#include<stdio.h>
#define Max_Terms 101
typedef struct
{
    float coeff;
    int exp;
}poly;
poly p[Max_Terms];
int avail=0,starta,finisha,startb,finishb,startc,finishc;
void Input()
{
    int i=1,e;
    float co;
    while(i)
    {
        scanf("%f%d",&co,&e);
        Attach(co,e);
        printf("Next element 1/0 :- \n");
        scanf("%d",&i);
    }
}
void Attach(float co,int ex)
{
    if(avail>=Max_Terms)
    {
        fprintf(stderr,"Too many terms \n");
        exit(1);
    }
    p[avail].coeff=co;
    p[avail].exp=ex;
    avail+=1;
}
void Print(int start,int finish)
{
    int i;
    for(i=start;i<finish;i++)
        printf("%fx^%d + ",p[i].coeff,p[i].exp);
    printf("%fx^%d \n",p[finish].coeff,p[finish].exp);
}
void Add(int sta,int fina,int stb,int finb)
{
    float c;
    int x,y;
    startc=avail;
    while((sta<=fina)&&(stb<=finb))
    {
        switch(Compare(p[sta].exp,p[stb].exp))
        {
            case 1:
                Attach(p[sta].coeff,p[sta].exp);
                sta++;
                break;
            case -1:
                Attach(p[stb].coeff,p[stb].exp);
                stb++;
                break;
            case 0:
                c=p[sta].coeff+p[stb].coeff;
                if(c)
                    Attach(c,p[sta].exp);
                sta++;
                stb++;
        }
        if(sta>fina)
        {
            x=stb;
            y=finb;
        }
        else if(stb>finb)
        {
            x=sta;
            y=fina;
        }
    }
    while(x<=y)
    {
        Attach(p[x].coeff,p[x].exp);
        x++;
    }
    finishc=avail-1;
}
int Compare(int a,int b)
{
    if(a>b)
        return 1;
    else if(a<b)
        return -1;
    return 0;
}
void main()
{
    int i;
    starta=0;
    printf("Enter first polynomial, coefficient and exponents of non-zero terms in descending order :- \n");
    Input();
    finisha=avail-1;
    startb=avail;
    printf("Enter second polynomial, coefficient and exponents of non-zero terms in descending order :- \n");
    Input();
    finishb=avail-1;
    Add(starta,finisha,startb,finishb);
    printf("First polynomial :- \n");
    Print(starta,finisha);
    printf("Second polynomial :- \n");
    Print(startb,finishb);
    printf("The resultant polynomial is :- \n");
    Print(startc,finishc);
}

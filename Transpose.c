#include<stdio.h>
typedef struct
{
    int row,column,value;
}term;
void transpose(term a[],term t[])
{
    int i,j,k;
    t[0].row=a[0].column;
    t[0].column=a[0].row;
    t[0].value=a[0].value;
    k=1;
    for(i=0;i<a[0].column;i++)
        for(j=1;j<a[0].value;j++)
            if(a[j].column==i)
            {
                t[k].column=a[k].row;
                t[k].row=a[k].column;
                t[k].value=a[k].value;
                k++;
            }
}
void displayMatrix(term a[])
{
    int i;
    for(i=1;i<=a[0].value;i++)
        printf("%d\t%d\t%d\n",a[i].row,a[i].column,a[i].value);
}
void main()
{
    term a[10],t[10];
    int i;
    printf("Enter number of rows & columns ");
    scanf("%d%d",&a[0].row,&a[0].column);
    printf("Enter the number of elements ");
    scanf("%d",&a[0].value);
    for(i=1;i<=a[0].value;i++)
    {
        printf("Enter %d row, column and element value ",i);
        scanf("%d%d%d",&a[i].row,&a[i].column,&a[i].value);
    }
    displayMatrix(a);
    transpose(a,t);
    displayMatrix(t);
}

#include<stdio.h>
int Search(int a[],int high,int low,int key)
{
    int mid=(low+high)/2;
    if(low<=high)
    {
        if(a[mid]==key)
            return 1;
        else if(a[mid]<key)
            return Search(a,high,mid+1,key);
        else if(a[mid]>key)
            return Search(a,mid-1,low,key);
    }
    else
        return 0;
    return 0;
}
void Display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    printf("\n");
}
void main()
{
    int n,a[100],i,k,j,temp;
    printf("Enter the size of the array ");
    scanf("%d",&n);
    printf("Enter array elements ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Input array is ");
    Display(a,n);
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("Sorted array is ");
    Display(a,n);
    prinf("Enter key ");
    scanf("%d",&k);
    if(Search(a,n-1,0,k)==1)
        printf("Key found\n");
    else
        printf("Key not found\n");
}

#include<stdio.h>
#include<stdlib.h>
#define MALLOC(x,size,type)(x=(type*)malloc(size*sizeof(type)))
typedef struct
{
    int n;
}element;
int front=0,rear=0,capacity;
element *queue;
void copy(element *start,element *end,element *newQueue)
{
    element *j;
    element *i;
    j=start;
    i=newQueue;
    for(;j<end;j++,i++)
        *i=*j;
}
void queueFull()
{
    element *newQueue;
    MALLOC(newQueue,capacity*2,element);
    int start=(front+1)%capacity;
    if(start<2)
        copy(queue+start,queue+start+capacity-1,newQueue);
    else
    {
        copy(queue+start,queue+capacity,newQueue);
        copy(queue,queue+rear+1,newQueue+capacity-start);
    }
    front=2*capacity-1;
    rear=capacity-2;
    capacity*=2;
    free(queue);
    queue=newQueue;
}
void addq(element item)
{
    int temp=rear;
    rear=(rear+1)%capacity;
    if(front==rear)
    {
        rear=temp;
        queueFull();
        rear=(rear+1)%capacity;
    }
    queue[rear]=item;
}
element deleteq()
{
    element item;
    if(front==rear)
    {
        item.n=-1;
        return item;
    }
    front=(front+1)%capacity;
    return queue[front];
}
void displayq()
{
    int i;
    if(front==rear)
    {
        printf("Queue empty\n");
        return;
    }
    for(i=(front+1)%capacity;i!=rear;i=(i+1)%capacity)
        printf("%d\t",queue[i].n);
    printf("%d",queue[i].n);
    printf("\n");
    printf("Front: %d Rear: %d\n",front,rear);
}
int main()
{
    int choice;
    element item;
    printf("Enter initial size ");
    scanf("%d",&capacity);
    MALLOC(queue,capacity,element);
    while(1)
    {
        printf(" 1.Add\n 2.Delete\n 3.Display\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter item to add ");
            scanf("%d",&item.n);
            addq(item);
            break;
        case 2:
            item=deleteq();
            if(item.n==-1)
                printf("Queue empty\n");
            else
                printf("Item deleted: %d\n",item.n);
            break;
        case 3:
            displayq();
            break;
        }
    }
}

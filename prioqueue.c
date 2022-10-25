//Program to implement priority queue
#include<stdio.h>

#define pl 7
#define size 3
int PQ[pl][size];
int front[pl]={-1,-1,-1,-1,-1,-1,-1};
int rear[pl]={-1,-1,-1,-1,-1,-1,-1};

void enqueue(int a,int lev)
{
    int p;
    if((rear[lev]+1)%size==front[lev])
        printf("The queue is full\n");
    else
    {
        rear[lev]=(rear[lev]+1)%size;
        p=rear[lev];
        PQ[lev][p]=a;
    }
    if(front[lev]==-1)
        front[lev]=front[lev]+1;
}

int dequeue()
{
    int temp,i=0,p;
    while(i<pl)
    {
        if(rear[i]!=-1);
            break;
        i++;
    }
    if(i==pl)
        return -1;
    else
    {
        if(front[i]==rear[i])
        {
            p=front[i];
            temp=PQ[i][p];
            front[i]=rear[i]=-1;
            return  temp;
        }
        else{
            p=front[i];
            temp=PQ[i][p];
            front[i]=(front[i]+1)%size;
            return temp;
        }
    }
}

void display()
{
    int p;
    printf("The current Priority queue is \n");
    for(int i=0;i<pl;i++)
    {
        printf("priority level %d: ",i);
        for(int j =front[i];(j%size)!=rear[i];j++)
        {
            printf("%d ",PQ[i][j%size]);
        }
        p=rear[i];
        printf("%d\n",PQ[i][p]);
    }
}

void main()
{
    int c,lev,el,x;
    char ch='Y';
    while(ch=='Y'||ch=='y')
    {
        printf("\tMENU\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\nEnter you choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                printf("Enter the priority level to be enqueued at : ");
                scanf("%d",&lev);
                if(lev>=pl)
                {
                    printf("Invalid priority level\n");
                    break;
                }
                else
                {
                    printf("Enter the element to be enqueued : ");
                    scanf("%d",&el);
                    enqueue(el,lev);
                }
                break;
            case 2:
                x=dequeue();
                if(x==-1)
                    printf("Queue is empty\n");
                else
                {
                    printf("Dequeue : %d\n",x);    
                }
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid Input\n");

        }
        printf("Do you want to continue (Y/N)? ");
        scanf(" %c",&ch);
    }

}

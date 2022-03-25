#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *NODE;

NODE insert_front(NODE);
NODE getNode();
void display(NODE);
void main()
{
    int choice;
    NODE head=NULL;
    while(1)
    {
        printf("\nPress\n 1 for inserting in front\n 2 for display\n 3 for exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: head=insert_front(head);
                    break;
            case 2: display(head);
                    break;
            case 3: exit(0);
                    break;
            default: printf("INVALID CHOICE\n");
        }
    }
}

NODE getNode()
{
    NODE NEWNODE;
    int ele;
    NEWNODE= malloc(sizeof(struct node));
    if(NEWNODE==NULL)
    {
        printf("Memory is not allocated");
    }
    printf("Enter the data part: \t");
    scanf("%d", &ele);
    NEWNODE->data=ele;
    NEWNODE->next=NULL;
    return NEWNODE;
}

NODE insert_front(NODE head)
{
    NODE NEWNODE=getNode();
    if(head==NULL)
    {
        head=NEWNODE;
        return head;
    }
    else
    {
        NEWNODE->next=head;
        head=NEWNODE;
        return head;
    }
}

void display(NODE head)
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    NODE temp=head;
    while(temp!=NULL)
    {
        printf("%d-->", temp->data);
        temp=temp->next;
    }
}

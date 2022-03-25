#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *NODE;

NODE insert_front(NODE);
NODE insert_end(NODE);
NODE getNode();
void display(NODE);
NODE delete_end(NODE);
NODE delete_front(NODE);
void main()
{
    int choice;
    NODE head=NULL;
    while(1)
    {
        printf("\nPress\n 1 for inserting in front\n 2 for inserting at end\n 3 to delete at front\n 4 to delete at end\n 5 for display\n 6 for exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: head=insert_front(head);
                    break;
            case 2: head=insert_end(head);
                    break;
            case 3: head=delete_front(head);
                    break;
            case 4: head=delete_end(head);
                    break;
            case 5: display(head);
                    break;
            case 6: exit(0);
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

NODE insert_end(NODE head)
{
    NODE Newnode=getNode();
    if(head==NULL)
    {
        head=Newnode;
        return head;
    }
    else
    {
        NODE temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=Newnode;

        return head;
    }

}

NODE delete_front(NODE head)
{
    if(head==NULL)
    {
        printf("List is empty!!can't delete node\n");
        return head;
    }

    NODE cur=head;
    head=head->next;
    printf("\nDeleted node data %d\n",cur->data);
    free(cur);

    return head;


}

NODE delete_end(NODE head)
{
    if(head==NULL)
    {
        printf("List is empty!!can't delete node\n");
        return head;
    }
    if(head->next==NULL)
    {
        printf("\nDeleted node data %d\n",head->data);
        free(head);
        head=NULL;
        return head;
    }

        NODE cur=head,prev=NULL;
        while(cur->next!=NULL)
        {
            prev=cur;
            cur=cur->next;
        }
        prev->next=NULL;

        printf("\nDeleted node data %d\n",cur->data);
        free(cur);

        return head;


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

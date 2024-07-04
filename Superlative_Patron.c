#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int code;
	int count;
	char name[20];
	char phno[10];
	struct node *next;
}*temp,*head,*newnode,*ptr,*top;
void insert(int code);
void display();
void increment(int code);
struct node* winner();
void delete_recent();
int main()
{
	head=NULL;
	top=NULL;
	int flag=0,s,code,ch,bill=0;
	while(1)
	{
		printf("\n\nEnter 1 to verify coustmer code or To create coustmer code:\nEnter 2 to declare the winner\nEnter 3 to delete recently created node\nEnter 4 to exit\nEnter 5 to display\nEnte your choice:");
		scanf("%d",&s);
		switch(s)
		{
			case 1:printf("Does coustemer already has a code if yes entr 1 else enter 0:");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:printf("enetr the code:");
				scanf("%d",&code);
				printf("Enter the bill amount:");
				scanf("%d",&bill);
				if(head==NULL)
                printf("Please creat a List\n");
                else if(bill>=200)
				increment(code);
				else
				printf("Bill amount must be greater then or equal to 200");
				break;
				case 0:flag++;
				printf("%d is the coustmer code\n",flag);
				insert(flag);
				break;
				default:printf("Wrong choice:(\n");
				break;
			}
			break;
			case 2:top=winner();
			if(head!=NULL&&top!=NULL)
			printf("coustmer with ID %d is the winner\nCongragulations %s :)",top->code,top->name);
			else
			printf("Please creat a List\n");
			break;
			case 3:delete_recent();
			flag--;
			break;
			case 4:exit(0);
			case 5:printf("\n------------------------------------\ncoustmer details\n");
			display();
			break;
			default:printf("Wrong choice:(");
		}
	}
}
void insert(int code)
{
    char name[20];
    char phno[10];
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->code=code;
	newnode->count=0;
	printf("Enter coustmer name:");
	scanf("%s",name);
	strcpy(newnode->name,name);
	printf("Enter coustmer phone number:");
	scanf("%s",phno);
	strcpy(newnode->phno,phno);
    newnode->next=NULL;
     if(head==NULL)
    {
        head=temp=newnode;
    }
    else
    {
    	temp=head;
    	while(temp->next!=NULL)
    	temp=temp->next;
        temp->next=newnode;
        temp=newnode;
    }
    printf("%d is Sucessfully inserted\n",code);
}
void display()
{
    temp=head;
    if(head==NULL)
    printf("Nothing to print please creat a List\n");
    else
    while(temp!=NULL)
    {
        printf("%d->%d\n",temp->code,temp->count);
        printf("Name:%s\nPhno:%s\n",temp->name,temp->phno);
        printf("-----------\n");
        temp=temp->next;
    }
 } 
void increment(int code)
{
	int count=0;
	temp=head;
	if(head==NULL)
    printf("Nothing to print please creat a List\n");
    else
	while(temp!=NULL)
	{
		if(temp->code==code)
		{
			temp->count++;
			count++;
			break;
		}
		temp=temp->next;
	}
	if(count>0)
	printf("Sucessfully incremented:)\n");
	else
	printf("Element not found or Not inserted:(\n");
}
struct node* winner()
{
	temp=head;
	if(head==NULL)
    printf("Please creat a List\n");
    else
    {
    int count=head->count;
    top=head;
	while(temp!=NULL)
	{
		if(count<temp->count)
		{
			count=temp->count;
			top=temp;
		}
		temp=temp->next;
	}
    }
	return top;
}
void delete_recent()
{
	temp=head;
	if(head==NULL)
    printf("Please creat a List\n");
    else{
    	if(temp->next==NULL){
    	free(temp);
    	head=NULL;
    	printf("Sucessfully deleted\n");
        }
    else{
	while(temp->next->next!=NULL)
	temp=temp->next;
	ptr=temp->next;
	temp->next=temp->next->next;
	free(ptr);
	printf("Sucessfully deleted\n");
    }
}
}


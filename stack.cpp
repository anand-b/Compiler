#include<stdio.h>
#include<stdlib.h>
int top=-1;
struct list
{
	struct node *link;
	int count;
}*lis;
struct node
{
    struct node *link;
    char *name;
    int *addr;
};
typedef struct list l;
typedef struct node n;

void push(l **s,list *li)
{
	s[++top]=li;	
}
l* pop(l **s)
{
	return s[top--];
}
// returns the index
int hashUtil(char *name)
{
    int addition=0;
    for(int i=0;name[i]!='\0';i++)
        addition+=(int)name[i];
    return addition%200;
}
n* createNode(char *name,int *addr)
{
	n *temp=(n*)malloc(sizeof(n));
	temp->link=NULL;
	temp->name=name;
	temp->addr=addr;
	return temp;
}
// 1 success 0 fail
int insert(l *list,char *name,int *addr)
{
    int index=hashUtil(name);
    list[index].count++;
    if(list[index].link==NULL)
    {
    	list[index].link=createNode(name,addr);
    }
    else
    {
        n *temp=list[index].link,*prev=list[index].link;
        while(temp!=NULL)
        {
        	prev=temp;
            temp=temp->link;
        }
        prev->link=createNode(name,addr);
    }
    return 1;
}
void remove(l *list,char *name)
{
    int index=hashUtil(name);
    n *temp,*prev;
    if(list[index].count==1)
    {
    	temp=list[index].link;
    	free(temp);    	
        list[index].link=NULL;
    }
    else
    {
    	if(list[index].link->name==name)
    	{
    		temp=list[index].link;
    		list[index].link=list[index].link->link;
    		free(temp);
    		
    	}
    	else
    	{
	        temp=list[index].link->link;
			prev=list[index].link;
	        while(temp!=NULL  && temp->name!=name)
	        {
	            prev=temp;
	            temp=temp->link;
	        }
	        prev->link=temp->link;
	        free(temp);
	    }
    }
    list[index].count--;
}
void printUtil(l *list,int index)
{
	n *temp=list[index].link;
	while(temp!=NULL)
	{
		printf("%s ",temp->name);
		temp=temp->link;
	}
	printf("\n");
}
void freeListUtil(n *node)
{
	if(node==NULL)
		return;
	else
	{
		freeListUtil(node->link);
	}
	n *temp=node;
	free(temp);	
}
void freeList(l *list)
{
	for(int i=0;i<200;i++)
	{
		freeListUtil(list[i].link);
		list[i].link=NULL;
	}
}
int main()
{
  lis=(l*)malloc(sizeof(l)*200);
  l *lis2=(l*)malloc(sizeof(l)*200);
  int a,b,c;
  char n1[6]="a",n2[6]="b",n3[6]="c",n4[5]="sfd";
  for(int i=0;i<200;i++)
  {
  	lis[i].link=NULL;
	lis[i].count=0;
  }
  insert(lis,n1,&a);
  insert(lis,n2,&b);
  insert(lis,n3,&c);
  insert(lis,n4,&a);
  printUtil(lis,97);
  freeList(lis);
  
}

%{
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>
#include<ctype.h>
#include "y.tab.h"
extern FILE *yyin;
extern int line;
//variables
int top=-1;
int result=1;
int startLoop,endLoop;

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

int if_stack[20];
int if_top=-1;
void if_push();
int if_pop();
int* getAddr(l *,char *);
int getVal(l *,char *);
void freeList(l *);
void freeListUtil(n *);
void printUtil(l *,int);
void insert(l *,char *);
void removeUtil(l *,char *);
n* createNode(char *,int *);
int hashUtil(char *);
%}
%union 
{
	int number;
	char *var_name;
}
%token INT NUMBER PLUS BMINUS MULTIPLY OP CP AND OR DO
%token COMMA DIVIDE MOD VAR FUNC_NAME PERIOD EQ
%token FOR THEN IF FI RETURN MAIN END BREAK CONTINUE
%token SRIGHT SLEFT BAND BOR BXOR BITCOMPLEMENT
%token LE GE L G NOT NE EE ELSE
%token DEC INC UMINUS OUT IN STRING LOOP TILL WITH

%left LE GE L G NOT NE EE
%left SRIGHT SLEFT AND OR
%left PLUS BMINUS MULTIPLY DIVIDE MOD 
%left BAND BOR BXOR

%type <number> loop

%type <number> expr
%type <number> statement
%type <number> term 
%type <number> factor
%type <number> shifts
%type <number> bitwise
%type <number> NUMBER
%type <number> logical
%type <number> compare
%type <number> pre
%type <number> post
%type <number> block
%type <number> init
%type <number> ifcond
%type <var_name> VAR
%type <var_name> STRING
%type <number> list
%type <number> initlist
%type <number> else_initlist
%type <number> else_init
%type <number> else_block
%%
st : MAIN statement					{printf("\n---------------------------------------------\nProgram terminated with return value %d\n",$2);exit(0);}
		;
statement :   END					{$$=0;}
			| declaration statement {}
			| init statement		{}
			| {if_push();} ifcond statement		{}
			| OUT STRING 
			{
				printf("%s\n",$2);
			}
			PERIOD statement {}
			| OUT logical PERIOD 
			{
				printf("%d\n",$2);
			} 
			statement  {}
			| IN VAR PERIOD
			{
				int *p=getAddr(lis,$2);
				int tmp;
				scanf("%d",&tmp);
				*p=tmp;
			}
			statement {}
			|{printf("%d\n",ftell(yyin));} loop statement {}
			| PERIOD statement {}
			;
declaration : INT list PERIOD
			{
			}
			;			
list 		: VAR COMMA list
			{
				insert(lis,$1);
			}
			| VAR EQ logical COMMA list
			{
				//printf("%s %d\n",$1,$3);
				insert(lis,$1);
				int *p;
				p=getAddr(lis,$1);
				*getAddr(lis,$1)=$3;
				//printf("list 1: %s\n",$1);
				int a=getVal(lis,$1);
				//printf("%d\n",a);
				$$=a;
				//printUtil(lis,hashUtil($1));
			}
			| VAR EQ logical
			{
				//printf("%s %d\n",$1,$3);
				insert(lis,$1);
				*getAddr(lis,$1)=$3;
				//printf("list 2: %s\n",$1);
				int a=getVal(lis,$1);
				//printf("%d\n",a);
			}
			| VAR
			{
				insert(lis,$1);
			}
			;
block 		: init block 	{$$=$1;}
			| ifcondition block  {}
			| loop block		{}
			| strprint1 block {}
			| varprint1 block  {}
			| input1 block {}
			| init			{}
			| varprint1		{}
			| strprint1		{}
			| input1		{}
			| ifcondition	{}
			| PERIOD block  {}
			| PERIOD		{}
			| loop
			;
ifcondition : {if_push();} ifcond	{}
input1		:  IN VAR PERIOD
			{
				if(result==1){
				int *p=getAddr(lis,$2);
				int tmp;
				scanf("%d",&tmp);
				*p=tmp;
				}
			}
			;
varprint1	: OUT logical PERIOD 
			{
				if(result==1)
					printf("%d\n",$2);
			}
			;
strprint1	: OUT STRING 
			{
				if(result==1)
					printf("%s\n",$2);
			}
			PERIOD {}	
			;
init 		: initlist PERIOD
			{
			}
			| initlist COMMA init {}
			;
initlist 	: VAR EQ logical
			{
				if(result==1)
				{
					//printf("Decl: %s\n",$1);
					int *a=getAddr(lis,$1);
					*a=$3;
					$$=*a;
					//printf("%d\n",*a);
				}
			}
			;
else_block 	: else_init else_block 	{$$=$1;}
			| ifcondition else_block  {}
			| loop block			{}
			| strprint0 else_block {}
			| varprint0	else_block  {}
			| input0 else_block {}
			| else_init			{}
			| varprint0			{}
			| strprint0			{}
			| input0			{}
			| ifcondition		{}
			| PERIOD else_block {}
			| PERIOD			{}
			| loop				{}
			;
varprint0   : OUT logical PERIOD 
			{
				if(result==0)
					printf("%d\n",$2);
			} 
			;
input0		: IN VAR PERIOD
			{
				if(result==0){
				int *p=getAddr(lis,$2);
				int tmp;
				scanf("%d",&tmp);
				*p=tmp;
				}
			}
			;
strprint0	:OUT STRING 
			{
				if(result==0)
					printf("%s\n",$2);
			}
			PERIOD {}
			;
else_init 	: else_initlist PERIOD
			{
			}
			;
else_initlist 	: VAR EQ logical
			{
				if(result==0)
				{
					//printf("Decl: %s\n",$1);
					int *a=getAddr(lis,$1);
					*a=$3;
					$$=*a;
					//printf("%d\n",*a);
				}
			}
			;

ifcond	    : IF OP logical CP THEN block FI
			 {
				if($3==1)
				{
					//$$=$7;
					//printf("IF statement\n");
				}
				result=if_pop();
			 }
			 |	IF OP logical CP THEN block ELSE else_block FI 
			 {
				//printf("condition: %d\n",$3);
				if($3==1)
				{
					//$$=$6;
					//printf("%d\n",$3);
					//printf("IF statement\n");
				}
				else
				{
					//$$=$9;
					//printf("ELSE statement\n");
				}
				result=if_pop();
			 }
			;
loop		: LOOP TILL logical DO block WITH logical PERIOD
				{
					printf("Loop\n");
					
				}
			;
logical		: logical AND compare {$$=$1&&$3;result=$$;}
			| logical OR compare  {$$=$1||$3;result=$$;}
			| compare			  {$$=$1;}
			;
compare		:compare GE bitwise 	
			 {
				if($1 >= $3)
					$$=1;
				else
					$$=0;
				result=$$;	
			 }
			| compare LE bitwise
			 {
				if($1 <= $3)
					$$=1;
				else
					$$=0;
				result=$$;
			 }
			| compare G bitwise
			 {
				if($1 > $3)
					$$=1;
				else
					$$=0;
				result=$$;
			 }
			| compare L bitwise
			{
				if($1 < $3)
					$$=1;
				else
					$$=0;
				result=$$;
			 }
			| compare NE bitwise 	
			{
				if($1 != $3)
					$$=1;
				else
					$$=0;
				result=$$;
			 }
			| compare EE bitwise 
			{
				if($1 == $3)
					$$=1;
				else
					$$=0;
				result=$$;
			 }
			| bitwise						{$$=$1;}
			;
bitwise 	: bitwise BAND shifts {$$=$1&$3;}
			| bitwise BOR shifts  {$$=$1|$3;}
			| bitwise BXOR shifts {$$=$1^$3;}
			| shifts			  {$$=$1;}
			;
shifts		: shifts SRIGHT expr {$$=$1>>$3;}
			| shifts SLEFT expr  {$$=$1<<$3;}
			| expr				 {$$=$1;}
			;
expr 		: expr PLUS term		{$$=$1+$3;}
			| expr BMINUS term		{$$=$1-$3;}
			| term					{$$=$1;} 
			;
term 		: pre MULTIPLY term	{$$=$1*$3;}
			| pre DIVIDE term	{$$=$1/$3;}
			| pre MOD term		{$$=$1%$3;}
			| pre				{$$=$1;}
			;			
pre			: INC pre				{$$=++$2;}
			| DEC pre				{$$=--$2;}
			| NOT pre				{$$=!$2;}
			| BITCOMPLEMENT pre		{$$=~$2;}
			| factor				{$$=$1;}
			;				
factor		: OP logical CP		{$$=$2;}
			| post				{$$=$1;}
			;
post		: post INC			{$$=$1++;}
			| post DEC			{$$=$1--;}
			| NUMBER			{$$=$1;}
			| VAR 				{
								//printf("%s\n",$1);
								int *p=getAddr(lis,$1);
								$$=*p;
								}
			;
%%
int yywrap()
{
	return 1;
}
int yyerror(char *err)
{
	printf("Error: ");
	printf("Program terminated with return value %d\n",err);
}
int hashUtil(char *name)
{
    int addition=0,i;
    for(i=0;name[i]!='\0';i++)
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
void insert(l *list,char *name)
{
	int *a=(int *) malloc(sizeof(int));
    int index=hashUtil(name);
	//printf("Inside insert\n");
    list[index].count++;
    if(list[index].link==NULL)
    {
		//printf("Inside insert link NLL\n");
    	list[index].link=createNode(name,a);
    }
    else
    {
        n *temp=list[index].link,*prev=list[index].link;
		//printf("Inside insert insde else\n");
        while(temp!=NULL && strcmp(temp->name,name))
        {
			//printf("%d\n",strcmp(temp->name,name));
			//printf("Inside insert while\n");
        	prev=temp;
            temp=temp->link;
        }
        if(!strcmp(temp->name,name))
        {
        	printf("Oops: Duplicate variable declaration!\n");
			exit(0);
        }
		else{
			//printf("Inside insert\n");
			prev->link=createNode(name,a);
		}
    }
	//printf("Inside insert end\n");
}
void removeUtil(l *list,char *name)
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
		printf("%d \n",*temp->addr);
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
	int i;
	for(i=0;i<200;i++)
	{
		freeListUtil(list[i].link);
		list[i].link=NULL;
	}
}
int* getAddr(l *list,char *name)
{
	//printf("%s\n",name);
	//printf("Inside getAddr\n");
	int index=hashUtil(name);
	n *temp=list[index].link;
	//printf("Inside getAddr\n");
	while(temp!=NULL && strcmp(temp->name,name) )
	{
		//printf("Inside getAddr while\n");
		temp=temp->link;
	}
	if(temp==NULL)
	{
		printf("Error: No such variable declared\n");
		exit(0);
	}
	else
	{
		//printf("Inside getAddr\n");
		return temp->addr;
	}
}
int getVal(l *list,char *name)
{
	int index=hashUtil(name);
	n *temp=list[index].link;
	while(temp->name!=name)
	{
		temp=temp->link;
	}
	return *(temp->addr);
}
void if_push()
{
	if_stack[++if_top]=result;	
}
int if_pop()
{
	return if_stack[if_top--];
}
int main(int argc,char *argv[])
{
	int i;
	int a,b,c;
	yyin=fopen(argv[1],"r");
	lis=(l*)malloc(sizeof(l)*200);
	l *lis2=(l*)malloc(sizeof(l)*200);
	for(i=0;i<200;i++)
	{
	lis[i].link=NULL;
	lis[i].count=0;
	}
	yyparse();	
	fclose(yyin);
	return 0;
}
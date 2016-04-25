
/*

STUDENT NAME->ANKIT PATEL
ASSIGNMENT:BINARY TREE DATA STRUCTURE
OBJECT    :THIS PROGRAM WILL PRINT OUT LIST OF NAMES BY USER DEFINED INPUT.
           THIS PROGRAM WILL TAKES 100 NAMES AS INPUT AND CREATE TREE DATA STRUCTURE
	       INORDER WAY RECURSIVELY.
       	   
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct treenode                     /*structure format to perform node in binary tree*/
{
	char name[30];  // array which store string 
	
	struct treenode *rightptr;  //right pointer variable to store address of another structure
    struct treenode *leftptr;	// left pointer variable to store address of another structure
};

typedef struct treenode tree;
typedef tree *treenodeptr;

void insert(treenodeptr *sptr,char *crt) //insert function: to insert node .
{
	int i;       // variable which store result of strcmp function.
	
	if(*sptr==NULL)      //if head is holding null
	{
		 *sptr=(struct treenode*)malloc(sizeof(struct treenode));// create new node
		if(*sptr!=NULL)     // if node is successfully created.
		{
			strcpy((*sptr)->name,crt);// transfer string in name array.
			(*sptr)->leftptr=NULL;  //set right and left pointer to NULL.
			(*sptr)->rightptr=NULL;
			
		}else
		{
			printf("memory not available\n");// if node is not created then print massage
		}
	}else
	{
		i=strcmp((*sptr)->name,crt);//compare strings to list in alphabetical order
		if(i<0||i==0)    //if input string is greater in order then string in existing node 
		{
			insert(&((*sptr)->rightptr),crt);//recursion which pass right side pointer and string.
		}else 
	 	{
			insert(&((*sptr)->leftptr),crt);// recursion which pass left side pointer and string.
		}
		
	}
	
}
void inorder(treenodeptr sptr)//function to print list of name inorder
{
	
	if(sptr!=NULL)//if head is not null.
	{
		inorder(sptr->leftptr);//recursion to access left side element first.
		
		printf("%s\n",sptr->name);//print list
		inorder(sptr->rightptr);//recursion to access right side element first.
	}
}

int main()
{
	
		treenodeptr startptr = NULL;// create head node
		char a[30]; // array for user input name
	
       for(int i=0;i<100;i++)
		{
		 printf("enter  name  %d:\t",i);
		 fgets(a,30,stdin);		 //take user input
        
               insert(&startptr,a);// call the insert function
			
		}
		printf("list ended\n");// call print function to display list
		inorder(startptr);//call of function to print list inorder
		
		return 0;
	
}
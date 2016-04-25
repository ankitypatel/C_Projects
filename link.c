
/*
NAME  :ANKIT PATEL
OBJECT:THIS PROGRAM WILL PRINT OUT LIST OF NAMES BY USER DEFINED INPUT.
       HERE, LINKED LIST DATA STRUCTURE TECHNIQUE IS USED TO PRINT LIST OF NAMES ACCORDING TO IT'S GIVEN POSITION.
       	   
*/






#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct listnode                     /*structure format to perform node in linklist*/
{
	char name[30];
	int data;
	struct listnode *nextptr;       //pointer variable to store address of another structure
};

typedef struct listnode list;
typedef list *listnodeptr;

void insert(listnodeptr *sptr, int value,char *crt) //insert function: to insert node according to it,s position value in linked list.
{
	listnodeptr newptr;
	listnodeptr previousptr;
	listnodeptr currentptr;
	if(*sptr!=NULL)            //update the position of every nodes.
	{
		listnodeptr temp;
		int length=0;
		temp=*sptr;
		while(temp!=NULL)      //count position of every node
		{
			length++;
			temp->data=length; // store the position
			temp=temp->nextptr;
		}
		if(value>(length+1))           //if position larger then total node then it will print invalid position and enter name at last.
		{
			printf("invalid position\n");
		}
		
	}

	newptr =(struct listnode*) malloc(sizeof(struct listnode));//dynamic memory allocation to make new node.
	if (newptr != NULL)                                       //check if new node is available or not.
	{
		strcpy(newptr->name, crt );                            //store user input data into new node data member.
		
		newptr->data=value;
        newptr->nextptr = NULL;

		previousptr = NULL;
		currentptr = *sptr;
			
		while (currentptr != NULL&&value>currentptr->data)//traversing link list to store name according to it,s position number.
        {
			previousptr = currentptr;
			currentptr = currentptr->nextptr;
			
		}
		if (previousptr == NULL) //create a first node 
		{
			newptr->nextptr = *sptr;
			*sptr = newptr;
		}
		else                                     //otherwise insert node according to position value
		{
			previousptr->nextptr = newptr;
			newptr->nextptr = currentptr;
		}
		
	}
	else
	{
		printf("%s not inserted memory full");// if newnode not generated then print this error message.
	}
	
}


void append(listnodeptr *sptr,char* c)// if "," is not in input then insert node at end.
{
	listnodeptr newptr;
	listnodeptr currentptr;
	listnodeptr temp;
	newptr =(struct listnode*) malloc(sizeof(struct listnode));// allocate memory for new node
	strcpy(newptr->name,c);
	if(newptr!=NULL)  // traverse the list untill null is detected
	{
		temp=*sptr;
		while(temp->nextptr!=NULL)
		{temp=temp->nextptr;}
	
	temp->nextptr=newptr;// insert list at the end.
	currentptr=newptr;
	}
	else{printf("sorry new node can not genrated\n");}
}




void printlist(listnodeptr currentptr)//function to print linklist.
{
	if (currentptr==NULL)        //check if any node available or not
	{
		printf("list is empty");

	}else                         //  print list.
	{
		printf("the list is:\n");
		while (currentptr != NULL)
		{
			printf("%s\n", currentptr->name);
			
			currentptr = currentptr->nextptr;
		}
		printf("null\n\n");
	}
}




int main()
{
	
		listnodeptr startptr = NULL;// create head node
		char a[30],s[2]=","; // array for user input name
		char *token; // token to detect number from string
		int item; //to get position value.
		
		while(1)
		{
		 printf("enter name:");
		 fgets(a,30,stdin);		 //take user input
        
                if(a[0]=='$')  // if input '$' then end list.
		        {
			     goto sd;
		        }		 
	
		   if(strstr(a,s)!=NULL)// detect ","
		   {
			   
		     token=strtok(a,s);// seperate string to detect number from input string
		     strcpy(a,token);
		     token=strtok(NULL,s);
		     item=atoi(token);// convert position value in int type
		     insert(&startptr, item,a);// call the insert function
			
		   }
		   else
		   {
			  append(&startptr,a);// if "," is not in input string then add new node at the end.
		   }
		 
		}
		sd:printf("list ended\n");// call print function to display list
		printlist(startptr);
		
		return 0;
	
}
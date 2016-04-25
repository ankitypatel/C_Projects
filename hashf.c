/*
STUDENT NAME->ANKIT PATEL
STUDENT ID->7158918
OBJECT:THIS PROGRAM WILL STORE LIST OF NAMES IN THEIR HASH VALUE AND TAKE USER INPUT.
       IF,USER INPUT IS IN THE LIST OF NAMES THAN IT SHOWS NAME IS MATCHED OTHERWISE NOT MATCHED.
       	   
*/


#include <stdio.h>

struct hashrec                    //STRUCTURE WHICH CONTAIN UNSIGNED LONG INTEGER TO STROE HASH VALUES OF NAMES.
{
	unsigned long key; 
};

unsigned long hash(char *str)                     //HASH FUNCTION WHICH GIVES HASH VALUE OF NAMES,ARGUMENT=CHARATER ARRAY,RETURNS UNSIGNED LONG VALUE
{
    unsigned long hash = 0;                        //UNSIGNED LONG VARIABLE
    int c;
	
    while (c = *str++)                             //CONVERT EVERY CHARACTER OF NAMES IN INTIGER UNTILL NULL
    hash = c + (hash << 6) + (hash << 16) - hash; //CONVERT HASH VALUE.

    return hash;                                  // RETURN HASH VALUE
}


int locate(unsigned long num,struct hashrec hasharray[]) // LOCATE FUNCTION
{
	
	for(int i=0;i<=12;i++)                               //FOR LOOP TO CET THROUGH STRUCTURE ARRAY.
	{
		
		if(hasharray[i].key==num)                         // CHECK IF VALUE IS PRESENT OR NOT IN STRUCTURE ARRAY
		{
			return 1;                                        //IF TRUE RETURN 1.
		}
	}
	return 0;                                               // OTHERWISE RETURN 0.
}


int main()
{
	unsigned long p,x;
	char a[30];               //ARRAY WHICH STORE USER INPUT NAME.
	char* string[12]={{"ankit"},{"yash"},{"aatish"},{"ravneet"},{"samson"},{"obiora"},{"ramya"},{"priya"},{"harpreet"},{"jestin"},{"arun"},{"ajit"}};//ARRAY OF NAME

	struct hashrec hasharray[12];// STRUCTURE ARRAY TO STORE HASH VALUES
	for(int i=0;i<=12;i++)    // GO THROUGH EVERY NAME
	{
	  p=hash(string[i]);// GET HASH VALUE FROM HASH FUNCTION
	  hasharray[i].key=p;//STORE HASH VALUE IN STRUCTURE ARRAY
	}
	while(1)//TO RUN LOOP FOREVER
	{
	  printf("enter name:\n");//TAKE USER INPUT
	  scanf("%s",a);
	       
	  x=hash(a);// HASH VALUE OF USER INPUT
	       
      if(locate(x,hasharray)) // CALL LOCATE FUNCTION AND CHECK IT RETURNS 1 OR 0
	  {	
         printf("Matched!!\n\n");// IF RETURN 1 THEN PRINT "MATCHED"
	  }
	  else
	  {
	     printf("Not Matched!!\n\n");	//OTHERWISE PRINT "NOT MATCHED"
	  }
	}
	
	
		 
}
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void append();
void addatbegin();
void addatanyloc();  
int length();
void display();
void deletenode();
							
	struct node
		{
			int data;
			struct node *link;
		};
	struct node *root =  NULL;
	int len;
		int main()
		{
			int ch;
			while (1)
				{
					printf("\n all operator in single link list");
					printf("\n 1 appenend  \\ create a node only");
					printf("\n 2 add at beign");
					printf("\n 3 add at any loc ");
				    printf("\n 4.length of list");
					printf("\n 5. Display");
					printf("\n 6. Delete a node");
					printf("\n 7 quit");
					printf("\n \n enter your choice");
							
							scanf("%d",&ch);
							switch (ch)
							{
								case 1 : append();
								               break;
								case 2 : addatbegin();
								         	  break;
								case 3 : addatanyloc();
								               break;
								case 4 : len =length();
											   printf("\n length = %d",len);
							               	break;
								case 5 : display();
							               	break;
								case 6 : deletenode();
								               break;
								case 7 : exit(1);
						               		break;
								default : printf("\n invalid choices");
							}
							
		}
		return 0;
}

	 
	  	void append()
	 		{
				struct node *temp;
				temp = (struct node *)malloc(sizeof(struct node));
				printf("\n enter the node");
	        	scanf("%d",&temp->data);
        		temp->link = NULL;
			 		if (root == NULL)
	  				  {
							root = temp;
						}
					else
						{
							struct node *p;
							p=root;
								while (p->link != NULL)
									{
										p = p->link;
									}
							p->link = temp;
						}
      	}



		void addatbegin()
		{
			struct node *temp;
			temp = (struct node *)malloc(sizeof(struct node));
			printf("\n enter the node");
			scanf("%d",&temp->data);
			temp->link = NULL;
					if (root == NULL)
				 	  {
							root = temp;
						}
	   			else
						{
							temp->link=root;
							root=temp;
						}
		}
			
		void addatanyloc()
		  {
		  	int loc;
		  	int  i=1;
		  	int len;
		  	struct node *temp;
		  	struct node *p;
		  		printf("\n enter location");
		  		scanf("%d",&loc);
		  			len = length();
		  				if (loc > len)
		  				{
		  					printf("\n enter valid location");
		  					printf("\n length are having %d",len);
		  				}
		  				else
		  				{
		  					p=root;
		  						while (i < loc) 
		  						{
		  							p = p->link;
		  							i++;
		  						}
		  							temp = (struct node *)malloc(sizeof(struct node));
		  								printf("\n enter node");
		  								scanf("%d",&temp->data);
		  								temp->link =NULL;
		  								temp->link = p->link;
		  								p->link=temp;
		  					}
		  	
		   	}
		
		
		
		
			int length( struct node *root)
				{
					struct node *temp;
					temp = root;
					int count =0;
						while (temp != NULL)
							{
								count++;
								temp= temp->link;
							}
					return count;
			}
			
			
		void display()
		{
				struct node *temp;
				temp = root;
					if (temp == NULL)
						{
							printf("\n no element");
						}
					else
				  	{
				      	while (temp != NULL)
								{
										printf("%d\n",temp->data);
								}
							printf("\n\n");
												
					}
		}
						
		void deletenode()//delete all pogestion of node begin/middle/last
		{
			struct node *temp;
			int loc,len=0;
			printf("\n enter location data");
			scanf("%d",&loc);
			len = length();
				if (loc > len)//also called len
				{
		     		printf("Invalid location");	
				}
				else if(loc == 1)
				{
					temp = root;
					root = temp->link;
					temp->link= NULL;
					free(temp);
				}
				else
				{
					struct node *p = root;
					struct node *q;
					int i=1;
						while (i < loc-1)
						{
							p =p->link;
							i++;
						}
						q = p->link;
						p->link = q->link;
						q->link = NULL;
						free(q);
					}
			}
								
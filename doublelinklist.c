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
			struct node *left;
			struct node *right;
		};
	struct node *root =  NULL;
	int len;
		int main()
		{
			int ch;
			while (1)
				{
					printf("\n all operator in single link list");
					printf("\n 1. appenend  \\ create a node only");
					printf("\n 2. add at beign");
					printf("\n 3. add at any loc ");
				    printf("\n 4.length of list");
					printf("\n 5. Display");
					printf("\n 6. Delete a node");
					printf("\n 7. quit");
					printf("\n \n enter your choice  ");
							
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
											   printf("\n length = %d \n  ",len);
											   
							               	break;
								case 5 : display();
							               	break;
								case 6 : deletenode();
								               break;
						
								default : printf("\n invalid choices\n");
							}
							
		}
		return 0;
}

	 
	  	void append()
	 		{
				struct node *temp;
				temp = (struct node *)malloc(sizeof(struct node));
				printf("\n enter the node \n");
	        	scanf("%d",&temp->data);
        		temp->left = NULL;
	    		temp->right = NULL;
		 		if (root == NULL)
	  				  {
							root = temp;
						}
					else
						{
							struct node *p;
							p=root;
								while (p->right != NULL)
									{
										p = p->right;
									}
							p->right = temp;
			                temp -> left = p;
					}
      	}



		void addatbegin()
		{
			struct node *temp;
			temp = (struct node *)malloc(sizeof(struct node));
			printf("\n enter the node\n ");
			scanf("%d",&temp->data);
			temp->left = NULL;
			temp->right = NULL;
						if (root == NULL)
				 	  {
							root = temp;
						}
	   			else
						{
							temp -> right=root;
							root -> left=temp;
							root = temp;
						}
		}
			
		void addatanyloc()
		  {
		  	int loc;
		  	int  i=1;
		  	int len;
		  	struct node *temp;
		  	struct node *p;
		  		printf("\n enter location \n");
		  		scanf("%d",&loc);
		  			len = length();
		  				if (loc > len)
		  				{
		  					printf("\n enter valid location\n");
		  					printf("\n length are having %d\n",len);
		  				}
		  				else
		  				{
		  					p=root;
		  						while (i < loc) 
		  						{
		  							p = p->right;
		  							i++;
		  						}
		  							temp = (struct node *)malloc(sizeof(struct node));
		  								printf("\n enter node\n");
		  								scanf("%d",&temp->data);
		  								temp -> left =NULL;
		  								temp -> right =NULL;
		  								
		  						         temp -> right = p -> right;
		  						         p -> right -> left =  temp;
		  						         temp -> left = p;
		  						         p -> right = temp;
		  					}
		  	
		   	}
		
		
		
		
			int length()
				{
					struct node *temp;
					temp = root;
					int count =0;
						while (temp != NULL)
							{
								count++;
								temp= temp->right;
							}
					return count;
			}
			
			
		void display()
		{
				struct node *temp;
				temp = root;
					if (temp == NULL)
						{
							printf("\n no element\n");
						}
					else
				  	{
				      	while (temp != NULL)
								{
										printf("%d\n",temp->data);
										temp = temp -> right;
								}
							printf("\n\n");
												
					}
		}
						
		void deletenode()//delete all pogestion of node begin/middle/last
		{
			struct node *temp;
			int loc;
			printf("\n enter location data\n");
			scanf("%d",&loc);
				if (loc > length())//also called len
				{
		     		printf("\nInvalid location \n");	
				}
				else if(loc == 1)
				{
					temp = root;
					root = temp->right;
					temp->right->left= NULL;
					free(temp);
				}
				else
				{
					struct node *p = root;
					struct node *q;
					int i=1;
						while (i < loc-1)
						{
							p =p->right;
							i++;
						}
						q = p->right;
						p -> right = q -> right;
					   q -> right -> left = p;
					   q -> right = NULL;
					   q -> left  = NULL;
					   free(q);
					
					}
			}
								

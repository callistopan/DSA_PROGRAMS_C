#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>



struct node
{
    int data; 
    struct node *right;
    struct node *left; 
};
struct node *root=NULL;
struct node* new_node(int x)
{
    struct node *p;
    p =(struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right= NULL;

    return p;
}


struct link
{
	struct node *item;
	struct link *next;
};



struct link *head=NULL;
struct link* createNode() 
{
 struct link *temp=(struct link*)malloc(sizeof(struct link));
 if(temp == NULL)
    { 
        exit(0); 
    }
 temp->next = NULL;
 return temp;
}
int  stack_empty(struct link *head)
{
    if(head==NULL)
    { 
        return 0;

    }
     
   else
   {
    return 1;
   }
      
}



struct link* push(struct link *head, struct node *value) 
{
 struct link *temp,*p;
 temp = createNode();
 temp->item = value; 
 if(head == NULL) { head = temp; }
 else {
 p = head;
 while(p->next != NULL)
 p = p->next;
 p->next = temp;
 }
 return head;
 }
 
 
 
struct link* pop(struct link *head)
{ 
    if(head == NULL) 
    {
        
        return NULL;
    } 
    struct link *cursor = head;
    struct link *prev= NULL;
 
 while(cursor->next != NULL) {
        prev = cursor;
        cursor = cursor->next; }

    if(prev != NULL) 
    prev ->next = NULL;

    if(cursor == head)
        head = NULL;
        
    return cursor;
}


void removespace(char str[])
{
	int i = 0, j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
          str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}
int i=0,num=0;

struct node* Make(struct node *root,char str[]) {

	if (str[i] == '(') 
	        i++;
	if (str[i] == ')') 
	    return NULL;
	int result = 0;
	
	
	while ((str[i] != '(') && (str[i]!=')')) {
		result = result * 10 + (str[i] - '0');
		i++;
	}
	root = new_node(result);
	head=push(head,root);
	num++;
	
	if (str[i] == ')') {
		i++;
		return root;
	}
	root->left = Make(root->left,str);
	if (str[i] == ')') i++;
	root->right = Make(root->right,str);
	if (str[i] == ')') i++;
	return root;
}

static struct node *prev = NULL; 
int is_bst(struct node* N)
{
    if (N)
    {
        if (!is_bst(N->left)) 
            return 0;
        if (prev != NULL && N->data <= prev->data)
            return 0;
        prev = N;
        return is_bst(N->right);
    }
    return 1;
}


int calculateSum(struct node *temp){  
    int sum, sumLeft, sumRight;  
    sum = sumRight = sumLeft = 0;  
      
    
    if(root == NULL) {  
        printf("Tree is empty\n");  
        return 0;  
    }  
    else {  
    
        if(temp->left != NULL)  
            sumLeft = calculateSum(temp->left);  
          
        
        if(temp->right != NULL)  
              sumRight = calculateSum(temp->right);  
          
        
        sum = temp->data + sumLeft + sumRight;   
        return sum;  
  }
}

void  check(int *k,int *count)
{
    int sum;
    *count=0;
    struct link *current;
    current=createNode();
int t=num;
    while(t--)
    {
      current=  pop(head);
      
      if(is_bst(current->item))
      {
          sum=calculateSum(current->item);
          
          if(sum==*k)
          {
              (*count)++;
          }
          sum=0;
          prev=NULL;
      }
        
          
          
      
      
    }

    
}

int main()
{
int k,count;
      
    char str[10000];
    scanf("%[^\n]*s",str);
    scanf("%d",&k);
   
    removespace(str);
    root=Make(root,str);

    check(&k,&count);
    if(count==0)
    {
        printf("-1\n");
        return 0;
    }
    
    printf("%d",count);
    
}













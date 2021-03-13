#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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
int i=0;
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


void Ksmallest(struct node *root,int a[],int *z)
{
    if(root!=NULL) 
    {
        Ksmallest(root->left,a,z); 
        a[*z]=root->data;
      (*z)++;
        Ksmallest(root->right,a,z);
    }
}
int main()
    {
        int z=0;
         int k, a[50000009];
    char str[50000009];
    scanf("%[^\n]*s",str);
    scanf("%d",&k);
 
   
    removespace(str);
    root=Make(root,str);
    Ksmallest(root,a,&z);
    printf("%d",a[k-1]);
    }
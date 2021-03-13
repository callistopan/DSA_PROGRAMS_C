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



int Leveltree(struct node *root,struct node *Node, int level) 
{ 
    
    if (root == NULL) 
        return 0; 
    if (root == Node) 
        return level; 
  

    int downlevel = Leveltree(root->left, Node, level+1); 
    if (downlevel != 0) 
        return downlevel; 
  
    
    return Leveltree(root->right, Node, level+1); 
} 
 int flag=0;
 void inorder(struct node *root)
{
    if(root!=NULL) 
    {
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right);
    }
}

void printLevel(struct node* root, struct node *Node, int level) 
{ 

    if (root == NULL || level < 2) 
        return; 
  

    if (level == 2) 
    { 
        if (root->left == Node || root->right == Node) 
            return; 
        if (root->left) 
           {printf("%d ", root->left->data);
           flag++;
           }
        if (root->right) 
           printf("%d ", root->right->data); 
    } 
  
 
    else if (level > 2) 
    { 
        printLevel(root->left, Node, level-1); 
        printLevel(root->right, Node, level-1); 
    } 
} 
  

void Cousins(struct node *root, struct node *Node) 
{ 
    
    int level = Leveltree(root, Node, 1); 
  
     
    printLevel(root, Node, level); 
}

struct node* search(struct node *temp, int value){  

    
        
        if(temp==NULL||temp->data == value){  
        
             return temp;  
        }  
    
        
     struct node *res1=  search(temp->left, value);  
        if(res1)
        {
            return res1;
        }
        
      struct node *res2=search(temp->right, value);  
        return res2;
        
    

}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
        
    }
}

int main()
{
    
    int k;
    char str[1000];
    scanf("%[^\n]*s",str);
    scanf("%d",&k);
   
    removespace(str);
    root=Make(root,str);
    
struct node* current=search (root,k);
Cousins(root,current);
if(flag==0)
{
    printf("-1\n");
}



    
}
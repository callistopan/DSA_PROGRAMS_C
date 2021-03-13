#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data; 
    struct node *right;
    struct node *left; 
};
 struct node *root=NULL;
struct node* search(struct node *root, int x)
{
    if(root==NULL || root->data==x) 
    {
        
        return root;
    }

    else if(x>root->data) 
        return search(root->right, x);
    else 
        return search(root->left,x);
}



struct node* new_node(int x)
{
    struct node *p;
    p =(struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right= NULL;

    return p;
}

struct node* find_minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left != NULL) 
        return find_minimum(root->left); 
    return root;
}

struct node* insert(struct node *root, int x)
{
    
    if(root==NULL)
        return new_node(x);
    else if(x>root->data) 
        root->right = insert(root->right, x);
    else 
        root->left= insert(root->left,x);
    
    return root;
}


struct node* delete1(struct node *root, int x)
{
    
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right = delete1(root->right, x);
    else if(x<root->data)
        root->left = delete1(root->left, x);
    else
    {
        
        if(root->left==NULL && root->right==NULL)
        {
            
            free(root);
            return NULL;
        }

        
        else if(root->left==NULL || root->right==NULL)
        {
            struct node *temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
        
            free(root);
            return temp;
        }

        
        else
        {
            struct node *temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = delete1(root->right, temp->data);
            
        }
    }
    
    
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL) 
    {
        inorder(root->left); 
        printf("%d ", root->data); 
        inorder(root->right);
    }
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
void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}



int getLevelUtil(struct node *root, 
                 int data, int level)
{
    if (root== NULL)
        return 0;
 
    if (root->data == data)
        return level;
 
    int downlevel = getLevelUtil(root->left, 
                                 data, level+1);
    if (downlevel != 0)
        return downlevel;
 
    downlevel = getLevelUtil(root->right, 
                             data, level+1);
    return downlevel;
}
 

int level(struct node *root, int data)
{
    return getLevelUtil(root,data,1);
}




int minvalue(struct node* root) { 
  struct node* current = root; 
  
  
  while (current->left != NULL) { 
    current = current->left; 
  } 
  return(current->data); 
} 




int maxvalue(struct node* root) { 
  struct node* current = root; 
  
 
  while (current->right!= NULL) { 
    current = current->right; 
  } 
  return(current->data); 
} 







struct node* findMaximum(struct node *root){
    if(!root)
        return NULL;
  
    while(root->right) root = root->right;
    return root;
}




int  Predecessor(struct node *root, int k){
  
struct node *predecessor   = NULL;
struct node *current       = root;
     
    if(!root)
        return -1;
  
    while(current && current->data != k){
        
        if(current->data>k){
            current= current->left;
        }
        
        else{
            predecessor = current;
            current = current->right;
             }
         }
    
    if(current && current->left){
        predecessor = findMaximum(current->left);
    }
    return predecessor->data;

}
struct node* findMinimum(struct node *root){
    if(!root)
        return NULL;
   
    while(root->left) root = root->left;
   
    return root;
}



int  Successor(struct node *root, int k){
  
struct node  *successor = NULL;
    struct node *current  = root;
    if(!root)
        return -1;
  
    while(current->data!= k){
        
         
        if(current->data > k){
            successor = current;
            current= current->left;
        }
        
        else
            current = current->right;
    }

    if(current && current->right){
        successor = findMinimum(current->right);
    }
  
    return successor->data;
}


int main(void)
{

   
    char x;
    int k,res;
    
    do
    {
        scanf("%c",&x);
        if (x=='a')
        {
            
            scanf(" %d",&k);
           root= insert(root,k);
            
        }
        if(x=='d')
        {
            
            scanf(" %d",&k);
            if(!search(root,k))
                printf("-1\n");
                else
                {
            
                printf("%d\n",k);
               root=delete1(root,k);
                }
        }
        if(x=='s')
        {
            
            scanf(" %d",&k);
            if(search(root,k))
                printf("1\n");
                else
                printf("-1\n");
            
        }
        if(x=='l')
        {
            scanf(" %d",&k);
              if(!search(root,k))
                printf("-1\n");
                else
                {
            
                    
                    res=level(root,k);
                    printf("%d\n",res);
            
                }
        }
        if(x=='m')
        {
            res=minvalue(root);
            printf("%d\n",res);
            
        }
        if(x=='x')
        {
            res=maxvalue(root);
            printf("%d\n",res);
        }
        
        if(x=='r')
        {
            scanf("%d",&k);
             if(!search(root,k))
                printf("-1\n");
                else
                {
            
                    
                    res=Predecessor(root,k);
                    printf("%d\n",res);
            
                }
            
        }
          if(x=='u')
        {
            scanf("%d",&k);
             if(!search(root,k))
                printf("-1\n");
                else
                {
            
                    
                    res=Successor(root,k);
                    printf("%d\n",res);
            
                }
            
        }
            
        
        if(x=='i')
        {
            inorder(root);
            printf("\n");
        }
        if(x=='p')
        {
            preorder(root);
            printf("\n");
        }
        if(x=='t')
        {
            postorder(root);
            printf("\n");
        }
    }while(x!='e');
    
}
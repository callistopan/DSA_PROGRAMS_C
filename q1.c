
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


struct Node {
    int data;
    struct	Node* left, * right;
};
struct link {
    struct Node* item;
    struct link* next;
};

struct Node* root = NULL;
struct link* head = NULL;

struct Node* newNode(int data)
{
    struct	Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

struct link* creatlink(struct Node* data)
{
    struct link* Link = (struct link*)malloc(sizeof(struct link));
    Link->item = data;
    Link->next = NULL;
    return Link;
}

int queue_empty(struct link* head)
{
    if (head == NULL)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

struct link* enqueue(struct link* head, struct Node* value)
{
    struct link* temp, * p;
    temp = creatlink(value);

    if (head == NULL) { head = temp; }
    else {
        p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = temp;
    }
    temp->next = NULL;
    return head;
}

struct link* dequeue(struct link* head)
{
    struct link* todelete;
    if (head == NULL)
    {

        return NULL;
    }
    else
    {
        todelete = head;
        head = head->next;

    }
    return head;
}

struct Node* InsertNode(struct Node* root, int data)
{

    if (root == NULL) {
        root = newNode(data);
        return root;
    }

    head = enqueue(head, root);
    

    while (queue_empty(head) != 1) {
        struct  link* temp = head;
        head = dequeue(head);
        if (temp->item)
        {
            if (temp->item->left != NULL)
                head = enqueue(head, temp->item->left);
            else {
                temp->item->left = newNode(data);
                return root;
            }

            if (temp->item->right != NULL)
                head = enqueue(head, temp->item->right);
            else {
                temp->item->right = newNode(data);
                return root;
            }
        }
    }
}

void String(struct Node* root, char str[])
{

    if (root == NULL)
    {
          
        
        return;
        
    }
        
    char res[50000009];
    //sprintf function convert number in data to a string 
    sprintf(res, "%d", root->data);

    strcat(str, res);
    strcat(str," ");

//if leaf node occurs then return by printing this
    if (!root->left && !root->right)
    {
        strcat(str,"( ) ( ) ");
    
        
        return;
        
    }
        

    strcat(str, "( ");
    String(root->left, str);
    strcat(str, ") ");


        strcat(str, "( ");
        String(root->right, str);
        strcat(str, ") ");
    
}
void print(char str[])
{
    puts(str);
    
}


int main()
{
    int data;
    char x;
    

    do {
        scanf("%c", &x);
        if (x == 'i')
        {
            scanf(" %d", &data);
            root = InsertNode(root, data);
            //insert node in level order fasion
             

        }
        if (x == 'p')
        {
            char  str[50000009] = "";
            strcat(str,"( ");
             String(root, str);
             strcat(str,")");
           
            print(str);
            
            

        }
    } while (x != 'e');

}

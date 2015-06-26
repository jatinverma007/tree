#include<stdio.h>
#include<stdlib.h>
struct Node
{

    int value;
    struct  node *left;
    struct  node *right;


};
void insert(int);
int search(int);
typedef struct Node tree;
tree *root =NULL;

main()
{

    int d,ch,a,b,e;
    while(1)
    {

        printf("\nuser choice\n");
        printf("\n1.insertion\n");
        printf("\n2.searching\n");
        printf("\n3.finding height\n");
        printf("\n4.exit");
        scanf("%d",&ch);
        switch(ch)

        {
        case 1:

            printf("\nenter data to be inserted");
            scanf("%d",&d);
            insert(d);
            break;
        case 2:
            printf("\nenter a number you want to search");
            scanf("%d",&a);
            b=search(a);
            if(b)
            {
                printf("\nelement found");

            }
            else
            {
                printf("\nelement not found");
            }
            break;
        case 3:
            e=height(root);
            printf("\nheight of tree=%d",e);
            break;
        case 4:
            printf("\nexitiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiinnnnnnnnnnnnnn\n");
            return 0;
        }

    }
}
void insert(int num)
{
    tree *temp=root , *prev=root;
    if(root == NULL)
    {

        root = (tree *)malloc(sizeof(tree));
        root->value = num;
        root->left = NULL;
        root->right=NULL;
    }
    else
    {
        while(temp !=NULL)
        {

            if(num > temp->value)
            {
                prev= temp;
                temp=temp->right;
            }
            else
            {
                prev = temp;
                temp = temp->left;
            }
        }
        temp = (tree *)malloc(sizeof(tree));
        temp->value=num;
        temp->left=NULL;
        temp->right=NULL;
        if(num> prev->value)
        {
            prev->right=temp;
        }
        else
        {
            prev->left=temp;
        }
    }
}
int search(int key)
{
    while(root!=NULL)
    {
        if(key>root->value)
        {
            root=root->right;
        }
        else if(key<root->value)
        {
            root=root->left;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
int height( tree *root)
{
    int hl,hr,h;
    if (root==NULL)
    {
        return -1;
    }
    if(root->left != NULL || root->right != NULL)
    {
        hl = height( root->left);
        hr = height( root->right);
        h = 1 + maximum(hl,hr);
        return h;
    }
    else
    {
        return 0;
    }
}
int maximum(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}



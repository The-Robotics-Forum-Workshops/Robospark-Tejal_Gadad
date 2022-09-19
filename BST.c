#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *left;
    struct node *right;
};

struct node* newNode(int ele){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->val = ele;
    temp->left = temp->right = NULL;
    return temp;
}

int search(struct node* root, int value){
    while (root != NULL){
        if (value > root->val)
            root = root->right;
        else if (value < root->val)
            root = root->left;
        else
            return 1;
    }
    return 0;
}

int main(){
    struct node* root = newNode(21);
    root->left = newNode(16);
    root->right = newNode(25);
    root->left->left = newNode(10);
    root->left->right = newNode(18);
    root->right->left = newNode(22);
    root->right->right = newNode(28);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(12);

    int ele;
    printf("ENTER ELEMENT TO BE SEARCHED: ");
    scanf("%d",&ele);

    int d = search(root,ele);

    if(d)
        printf("\nFOUND\n");
    else
        printf("\nNOT FOUND\n");

    return 0;
}

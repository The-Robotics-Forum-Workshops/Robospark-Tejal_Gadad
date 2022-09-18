#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left; 
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    if (!node)
    {
        printf("Memory not allocated!");
        exit(0);
    }

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}
struct node *insertNode(struct node *root, int data)
{
    if (root == NULL)
        root = createNode(data);
    else if (data <= root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);

    return root;
}

struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
        return root;
    }

    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
        return root;
    }

    // one child to node to be deletetd
    if (root->left == NULL)
    {
        struct node *temp = root->right;
        free(root);
        return temp;
    }

    else if (root->right == NULL)
    {
        struct node *temp = root->left;
        free(root);
        return temp;
    }

    // Both children exist
    else
    {
        struct node *sParent = root;

        struct node *successor = root->right;
        while (successor->left != NULL)
        {
            sParent = successor;
            successor = successor->left;
        }

        if (sParent != root)
            sParent->left = successor->right;
        else
            sParent->right = successor->right;

        root->data = successor->data;
        free(successor);
        return root;
    }
}

//left->root->right
void inOrder(struct node *node)
{
    if (node == NULL)
        return;

    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}

//root->left->right
void preOrder(struct node *node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}
//left->right->root
void postOrder(struct node *node)
{
    if (node == NULL)
        return;

    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->data);
}

int main()
{
    struct node *root = NULL;
    root = insertNode(root, 3);
    root = insertNode(root, 40);
    root = insertNode(root, 21);
    root = insertNode(root, 92);
    root = insertNode(root, 33);
    root = insertNode(root, 65);
    root = insertNode(root, -1);
    root = insertNode(root, 15);
    root = insertNode(root, 99);
    root = insertNode(root, 83);
    root = insertNode(root, 32);

    printf("\n Inorder Transversal: ");
    inOrder(root);
    printf("\n Pre-Order Transversal: ");
    preOrder(root);
    printf("\n Post-Order Transversal: ");
    postOrder(root);

    printf("\n Deleting node with val 15");
    root = deleteNode(root, 15);
    printf("\n Inorder Transversal : ");
    inOrder(root);

    printf("\n  Deleting node with val 32");
    root = deleteNode(root, 32);
    printf("\n Inorder Transversal : ");
    inOrder(root);

    return 0;
}
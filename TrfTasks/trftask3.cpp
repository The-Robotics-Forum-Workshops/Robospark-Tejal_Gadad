#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

struct node *newnode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void traverse(struct node *root) {
  if (root != NULL) 
  {
    traverse(root->left);
    cout << root->key << "->";
    traverse(root->right);
  }
}

// Insert a node
struct node *insert(struct node *node, int key) {
  if (node == NULL) return newnode(key);

  if (key < node->key)
    node->left= insert(node->left, key);
  else
    node->right= insert(node->right, key);

  return node;
}

struct node *minvaluenode(struct node *node) {
  struct node *current = node;


  while (current && current->left != NULL)
    current = current->left;

  return current;
}


struct node *deletenode(struct node *root, int key) {

  if (root == NULL) return root;

  if (key < root->key)
    root->left = deletenode(root->left, key);
  else if (key > root->key)
    root->right = deletenode(root->right, key);
  else {

    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    struct node *temp = minvaluenode(root->right);
    root->key = temp->key;
    root->right = deletenode(root->right, temp->key);
  }
  return root;
}

int main()
{
  struct node *root = NULL;
  root = insert(root, 9);
  root = insert(root, 3);
  root = insert(root, 1);
  root = insert(root, 4);
  root = insert(root, 6);
  root = insert(root, 18);
  root = insert(root, 2);
  root = insert(root, 11);

  cout<< "Inorder traversal: ";
  traverse(root);

  cout<< "\nAfter deleting 10\n";
  root = deletenode(root, 11);
  cout<< "Inorder traversal: ";
  traverse(root);
}
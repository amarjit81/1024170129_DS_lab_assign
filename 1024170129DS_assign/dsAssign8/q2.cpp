// Implement following functions for Binary Search Trees
// (a) Search a given item (Recursive & Non-Recursive)
// (b) Maximum element of the BST
// (c) Minimum element of the BST
// (d) In-order successor of a given node the BST
// (e) In-order predecessor of a given node the BST

#include <iostream>
using namespace std;

struct Node
{
              int data;
              Node *left;
              Node *right;
              Node(int x) : data(x), left(NULL), right(NULL) {}
};

Node *insert(Node *root, int key)
{

              if (root == nullptr)
              {
                            return new Node(key);
              }
              if (key < root->data)
              {
                            root->left = insert(root->left, key);
              }
              else
              {
                            root->right = insert(root->right, key);
              }
              return root;
}

// (a) Search: Recursive
Node *searchRecursive(Node *root, int key)
{
              if (!root || root->data == key)
                            return root;
              if (key < root->data)
                            return searchRecursive(root->left, key);
              return searchRecursive(root->right, key);
}

//// (a) Search: Non-Recursive
Node *searchIterative(Node *root, int key)
{
              while (root != nullptr)
              {
                            if (key == root->data)
                                          return root;
                            root = (key < root->data) ? root->left : root->right;
              }
              return NULL;
}

//// (b) Maximum element
Node *findMax(Node *root)
{
              while (root && root->right)
                            root = root->right;
              return root;
}

//// (c) Minimum element
Node *findMin(Node *root)
{
              while (root && root->left)
                            root = root->left;
              return root;
}

//// (d) Inorder Successor of a node
Node *inorderSuccessor(Node *root, Node *target)
{
              if (target->right)
                            return findMin(target->right);

              Node *succ = NULL;
              while (root)
              {
                            if (target->data < root->data)
                            {
                                          succ = root;
                                          root = root->left;
                            }
                            else if (target->data > root->data)
                            {
                                          root = root->right;
                            }
                            else
                                          break;
              }
              return succ;
}

//// (e) Inorder Predecessor
Node *inorderPredecessor(Node *root, Node *target)
{
              if (target->left)
                            return findMax(target->left);

              Node *pred = NULL;
              while (root)
              {
                            if (target->data > root->data)
                            {
                                          pred = root;
                                          root = root->right;
                            }
                            else if (target->data < root->data)
                            {
                                          root = root->left;
                            }
                            else
                                          break;
              }
              return pred;
}

int main()
{
              Node *root = NULL;
              int arr[] = {20, 18, 22, 4, 12, 10, 14};
              for (int x : arr)
                            root = insert(root, x);

              Node *target = searchRecursive(root, 12);
              cout << "Inorder Successor of 12: " << inorderSuccessor(root, target)->data << endl;
              cout << "Inorder Predecessor of 12: " << inorderPredecessor(root, target)->data << endl;
}
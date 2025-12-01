// Write a program for binary search tree (BST) having functions for the following
// operations:
// (a) Insert an element (no duplicates are allowed),
// (b) Delete an existing element,
// (c) Maximum depth of BST
// (d) Minimum depth of

#include <iostream>
using namespace std;

struct Node
{
              int data;
              Node *left;
              Node *right;
              Node(int x)
              {
                            data = x;
                            left = nullptr;
                            right = nullptr;
              }
};

Node *insert(Node *root, int key)
{
              if (!root)
                            return new Node(key);
              if (key < root->data)
                            root->left = insert(root->left, key);
              else if (key > root->data)
                            root->right = insert(root->right, key);
              return root;
}

Node *findMin(Node *root)
{
              while (root->left)
                            root = root->left;
              return root;
}

// (b) DELETE
Node *deleteNode(Node *root, int key)
{
              if (!root)
                            return root;

              if (key < root->data)
                            root->left = deleteNode(root->left, key);
              else if (key > root->data)
                            root->right = deleteNode(root->right, key);
              else
              {
                            if (!root->left)
                            {
                                          Node *temp = root->right;
                                          delete root;
                                          return temp;
                            }
                            else if (!root->right)
                            {
                                          Node *temp = root->left;
                                          delete root;
                                          return temp;
                            }
                            Node *temp = findMin(root->right);
                            root->data = temp->data;
                            root->right = deleteNode(root->right, temp->data);
              }
              return root;
}

// (c) Maximum Depth
int maxDepth(Node *root)
{
              if (!root)
                            return 0;
              return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// (d) Minimum Depth
int minDepth(Node *root)
{
              if (!root)
                            return 0;
              if (!root->left)
                            return 1 + minDepth(root->right);
              if (!root->right)
                            return 1 + minDepth(root->left);
              return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main()
{
              Node *root = NULL;
              int arr[] = {15, 10, 20, 8, 12, 17, 25};
              for (int x : arr)
                            root = insert(root, x);

              root = deleteNode(root, 10);

              cout << "Max Depth: " << maxDepth(root) << endl;
              cout << "Min Depth: " << minDepth(root) << endl;
}
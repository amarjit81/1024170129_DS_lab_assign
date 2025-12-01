//  Write a program to determine whether a given binary tree is a BST or not.

#include <iostream>
#include <climits>
using namespace std;

struct Node
{
              int data;
              Node *left;
              Node *right;
              Node(int x) : data(x), left(NULL), right(NULL) {}
};

bool isBST(Node *root, int minVal = INT_MIN, int maxVal = INT_MAX)
{
              if (!root)
                            return true;
              if (root->data <= minVal || root->data >= maxVal)
                            return false;

              return isBST(root->left, minVal, root->data) &&
                     isBST(root->right, root->data, maxVal);
}

int main()
{
              Node *root = new Node(10);
              root->left = new Node(5);
              root->right = new Node(20);
              root->left->right = new Node(8);

              if (isBST)
                            cout << "valid BST";
              else
                            cout << "not valid BST";
}
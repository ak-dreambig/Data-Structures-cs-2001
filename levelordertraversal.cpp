
// order traversal of Binary Tree
#include <bits/stdc++.h>
using namespace std;

/*


OTHER way to find level order traversal 



void row( Node *& temp)
        {
            if ( temp -> left != NULL)
                cout << temp -> left -> data << "\t";
            
            if ( temp -> right != NULL)
            cout << temp -> right -> data << "\t";

            return;
        }

        void print_level( Node *& temp)
        {
            if ( root == NULL)
            {
                cout << "\nTree is empty." << endl;
                return;
            }

            if ( temp == root)
            {
                cout << temp -> data << "\t";
                cout << temp -> left -> data << "\t";
                cout << temp -> right -> data << "\t";
            }

            if ( temp -> left != NULL)
                row( temp -> left);

            if ( temp -> right != NULL)
                row( temp -> right);

            if ( temp -> left != NULL)
                print_level( temp -> left);

            if ( temp -> right != NULL)
                print_level( temp -> right);

            return;
        }



*/

/* A binary tree node has data,
pointer to left child
and a pointer to right child */
class node {
public:
    int data;
    node *left, *right;
};
 
/* Function prototypes */
void printCurrentLevel(node* root, int level);
int height(node* node);
node* newNode(int data);
 
/* Function to print level
order traversal a tree*/
void printLevelOrder(node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 
/* Print nodes at a current level */
void printCurrentLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}
 
/* Compute the "height" of a tree -- the number of
    nodes along the longest path from the root node
    down to the farthest leaf node.*/
int height(node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}
 
/* Helper function that allocates
a new node with the given data and
NULL left and right pointers. */
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return (Node);
}

int main()
{
    node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
 
    return 0;
}
 
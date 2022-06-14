// Binary Search Tree Implementation..  
#include<iostream>
using namespace std;
class Node {
	public:
	int data;
	Node* left;	
	Node* right;
	
	Node(int data){
	
		this->data=  data;
		left= right= NULL;
	}
}; 
class BinarySearchTree{
	public:
	int counter = 0;
	Node* root;
	BinarySearchTree(){
		root= NULL;
	}
	Node* insert( Node* root, int val);
	Node* inOrderTraversal( Node* root);
	Node* Calculate_Parents(Node* root);
};

int main (){
	BinarySearchTree tree1;
  	tree1.insert(tree1.root,100);
    tree1.insert(tree1.root, 50);
    tree1.insert(tree1.root, 150);
    tree1.insert(tree1.root, 75);
    tree1.insert(tree1.root, 74);
    tree1.insert(tree1.root, 76);
    tree1.insert(tree1.root, 73);
    tree1.insert(tree1.root, 125);
    tree1.insert(tree1.root, 124);
    tree1.insert(tree1.root, 130);
    tree1.insert(tree1.root, 131);
	cout<<"In Order Print (left--Root--Right)"<<endl;
	tree1.inOrderTraversal(tree1.root);	
	tree1.Calculate_Parents(tree1.root);
	return 0;
}

Node* BinarySearchTree::insert(Node* r, int val ){
	
 if (r==NULL)
	{
		Node* t= new Node(val);		
		if (r==root)
		root= r=t;
		else
		r=t;		
		return r;
	}
//	else if (r->data== val){
//		//cout<<"Duplicate Record  "<<val;
//			return r;
//	}
	else if (val < r->data)
		r->left = insert(r->left , val );
	
	else if (val > r->data)
		r->right= insert( r->right,val);
}
Node * BinarySearchTree::inOrderTraversal( Node* r){
	 if (r == NULL)
        return NULL;
    inOrderTraversal(r->left);
    cout << " "<< r->data << " -> ";

    inOrderTraversal(r->right);

    
}

Node * BinarySearchTree::Calculate_Parents(Node* r)
{
	if(r != NULL)
	{

		if(r->left != NULL || r->right != NULL)
		{
			counter++;
			Calculate_Parents(r->left);
			Calculate_Parents(r->right);
			
			cout<<"Total Parents nodes are : "<<counter<<endl;
		}
		
	}
}

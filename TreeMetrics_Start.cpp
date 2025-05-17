
 
#include <iostream>
#include <algorithm>  // for max
#include <vector>
using namespace std;


struct  BTreeNode
{
    private:
        double value; // value of the node
        BTreeNode *left; // pointer to left child
        BTreeNode *right; // pointer to right child
        friend class BST; // make BST a friend class
        
    // Constructor for BTreeNode
    BTreeNode(double x, BTreeNode *leftp = NULL, BTreeNode *rightp = NULL)
        : value(x), left(leftp), right(rightp) {}
};

// Binary tree class itself
class BST
{
public:
    int height( ) {return height(tree);}
    bool search(double x) {return search (x, tree);}
    void insert(double x);
    void inorder(vector<double> & v){ inorder(v, tree);}
    int leafCounter( ) {return leafCounter(tree); }
    BST() {tree = NULL;}
private:
    bool search(double x, BTreeNode *t);
    void inorder(vector<double>&tlist, BTreeNode *t);
    int leafCounter(BTreeNode *t);
    static int height(BTreeNode *t);
    BTreeNode *tree;
};

//*************************************************
//             BST::height                        *
// Determines the height of a binary tree.        *
//*************************************************
int BST::height(BTreeNode *t)
{
	
    if (t == NULL) return 0; // base case: empty tree has height 0
    else return max(height(t->left), height(t->right)) + 1; // recursive case
}

//************************************************
//           BST::leafCounter                    *
// Recursively counts the leaves in the tree.    *
//************************************************
int BST::leafCounter(BTreeNode *t )
{
	
    if (t == NULL) return 0; // base case: empty tree has no leaves
    if (t->left == NULL && t->right == NULL) return 1; // leaf node
    else return leafCounter(t->left) + leafCounter(t->right); // recursive case

}

//****************************************************
//              BST::search                          *
// Given a value x and a pointer to the root of a    *
// binary search tree, this function returns true    *
// is x is in the tree, and false otherwise.         *
//****************************************************
bool BST::search(double x, BTreeNode *t)
{
	
    if (t == NULL) return false; // base case: empty tree has no x
    if (t->value == x) return true; // found x
    else if (t->value > x) return search(x, t->left); // search left subtree
    else return search(x, t->right); // search right subtree
}

//*****************************************
//         BST::insert                    *
// Insert x into the binary search tree.  *
// Must be non-recursive.                 *
//*****************************************
void BST::insert(double x)
{
    if (tree == NULL) 
    {
        tree = new BTreeNode(x);
        return;
    }
   
    // Use p  to search for right place to insert
    // p will point to the node that will be the parent
    // of the node being added
    BTreeNode *p = tree; 
    while (p != NULL)
    {
        if (x <= p->value)
        {
            // x goes to left of p
            if (p->left == NULL)
            {                
                p->left = new BTreeNode(x);
                return;                
            }
            else
                p = p->left;            
        }
        else
        {
            if (p->right == NULL)
            {                
                p->right = new BTreeNode(x);
                return;                
            }
            else
                p = p->right;
        }        
    }    
}

//********************************************************************
//                 BST::inorder                                      *
// This call to inorder appends all nodes in subtree rooted at t     *
// to the ordered list passed in as parameters.                      *
//********************************************************************
void BST::inorder(vector<double> & orderedList, BTreeNode *t)       
{
    if (t == NULL) return;
    inorder(orderedList, t->left);
    orderedList.push_back(t->value);
    inorder(orderedList, t->right);
}

int main()
{
    // Tell user what program does
    cout << "This program allows you to insert some numbers in binary search tree.";    
    cout << "\nTt prints out the numbers in the tree in inorder.";
    cout << "\nIt then computes and prints the height of the tree.";    
    
    // Tell user to enter numbers
    BST tree1;
    cout << "\nEnter 5 numbers: \n";
    for (int k = 1; k <= 5; k++)
    {
        double x;
        cin >> x;
        tree1.insert(x);
    }    
    // Compute  values in inorder
    vector<double> orderedList;
    orderedList.clear();
    tree1.inorder(orderedList);   

    // Print the inorder list        
    for (unsigned int k = 0; k < orderedList.size(); k++)
        cout << orderedList[k] << "  ";    

    // Compute height and report
    cout << "\nThe height of the tree is " << tree1.height();       
    return 0;
    
}

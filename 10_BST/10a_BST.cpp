// insert, search, inorder

#include <iostream>
using namespace std;
 
class Node                  // node for binary tree
{
public:
    Node* lchild;           // or struct Node* lchild;
    int data;
    Node* rchild;
};

class BST
{
private:
    Node *root;
public:
    BST(){ root = NULL; }
    Node *getRoot(){ return root; }
    void Insert(int key);
    void Inorder(Node* p);
    Node *Search(int key);
};
 
void BST::Insert(int key) 
{
 
    Node *t = root;
    Node *p;
    Node *r;
 
    // root is empty
    if (root == NULL)
    {
        p = new Node;
        p->data = key;
        p->lchild = NULL;
        p->rchild = NULL;
        root = p;
        return;                         // stops the function Insert when we insert the first node, else it 
    }                                   // might insert a new node in another place
 
    while(t != NULL)                    // searches all subtree if the nodes are in the expected level
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else                        // if the element is already inserted then we will not try to insert it again
        {
            return;
        }
    }

    // Now t points at NULL and r points at insert location
    p = new Node;
    p->data = key;
    p->lchild = NULL;
    p->rchild = NULL;
 
    if (key < r->data)
    {
        r->lchild = p;
    } 
    else 
    {
        r->rchild = p;
    } 
}

void BST::Inorder(Node* p) 
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << ", " ;
        Inorder(p->rchild);
    }
}
 
Node* BST::Search(int key) 
{
    Node* t = root;
    while (t != NULL)
    {
        if (key == t->data)
        {
            return t;
        } 
        else if (key < t->data)
        {
            t = t->lchild;
        } 
        else 
        {
            t = t->rchild;
        }
    }
    return NULL;
}
 
 
int main() 
{
 
    BST bst;
 
    // Insert
    bst.Insert(10);
    bst.Insert(5);
    bst.Insert(20);
    bst.Insert(8);
    bst.Insert(30);
    bst.Insert(15);
 
    // Inorder traversal
    bst.Inorder(bst.getRoot());                 // prints the binary tree in inorder format
    cout << endl;
 
    // Search
    Node* temp = bst.Search(2);                 // since values are returned in Node format 
    if (temp != NULL)                           // therefore temp must also be declared as Node
    {
        cout << temp->data << endl;
    } 
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}
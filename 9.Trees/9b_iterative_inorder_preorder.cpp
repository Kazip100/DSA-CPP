#include <iostream>
#include "9a_Stack.cpp"             // calliing the 9a_Stack.cpp file will also call the 9a_Queue.cpp file too
using namespace std;

class Tree
{
public:
    Node *root;
    Tree(){root=NULL;}
    void CreateTree();
    void Preorder(){Preorder(root);}
    void Preorder(Node *p);
    void Postorder(){Postorder(root);}
    void Postorder(Node *p);
    void Inorder(){Inorder(root);}
    void Inorder(Node *p);
    
    void Levelorder(){Levelorder(root);}
    void Levelorder(Node *p);
    int Height(){return Height(root);}
    int Height(Node *root);

    void IPreorder(){ IPreorder(root); }
    void IPreorder(Node *p);

    void Iinorder(){ Iinorder(root); }
    void Iinorder(Node *p);
};

void Tree::CreateTree()
{
    Node *p,*t;
    int x;
    Queue q(100);

    printf("Enter root value ");
    scanf("%d",&x);
    root=new Node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    q.enqueue(root);

    while(!q.isEmpty())
    {
        p=q.dequeue();
        printf("Enter left child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            q.enqueue(t);
        }
        printf("Enter right child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            q.enqueue(t);
        }
    }
}
void Tree::Preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Tree::Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}
void Tree::Postorder(struct Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}
void Tree::Levelorder(struct Node *root)
{
    Queue q(100);

    printf("%d ",root->data);
    q.enqueue(root);

    while(!q.isEmpty())
    {
        root=q.dequeue();
        if(root->lchild)
        {
            printf("%d ",root->lchild->data);
            q.enqueue(root->lchild);
        }
        if(root->rchild)
        {
            printf("%d ",root->rchild->data);
            q.enqueue(root->rchild);
        }
    }
}
int Tree::Height(struct Node *root)
{
    int x=0,y=0;
    if(root==0)
        return 0;
    x=Height(root->lchild);
    y=Height(root->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;

}

void Tree::IPreorder(struct Node *p)
{
    struct Stack stk;
    Stackcreate(&stk, 100);

    while( p || !isEmptyStack(stk) )
    {
        if(p)
        {
            cout << p->data << " ";
            push(&stk, p);              // stores address of the node to come back again
            p = p->lchild;            
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}

void Tree :: Iinorder(struct Node *p)
{
    struct Stack stk;
    Stackcreate(&stk, 100);

    while( p || !isEmptyStack(stk) )
    {
        if(p)
        {
            push(&stk, p);              // stores address of the node to come back again
            p = p->lchild;            
        }
        else
        {
            p = pop(&stk);
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}

int main()
{
    Tree t;
    t.CreateTree();
    cout<<"Preorder ";
    t.Preorder(t.root);
    cout<<endl;

    cout<<"Inorder ";
    t.Inorder(t.root);
    cout<<endl;

    cout<<"Postorder ";
    t.Postorder(t.root);
    cout<<endl;
    
    cout << "Iterative Inorder: ";
    t.Iinorder(t.root);
    cout<<endl;

    cout << "Iterative Preorder: ";
    t.IPreorder(t.root);
    cout<<endl;

    
    return 0;
}
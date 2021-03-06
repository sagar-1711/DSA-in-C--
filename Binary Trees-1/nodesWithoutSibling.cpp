
#include<iostream>
using namespace std;
class node
{
    public:
        int data;
        node*left;
        node*right;
        node(int data)
        {
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};
node*treeInput()
{   int data;
    cin>>data;
    if(data==-1)
        return NULL;
    node*root=new node(data);
    root->left=treeInput();
    root->right=treeInput();
    return root;

}
void printTreeDetailed(node*root)
{
    if(root==NULL)
        return;
    cout<<root->data<<":";
    if(root->left!=NULL)
        cout<<"L"<<root->left->data<<",";
    if(root->right!=NULL)
        cout<<"R"<<root->right->data<<" ";
    cout<<endl;
    printTreeDetailed(root->left);
    printTreeDetailed(root->right);

}
void nodesWithoutSibling(node*root)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right!=NULL)
        cout<<root->right->data<<endl;
    if(root->left!=NULL && root->right==NULL)
        cout<<root->left->data<<endl;
    nodesWithoutSibling(root->left);
    nodesWithoutSibling(root->right);

}


int main()
{

    node*root=treeInput();
    printTreeDetailed(root);
    nodesWithoutSibling(root);

}

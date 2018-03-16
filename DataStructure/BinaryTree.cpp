
#include<iostream>
using namespace std;

typedef char datatype;

struct BinNode{
    datatype data;
    BinNode * lchild;
    BinNode * rchild;
};

typedef BinNode* bintree; //bintree本身是个指向结点的指针  
//-----------------------------------------------------------------
//递归实现
//前序遍历
void preorder(bintree t){
    if(t){
        cout<<t->data<<' '<<endl;
        preorder(t->lchild);
        preorder(t->rchild);
    }
}
//中序遍历
void inorder(bintree t){
    if(t){
        inorder(t->lchild);
        cout<<t->data<<' '<<endl;
        inorder(t->rchild);
    }
}
//后续遍历
void postorder(bintree t){
    if(t){
        postorder(t->lchild);
        postorder(t->rchild);
        cout<<t->data<<' '<<endl;
    }
}
//-----------------------------------------------------------------




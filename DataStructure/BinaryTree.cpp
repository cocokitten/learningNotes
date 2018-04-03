
#include<iostream>
using namespace std;

typedef char datatype;

struct BinaryNode{
    datatype data;
    BinaryNode * lchild = nullptr;
    BinaryNode * rchild = nullptr;
};

typedef BinaryNode* bintree; //bintree本身是个指向结点的指针  
//-----------------------------------------------------------------
// 先序构造二叉树
void createBinaryTree(BinaryNode *&node) {
	char ch;
	cin >> ch;
	if (ch == '#') {
		return;
	}
	if (node == nullptr) {
		node = new BinaryNode();
	}
	node->data = ch;
	createBinaryTree(node->lchild);
	createBinaryTree(node->rchild);
}
//-----------------------------------------------------------------
//递归实现

// 先序遍历
void preOrderTraverse(BinaryNode *node) {
	if (node == nullptr) {
		return;
	}
	//printf("%c\n", node->data);
	cout << node->data << ',';
	preOrderTraverse(node->lchild);
	preOrderTraverse(node->rchild);
}

// 中序遍历
void inOrderTraverse(BinaryNode *node) {
	if (node == nullptr) {
		return;
	}
	inOrderTraverse(node->lchild);
	printf("%c\n", node->data);
	inOrderTraverse(node->rchild);
}

// 后序遍历
void postOrderTraverse(BinaryNode *node) {
	if (node == nullptr) {
		return;
	}
	postOrderTraverse(node->lchild);
	postOrderTraverse(node->rchild);
	printf("%c\n", node->data);
}
//-----------------------------------------------------------------
//求二叉树中的节点个数
int getNodeNum(BinaryNode* pRoot) {

	if (pRoot==nullptr) return 0;
	return getNodeNum(pRoot->lchild) + getNodeNum(pRoot->rchild)+1;
}
//-----------------------------------------------------------------
//求二叉树的深度

int getDepth(BinaryNode* pRoot) {

	if (pRoot == nullptr)return 0;
	int dLeft = getDepth(pRoot->lchild) + 1;
	int dRight = getDepth(pRoot->rchild) + 1;
	return dLeft > dRight ? dLeft : dRight;
}
//-----------------------------------------------------------------
//判断两颗二叉树是否相等(腾讯面试)
bool is_equal(BinaryNode* pRoot1,BinaryNode* pRoot2) {
	
	if (pRoot1 == nullptr && pRoot2 == nullptr)return true;
	if (pRoot1 == nullptr || pRoot2 == nullptr)return false;
	//if ((pRoot1 == nullptr && pRoot2 != nullptr) || (pRoot1 != nullptr && pRoot2 == nullptr))return false;

	//bool res_l = is_equal(pRoot1->lchild, pRoot2->lchild);
	//bool res_r = is_equal(pRoot1->rchild, pRoot2->rchild);
	//return (res_l && res_r);

	//不加这一句比较二叉树结构是否相同
	//if (pRoot1->data != pRoot2->data) return false;//加上这句比较二叉树结构和数据是否同时相等，即两个一模一样的树
	return is_equal(pRoot1->lchild, pRoot2->lchild) && is_equal(pRoot1->rchild, pRoot2->rchild);
}
//-----------------------------------------------------------------
int main(int argc, const char * argv[]) {
	// 输入示例：AB#C##D##
	//abc#e##d##f##

	printf("请输入一棵二叉树(#表示无子节点):\n");
	BinaryNode *tree1 = new BinaryNode();
	createBinaryTree(tree1);

	BinaryNode *tree2 = new BinaryNode();
	createBinaryTree(tree2);

	cout << is_equal(tree1, tree2) << endl;
	
	//printf("先序遍历:\n");
	//preOrderTraverse(tree);
	//printf("中序遍历:\n");
	//inOrderTraverse(tree);
	//printf("后序遍历:\n");
	//postOrderTraverse(tree);
	//printf("中序线索化遍历:\n");
	//inOrderTreading(tree);
	//inOrderTreadingTraverse(tree);

	/*cout << "该二叉树中节点个数为：";
	cout << getNodeNum(tree1) << endl;
	cout << "二叉树深度：";
	cout << getDepth(tree1) << endl;*/
	return 0;
}

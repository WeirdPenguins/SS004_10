
#include <iostream>
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

TNODE* CreateTNode(int x) {
	TNODE *p=new TNODE; //cấp phát vùng nhớ động
	p->key = x; //gán trường dữ liệu của node = x
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int Insert(TREE &T, TNODE *p) {
	if (T) {
		if (T->key == p->key) return 0;
		if (T->key > p->key)
			return Insert(T->pLeft, p);
		return Insert(T->pRight, p);
	}
	T = p;
	return 1;
}
void CreateTree(TREE &T){
	int x;
	do {
		cin >> x;
		if(x==-1) break;
		Insert(T, CreateTNode(x));
	}while(true);
}

void DemNode(TREE t, int &count) {
    if (t == NULL)
         return;
     DemNode(t->pRight, count);
     if (t->pRight == NULL && t->pLeft == NULL)
        count++;
     DemNode(t->pLeft, count);
}

int CountLeaf(TREE T)
{
    int count = 0;
    if (T == NULL)
       return 0;
    else {
        DemNode(T, count);
    }
  return count;
}




int main() {
	TREE T; //hay: TNODE* T; OMG OMG OMG
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	cout << CountLeaf(T);
	return 0;
}


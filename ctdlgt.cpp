//                                                     SORTING 
#if 0
char ok;
void InterchangeSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                swap(a[i], a[j]);
            }
        }
    }
}
void SelectionSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[min_pos] > a[j])
            {
                min_pos = j;
            }
        }
        swap(a[i], a[min_pos]);
    }
}
void BubbleSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
        }
    }
}
void InsertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i], pos = i - 1;
        while (pos >= 0 && x < a[pos])
        {
            a[pos + 1] = a[pos];
            --pos;
        }
        a[pos + 1] = x;
    }
}
void BinaryInsertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int x = a[i], left = 0, right = i - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (x < a[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        for (int j = i - 1; j >= left; j--)
        {
            a[j + 1] = a[j];
        }
        a[left] = x;
    }
}
int getMax(int *a, int n)
{
    int mx = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > mx)
            mx = a[i];
    return mx;
}
void RadixSort(int *a, int n)
{
    int m = getMax(a, n);
    int output[n], count[10] = {0};
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        for (int i = 0; i < n; i++)
            count[(a[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--)
        {
            output[count[(a[i] / exp) % 10] - 1] = a[i];
            count[(a[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++)
            a[i] = output[i];
        fill(count, count + 10, 0);
    }
}
void CountingSort(int *a, int n)
{
    int maxElement = *max_element(a, a + n);
    int *b = new int[maxElement + 1]{0};
    for (int i = 0; i < n; i++)
        b[a[i]]++;
    for (int i = 1; i <= maxElement; i++)
        b[i] += b[i - 1];
    int *c = new int[n];
    for (int i = n - 1; i > -1; i--)
    {
        c[b[a[i]] - 1] = a[i];
        b[a[i]]--;
    }
    for (int i = 0; i < n; i++)
        a[i] = c[i];
    delete[] b;
    delete[] c;
}
void QuickSort(int *a, int l, int r)
{
    if (l >= r)
        return;
    int x = a[(l + r) / 2];
    int i = l;
    int j = r;
    while (i <= j)
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    QuickSort(a, l, j);
    QuickSort(a, i, r);
}
void Merge(int *a, int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int nc = 0;
    int *c = new int[r - l + 1];
    while (i <= m && j <= r)
    {
        if (a[i] < a[j])
        {
            c[nc++] = a[i++];
        }
        else
            c[nc++] = a[j++];
    }
    while (i <= m)
    {
        c[nc++] = a[i++];
    }
    while (j <= r)
    {
        c[nc++] = a[j++];
    }
    for (int i = 0; i < nc; i++)
    {
        a[i + l] = c[i];
    }
    delete[] c;
}
void MergeSort(int *a, int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    Merge(a, l, m, r);
}
void heapify(int *a, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void HeapSort(int *a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}
void ShellSort(int *a, int n)
{
    int gap = n / 2;
    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j = i;
            while (j >= gap && a[j - gap] > temp)
            {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
        }
        gap /= 2;
    }
}
void ShakerSort(int *a, int n)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        for (int i = left; i < right; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
            }
        }
        right--;
        for (int i = right; i > left; i--)
        {
            if (a[i] < a[i - 1])
            {
                swap(a[i], a[i - 1]);
            }
        }
        left++;
    }
}
#endif
#if 0

#include <iostream>
#include <cstring>
#include <string>
using namespace std;
struct node{
    int id;
    string name;
    int pop;
    double area;
    node* next;
};
struct List{
    node* pHead,*pTail;
};
void Init(List& a){
    a.pHead=a.pTail=NULL;
}
void input(node* &p){
    p=new node();
    cin >>p->id;
    cin.ignore();
    getline(cin,p->name);
    cin >>p->pop>>p->area;
}
void inputListProvinces(List &a){
    int n; cin >>n;
    if (n==0){
        return;
    } 
    for (int i=0;i<n;i++){
        node* p=new node();
        input(p);
        if (a.pHead==NULL){
            a.pHead=a.pTail=p;
        }else {
            a.pTail->next=p;
            a.pTail=p;
        }
    }
}
void output(node* p){
    cout <<p->id<<"\t"<<p->name<<"\t"<<p->pop<<"\t"<<p->area<<endl;
}
void outputListProvinces(List a){
    if (a.pHead == NULL){
        cout <<"List is empty";
        return;
    }
    node* p=a.pHead;
    while (p!=NULL){
        output(p);
        p=p->next;
    }
} 
bool endsWith(string& full, string& end) {
    if (full.length() >= end.length()) {
        return (full.compare(full.length() - end.length(), end.length(), end) == 0);
    } else {
        return false;
    }
}
int removeProvince(List& a, string s){
    if (a.pHead == NULL) {
        return 0;
    }
    node* current = a.pHead;
    node* prev = NULL;
    int count = 0;
    while (current != NULL) {
        if (endsWith(current->name, s)) {
            count++;
            if (current == a.pHead) {
                a.pHead = current->next;
                delete current;
                current = a.pHead;
            } else {
                prev->next = current->next;
                if (a.pTail == current) {
                    a.pTail = prev;
                }
                delete current;
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
    return count;
}

int main(){
    List L;
    Init (L);
    inputListProvinces (L);
    cout <<"List of provinces:"<<endl;
    cout <<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);
    if (L.pHead){
        string s;
        cin.ignore();
        cout <<"Enter the last word of name to research:"<<endl;
        getline(cin,s);
        int i=removeProvince(L,s);
        if(i==0) cout <<"Not found";
        else{
            cout <<"Updated List:"<<endl;
            cout <<"ID\t|Province\t|Population\t|Area"<<endl;
            outputListProvinces(L);
        }
    }
}
#endif
#if 0
#include <bits/stdc++.h>
using namespace std;
struct node// cau truc cua 1 node
{
    int info;
    node*left, *right;
};
node* getnode(int x)
{
    node* p = new node;
    p->info= x;
    p->left = p->right=NULL;
    return p;
    
}
typedef node* Tree;

void inputTree1(Tree &T, int x)//(node* T) -> them x vao T
{
    if(T!= NULL)
    {
        if(x==T->info){
            cout<<"Bi trung";
        }
        else if(x<T->info)// them vao ben trai cua T
        {   
            inputTree1(T->left, x);
        }
        else{
            inputTree1(T->right, x);
        }
    }// neu T= NULL thi moi gan x vao
    else{
            T=getnode(x);
        }
}
void inputTree(Tree &T)
{
    int n,x;
    cin>>n;
    while(n>0)
    {
        cin>>x;
        inputTree1(T,x);
        n--;
    }
}

void NLR(Tree T)// PreOrder
{
    if(T==NULL)
    {
        return; // cay rong thi ko xuat nua
    }
    
    cout<<T->info<<" ";
    // xuat het cai nhanh trai
    NLR(T->left);
    NLR(T->right);
}
void LRN(Tree T) // PostOrder
{
    if(T==NULL)
    {
        return;
    }
    
    LRN(T->left);
    LRN(T->right);
    cout<<T->info<<" ";

}

void LNR(Tree T) // InOrder
{
    if(T==NULL)
    {
        return;
    }
    LNR(T->left);
    cout<<T->info<<" ";
    LNR(T->right);
}

void listLeafs(Tree T)
{
    if(T!=NULL)
    {
        if(T->left ==NULL&& T->right== NULL)
        {
            cout<<T->info<<" ";
        }
    listLeafs(T->left);// duyệt sang cây con trái của node hiện tại
    listLeafs(T->right); // duyệt sang cây con phải của node hiện tại
    }
}
void listNodesWithOneChild(Tree T)
{
    if(T!=NULL)
    {
        if((T->left ==NULL&& T->right!=NULL)||(T->right ==NULL&& T->left!=NULL))
        {
            cout<<T->info<<" ";
        }
    listNodesWithOneChild(T->left);// duyệt sang cây con trái của node hiện tại
    listNodesWithOneChild(T->right); // duyệt sang cây con phải của node hiện tại
    }
}

void listNodesWithTwoChildren(Tree T)
{
    if(T!=NULL)
    {
        if(T->left !=NULL&& T->right!=NULL)
        {
            cout<<T->info<<" ";
        }
        listNodesWithTwoChildren(T->left);
        listNodesWithTwoChildren(T->right);
    }
}
/*
    su ly goc
    goi nhanh cay ben trai
    goi nhanh cay ben phai 
*/
 void listInternalNodes(Tree T, int a)// node trong
 {
    if(T!=NULL)
    {
        if(a!=0&&(T->left!=NULL||T->right !=NULL))
        cout<<T->info<<" ";
        listInternalNodes(T->left,1);
        listInternalNodes(T->right,1);
    }
 }
#endif
#if 0
                                            //Stack
    //push
    //pop
    //top
    //size
    //empty()
                                            //Queue
    //push
    //pop
    //front
    //back
    //size
    //empty()
                                            //Deque
    //push_front()
    //push_back()
    //pop_back()
    //pop_front()
    //empty()
    //front()
    //back()
#endif
#if 0
/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
[
]
define
include
###End banned keyword*/
#include<iostream>
#include <iomanip>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
};


struct Node{
	DONTHUC* data;
	Node* next;

};

typedef struct DATHUC{
	Node* head;
	Node* tail;
}List;
Node* getnode(double x, int y) {
    Node* tmp = new Node;
    tmp->data = new DONTHUC;
    tmp->data->heso = x;
    tmp->data->somu = y;
    tmp->next = NULL;
    return tmp;
}
void addlast(DATHUC& b, double x, int y) {
    Node* tmp = getnode(x, y);
    if (b.head == NULL) {
        b.head = b.tail = tmp;
        return;
    }
    b.tail->next = tmp;
    b.tail = tmp;

}
void Nhap(DATHUC& b) {
    int n; cin >> n;
    b.head = b.tail = NULL;
    while (n > 0) {
        double x; int y;
        cin >> x >> y;
        addlast(b, x, y);
        n--;
    }
}

DATHUC Tong2DaThuc(DATHUC& a, DATHUC b) {
    DATHUC result;
    result.head = result.tail = NULL;
    Node* tmp1 = a.head;
    Node* tmp2 = b.head;
    while (tmp1 != NULL && tmp2 !=NULL) {
        if (tmp1->data->somu == tmp2->data->somu) {
            double sum = tmp1->data->heso + tmp2->data->heso;
            addlast(result, sum, tmp1->data->somu);
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        else if (tmp1->data->somu > tmp2->data->somu) {
            addlast(result, tmp1->data->heso, tmp1->data->somu);
            tmp1 = tmp1->next;
        }
        else {
            addlast(result, tmp2->data->heso, tmp2->data->somu);
            tmp2 = tmp2->next;
        }
    }
    while (tmp1 != NULL) {
        addlast(result, tmp1->data->heso, tmp1->data->somu);
        tmp1 = tmp1->next;
    }

    while (tmp2 != NULL) {
        addlast(result, tmp2->data->heso, tmp2->data->somu);
        tmp2 = tmp2->next;
    }
    return result;
}
void Xuat(DATHUC a) {
    bool firstTerm = true;

    Node* p = a.head;
    while (p != NULL) {
        if (p->data->heso != 0) {
            if (!firstTerm && p->data->heso > 0) {
                cout << "+";
            }
            if (abs(p->data->heso) != 1 || p->data->somu == 0) {
                cout << p->data->heso;
            } else if (p->data->heso == -1) {
                cout << "-";
            }
            if (p->data->somu > 0) {
                cout << "x";
                if (p->data->somu > 1) {
                    cout << "^" << p->data->somu;
                }
            }
            firstTerm = false;
        }
        p = p->next;
    }
    if (firstTerm) {
        cout << 0;
    }
    cout << endl;
}


int main() {
    DATHUC A, B;
    Nhap(A);
    Nhap(B);
    cout << "Da thuc A: "; Xuat(A);
    cout << "\nDa thuc B: "; Xuat(B);
    cout << "\nA+B = "; Xuat(Tong2DaThuc(A, B));
    return 0;
}
#endif
#if 1

#include <bits/stdc++.h>
using namespace std;
int main(){
    cout <<sizeof(int);
}
#endif

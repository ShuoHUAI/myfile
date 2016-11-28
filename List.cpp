// List.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
using namespace std;
template<class T>
class ListNode {
public:
	T data;
	ListNode<T> *node;
	ListNode(T &t) { data = t; node = 0; };
	~ListNode() { delete data; delete node; };
};
template <class T>
class List {
public:
	List() { length = 0; head = NULL; };
	~List() { for (int i = 0; i < length; i++) { head = head->node; delete head; } };
	ListNode<T> *head;
	List<T> &AddHead(T &t);
	List<T> &AddBack(T&t);
	List<T> &Delete(T &t, int &x);
	bool Search(T &t, int &x);
	void Output(ostream& out) const;
	void reversedOutput();
	int length;
};
template<class T>
List<T>& List<T>::AddHead(T &t) {
	ListNode<T> *current = new ListNode<T>(t);
	if (head == NULL)
	{
		head = current;
		length++;
	}
	else
	{
		ListNode<T> *cu = head;
		head = current;
		current->node = cu;
		length++;
	}
	return *this;
}
template<class T>
List<T>& List<T>::AddBack(T&t) {
	ListNode<T> *current = new ListNode<T>(t);
	if (head==NULL)
	{
		head = current;
		length++;
	}
	else
	{
		ListNode<T> *cu = head;
		for (int i = 1; i < length; i++)
		{
			cu = cu->node;
		}
		cu->node = current;
		length++;
	}
	return *this;
}
template<class T>
List<T>& List<T>::Delete(T&t, int &x) {
	ListNode<T> *current, *current1;
	current = head->node;
	current1 = head;
	x = 0;
	if (head->data == t) { head = head->node; length--; x = 1; }
	else
	{
		for (int i = 0; i < length - 1; i++)
		{
			if (current->data == t)
			{
				current1->node = current->node;
				length--;
				x = 1;
				break;
			}
			else
			{
				current = current->node;
				current1 = current1->node;
			}
		}
	}
	return *this;
}

template<class T>
bool List<T>::Search(T&t, int &x) {
	ListNode<T> *current = head;
	for (int i = 0; i < length; i++)
	{
		if (current->data == t) { x = i + 1; return 1; }
		else current = current->node;
	}
	return 0;
}
template<class T>
void List<T>::reversedOutput() {
	T *t = new T[length];
	ListNode<T> *current = head;
	for (int i = 0; i < length; i++)
	{
		t[i] = current->data;
		current = current->node;
	}
	for (int i = length - 1; i >= 0; i--)
	{
		cout << t[i] << " ";
	}
}
template<class T>
void List<T>::Output(ostream& out) const
{
	ListNode<T> *current;
	current = head;
	for (int i = 0; i < length; i++) {
		out << current->data << " ";
		current = current->node;
	}
}

template <class T>
ostream& operator<<(ostream& out, const List<T>* x)
{
	x->Output(out); return out;
}
void Union() {
	int a;
	List<int> *list1 = new List<int>();
	List<int> *list2 = new List<int>();
	List<int> *list3 = new List<int>();
	cout << "请输入有序链表1元素个数：" << endl;
	cin >> a;
	cout << "请输入要插入的元素：" << endl;
	for (int i = 0; i < a; i++)
	{
		int k;
		cin >> k;
		list1->AddBack(k);
	}
	cout << "链表1的元素为：" << list1 << endl << endl;
	cout << "请输入有序链表2元素个数：" << endl;
	cin >> a;
	cout << "请输入要插入的元素：" << endl;
	for (int i = 0; i < a; i++)
	{
		int k;
		cin >> k;
		list2->AddBack(k);
	}
	cout << "链表2的元素为：" << list2 << endl << endl;
	ListNode<int> *cu1 = list1->head;
	ListNode<int> *cu2 = list2->head;
	while (cu1&&cu2)
	{
		if (cu1->data<=cu2->data)
		{
			list3->AddBack(cu1->data);
			cu1 = cu1->node;
		}
		else
		{
			list3->AddBack(cu2->data);
			cu2 = cu2->node;
		}
	}
	while (cu1) {
		list3->AddBack(cu1->data);
		cu1 = cu1->node;
	}
	while (cu2) {
		list3->AddBack(cu2->data);
		cu2 = cu2->node;
	}
	cout << "合并以后的链表为：";
	cout << list3 << endl << endl;
}
int main()
{
	List<int> *list = new List<int>();
	int n;
	cout << "请输入插入元素的个数：" << endl;
	cin >> n;
	cout << "请输入要插入元素：" << endl;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		list->AddBack(k);
	}
	cout << "链表的元素为：" << list << endl << endl;
	while (true) {
		int t;
		cout << "1.从表头插入元素					2.删除指定的元素（只删除第一次出现的）" << endl;
		cout << "3.搜索表中指定元素（记录第一次出现的位置）		4.输出链表" << endl;
		cout << "5.反序输出						6.创建两个有序链表实现合并（不去重）" << endl;
		cout << "0.退出" << endl;
		cout << "请选择执行的操作：" << endl;
		cin >> t;
		switch (t)
		{
		case 1:
			int k;
			cout << "输入要插入的元素：" << endl;
			cin >> k;
			list->AddHead(k);
			cout << "链表的元素为：" << list << endl << endl;
			break;
		case 2:
			int kk, kk1;
			cout << "输入要删除的元素：" << endl;
			cin >> kk;
			list->Delete(kk, kk1);
			if (kk1)
				cout << "链表的元素为：" << list << endl << endl;
			else
				cout << "不存在要删除的元素！" << endl << endl;
			break;
		case 3:
			int k2, k3;
			cout << "输入要搜索的元素：" << endl;
			cin >> k2;
			if (list->Search(k2, k3))
				cout << "搜索的元素位置为：" << k3 << endl << endl;
			else
				cout << "0" << endl << endl;
			break;
		case 4:
			cout << "链表的元素为：" << list << endl << endl;
			break;
		case 5:
			cout << "反向输出结果为：";
			list->reversedOutput();
			cout << endl << endl;
			break;
		case 6:
			Union();
			break;
		case 0:
			system("pause");
			return 0;
			break;
		default:
			cout << "请输入0~6的数字" << endl << endl;
			break;
		}
	}
}


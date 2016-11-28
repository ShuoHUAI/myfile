// List.cpp : �������̨Ӧ�ó������ڵ㡣
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
	cout << "��������������1Ԫ�ظ�����" << endl;
	cin >> a;
	cout << "������Ҫ�����Ԫ�أ�" << endl;
	for (int i = 0; i < a; i++)
	{
		int k;
		cin >> k;
		list1->AddBack(k);
	}
	cout << "����1��Ԫ��Ϊ��" << list1 << endl << endl;
	cout << "��������������2Ԫ�ظ�����" << endl;
	cin >> a;
	cout << "������Ҫ�����Ԫ�أ�" << endl;
	for (int i = 0; i < a; i++)
	{
		int k;
		cin >> k;
		list2->AddBack(k);
	}
	cout << "����2��Ԫ��Ϊ��" << list2 << endl << endl;
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
	cout << "�ϲ��Ժ������Ϊ��";
	cout << list3 << endl << endl;
}
int main()
{
	List<int> *list = new List<int>();
	int n;
	cout << "���������Ԫ�صĸ�����" << endl;
	cin >> n;
	cout << "������Ҫ����Ԫ�أ�" << endl;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		list->AddBack(k);
	}
	cout << "�����Ԫ��Ϊ��" << list << endl << endl;
	while (true) {
		int t;
		cout << "1.�ӱ�ͷ����Ԫ��					2.ɾ��ָ����Ԫ�أ�ֻɾ����һ�γ��ֵģ�" << endl;
		cout << "3.��������ָ��Ԫ�أ���¼��һ�γ��ֵ�λ�ã�		4.�������" << endl;
		cout << "5.�������						6.����������������ʵ�ֺϲ�����ȥ�أ�" << endl;
		cout << "0.�˳�" << endl;
		cout << "��ѡ��ִ�еĲ�����" << endl;
		cin >> t;
		switch (t)
		{
		case 1:
			int k;
			cout << "����Ҫ�����Ԫ�أ�" << endl;
			cin >> k;
			list->AddHead(k);
			cout << "�����Ԫ��Ϊ��" << list << endl << endl;
			break;
		case 2:
			int kk, kk1;
			cout << "����Ҫɾ����Ԫ�أ�" << endl;
			cin >> kk;
			list->Delete(kk, kk1);
			if (kk1)
				cout << "�����Ԫ��Ϊ��" << list << endl << endl;
			else
				cout << "������Ҫɾ����Ԫ�أ�" << endl << endl;
			break;
		case 3:
			int k2, k3;
			cout << "����Ҫ������Ԫ�أ�" << endl;
			cin >> k2;
			if (list->Search(k2, k3))
				cout << "������Ԫ��λ��Ϊ��" << k3 << endl << endl;
			else
				cout << "0" << endl << endl;
			break;
		case 4:
			cout << "�����Ԫ��Ϊ��" << list << endl << endl;
			break;
		case 5:
			cout << "����������Ϊ��";
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
			cout << "������0~6������" << endl << endl;
			break;
		}
	}
}


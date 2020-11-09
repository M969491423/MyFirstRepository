//#include <iostream>
//#define MAXSIZE 5
//using namespace std;
//struct MyStack
//{
//	int* base = NULL;
//	int* top;
//	int length;
//};
//
//struct MyQueue
//{
//	int data;
//	MyQueue* next;
//};
//
//struct MyQueue_Pointer
//{
//	MyQueue* front;
//	MyQueue* rear;
//};
//
//void Stack_init(MyStack& S) {
//	S.base = new int[MAXSIZE];
//	S.top = S.base;
//	S.length = 0;
//}
//
//void Stackt_push(MyStack& S, int data) {
//	if (!S.base) {
//		cout << "δ��ʼ��" << endl;
//	}else if (S.length >= MAXSIZE) {
//		cout << "�ѵ���ջ��" << endl;
//	}else {
//		*(S.top++) = data;
//		S.length++;
//	}
//}
//
//void Stack_pop(MyStack& S, int& data) {
//	if (!S.base) {
//		cout << "δ��ʼ��" << endl;
//	}else if (S.length <= 0) {
//		cout << "������" << endl;
//	}else {
//		data = *(--S.top);
//		S.length--;
//	}
//}
//
//void Stack_destroy(MyStack& S) {
//	if (!S.base) {
//		cout << "δ��ʼ��" << endl;
//	}
//	else {
//	delete[]S.base;
//	S.length = 0;
//	}
//}
//
//void Stack_display(MyStack s) {
//	int* temp = s.top;
//	while (temp != s.base) {
//		cout << *(--temp) << " ";
//	}
//	cout << endl;
//}
//
//void Stack_middle(MyStack& S, MyStack& middle) {
//	int m_data[2];
//	int data;
//	int index = S.length / 2;
//	int num = (S.length % 2) * -1 + 2;
//	if (num==2) {
//		index--;
//	}
//	for (int i = 0; i < index; i++) {
//		Stack_pop(S, data);
//		Stackt_push(middle, data);
//	}
//	ȡ���м�ֵ
//	for (int i = 0; i < num; i++) {
//		Stack_pop(S, data);
//		m_data[i] = data;
//	}
//	while (middle.top!=middle.base)
//	{
//		Stack_pop(middle, data);
//		Stackt_push(S, data);
//	}
//	for (int i = num-1; i>=0; i--) {
//		Stackt_push(middle, m_data[i]);
//	}
//}
//void Queue_init(MyQueue_Pointer& Q) {
//	Q.front = new MyQueue;
//	Q.front->next = NULL;
//	Q.rear = Q.front;
//}
//void Queue_push(MyQueue_Pointer & Q, int data) {
//	MyQueue* temp = new MyQueue;
//	temp->data = data;
//	temp->next = NULL;
//	Q.rear->next = temp;
//	Q.rear = temp;
//}
//void Queue_pop(MyQueue_Pointer& Q, int& data) {
//	if (Q.front == Q.rear) {
//		cout << "����Ϊ��" << endl;
//	}
//	else {
//		MyQueue* temp = Q.front->next;
//		if (Q.rear != Q.front) {
//			data = temp->data;
//			Q.front->next = temp->next;
//		}
//		if (Q.rear == temp) {
//			Q.rear = Q.front;
//		}
//		delete temp;
//
//	}
//}
//
//
//int main() {
//	MyQueue_Pointer Q;
//	MyStack s,middle;
//	Queue_init(Q);
//	Stack_init(s);
//	Stack_init(middle);
//	cout << "����ջ��Ԫ������Ϊ��" << endl;
//	for (int i = 0; i < MAXSIZE; i++) {
//		int data;
//		cin >> data;
//		Stackt_push(s, data);
//	}
//	int num = (s.length % 2) * -1 + 2;
//	cout << "ջ����ջ�׵�Ԫ������Ϊ��" << endl;
//	Stack_display(s);
//	cout << "��ջ��Ԫ��Ϊ��";
//	Stack_middle(s, middle);
//	Stack_display(middle);
//	cout << "����ջ�е�Ԫ��Ϊ��";
//	Stack_display(s);
//	cout << "������5�����ӵ�Ԫ�أ�" << endl;
//	for (int i = 0; i < 5; i++) {
//		int data;
//		cin >> data;
//		Queue_push(Q, data);
//	}
//	cout << "Ԫ�صĳ���Ϊ��" << endl;
//	for (int i = 0; i < 5; i++) {
//		int data;
//		Queue_pop(Q, data);
//		cout << data << " ";
//	}
//	cout << endl;
//	Stack_destroy(s);
//	Stack_destroy(middle);
//}
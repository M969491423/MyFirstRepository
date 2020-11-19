//#include <iostream>
//using namespace std;
//struct MyStack
//{
//	char ch;
//	MyStack* next;
//};
//void InitStack(MyStack*& s) {
//	s = NULL;
//}
//
//void Push(MyStack*& S, char c) {
//	MyStack* temp = new MyStack;
//	temp->ch = c;
//	temp->next = S;
//	S = temp;
//}
//
//void Pop(MyStack*& S, char& c) {
//	MyStack* temp = S;
//	c = S->ch;
//	S = temp->next;
//	delete temp;
//}
//
//char GetTop(MyStack*& S) {
//	return S->ch;
//}
//
//bool In(char c) {
//	switch (c)
//	{
//	case '+':
//	case '-':
//	case '*':
//	case '/':
//	case '(':
//	case ')':
//	case '#':
//		return true;
//	default:
//		return false;
//	}
//}
//
//char Precede(char t1, char t2) {
//	switch (t1) {
//	case '+':
//		if (t1 == t2 || t2 == '-' || t2 == ')' || t2 == '#') {
//			return '>';
//		}
//		else {
//			return '<';
//		}
//		break;
//	case '-':
//		if (t1 == t2 || t2 == '+' || t2 == ')' || t2 == '#') {
//			return '>';
//		}
//		else {
//			return '<';
//		}
//		break;
//	case '*':
//		if (t2 == '(') {
//			return '<';
//		}
//		else {
//			return '>';
//		}
//		break;
//	case '/':
//		if (t2 == '(') {
//			return '<';
//		}
//		else {
//			return '>';
//		}
//		break;
//	case '(':
//		if (t2 == ')') {
//			return '=';
//		}
//		else {
//			return '<';
//		}
//		break;
//	case ')':
//		return '>';
//		break;
//	case '#':
//		if (t2 == '#') {
//			return '#';
//		}
//		else {
//			return '<';
//		}
//		break;
//	default: return ' ';
//	}
//
//}
//int Operate(char a, char theta, char b) {
//	int c = 0;
//	int _a = a - 48;
//	int _b = b - 48;
//	switch (theta)
//	{
//	case '+':
//		 c=_a + _b;
//		 break;
//	case '-':
//		c = _a - _b;
//		break;
//	case '*':
//		c = _a * _b;
//		break;
//	case '/':
//		c = _a / _b;
//		break;
//	default:
//		break;
//	}
//	return c+48;
//}
//
//void display(MyStack* S) {
//	MyStack* temp = S;
//	while (temp)
//	{
//		cout << temp->ch << " ";
//		temp = temp->next;
//	}
//	cout << endl;
//}
//
//int EvaluateExpression() {
//	char c;
//	char x;
//	char a,b,theta;
//	MyStack *OPTR, *OPND;
//	InitStack(OPND);
//	InitStack(OPTR);
//	Push(OPTR, '#');
//	c = getchar();
//	while (c!='#'||GetTop(OPTR)!='#')
//	{
//		if (!In(c)) {
//			Push(OPND, c);
//			c = getchar();
//		}
//		else {
//			switch (Precede(GetTop(OPTR),c))
//			{
//			case '<':
//				Push(OPTR, c);
//				c = getchar();
//				break;
//			case '=':
//				Pop(OPTR, x);
//				c = getchar();
//				break;
//			case '>':
//				Pop(OPTR, theta);
//				Pop(OPND, b);
//				Pop(OPND, a);
//				Push(OPND, Operate(a, theta, b));
//				break;
//			default:
//				break;
//			}
//		}
//
//	}
//	return GetTop(OPND)-48;
//}
//
//int main() {
//	cout << EvaluateExpression() << endl;
//}

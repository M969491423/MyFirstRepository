#include<iostream>
#include <fstream>
using namespace std;

struct BTree
{
	char ch;
	int weight;
	int parent, lchild, rchild;
};

void display(BTree* B, int num) {
	cout << "num\tweight\tlchild\trchile\tparent\t" << endl;
	for (int i = 1; i <= num * 2 - 1; i++) {
		cout << B[i].ch << "\t" << B[i].weight << "\t" << B[i].lchild << "\t" << B[i].rchild << "\t" << B[i].parent << endl;
	}
}

void Select(BTree*& B, int index, int& s1, int& s2) {
	int min1 = 10000;
	int min2 = 10000;
	for (int i = 1; i <= index; i++) {
		if (B[i].parent == 0 && min1 > B[i].weight) {
			min1 = B[i].weight;
			s1 = i;
		}
	}

	for (int i = 1; i <= index; i++) {
		if (i != s1 && B[i].parent == 0) {
			if (B[i].weight < min2) {
				min2 = B[i].weight;
				s2 = i;
			}
		}
	}
}

void CreatHuffmanTree(BTree*& B, int n, int word[26]) {
	if (n <= 1) {
		return;
	}
	int m = 2 * n - 1;
	B = new BTree[m + 1];
	for (int i = 1; i <= m; i++) {
		B[i].parent = 0;
		B[i].lchild = 0;
		B[i].rchild = 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> B[i].weight;
	}

	for (int i = n + 1; i <= m; i++) {
		int s1, s2;
		Select(B, i - 1, s1, s2);
		B[s1].parent = i;
		B[s2].parent = i;
		B[i].lchild = s1;
		B[i].rchild = s2;
		B[i].weight = B[s1].weight + B[s2].weight;
	}
}

void delete_zero(int word[26], int& length) {
	for (int i = 0; i < length; i++) {
		if (word[i] == 0) {

		}
	}
}

void File_read(int word[26]) {
	for (int i = 0; i < 26; i++) {
		word[i] = 0;
	}
	ifstream inf;
	inf.open("d:\\source.txt");
	if (!inf) {
		cout << "打开文件失败" << endl;
		exit(0);
	}
	while (!inf.eof())
	{
		char data[100];
		inf >> data;
		for (int i = 0; i < 100; i++) {
			if (data[i] >= 'a' && data[i] <= 'z') {
				word[data[i] - 'a']++;
			}
			else if (data[i] >= 'A' && data[i] <= 'Z') {
				word[data[i] - 'A']++;
			}
		}
	}
	inf.close();
}

void CreatHuffmanCode(BTree* HT, char**& HC, int n) {
	HC = new  char* [n + 1];
	char* cd = new char[n];
	cd[n - 1] = '/0';
	for (int i = 1; i <= n; i++) {
		int start = n - 1;
		int c = i;
		int f = HT[i].parent;
		while (f != 0)
		{
			--start;
			if (HT[f].lchild == c)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = f;
			f = HT[f].parent;
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &cd[start]);
	}
	delete[]cd;
}

void display_Code(char** c, int length) {
	for (int i = 1; i <= length; i++) {
		cout << i << "  " << c[i] << endl;
	}
}

void File_Write(char** c) {
	ifstream fin;
	ofstream fout;
	fin.open("Source.txt");
	fout.open("Code.txt",ios::out);
	string str;
	fin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			fout << c[str[i] - 'a'+1];
		}
		else if (str[i] >= 'A' && str[i] <= 'Z') {
			fout << c[str[i] - 'A'+1];
		}
	}
	fin.close();
	fout.close();
}
int main() {
	BTree* B;
	char** c;
	int word[26];
	int length = 26;
	CreatHuffmanTree(B, 3, word);
	display(B, 3);
	CreatHuffmanCode(B, c, 3);
	display_Code(c, 3);
	File_Write(c);
}
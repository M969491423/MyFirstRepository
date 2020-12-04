#include <iostream>
#include <stdlib.h>
#define MAXINT 65535
#define MAXSIZE 100
using namespace std;
int visited[MAXSIZE]{0};
struct Queue
{
	char data;
	Queue *next;
};
struct Verge
{

	int node, weigth;
	Verge *next;
};
//邻接表表示法
struct Graph2
{
	char data;
	Verge *firstVerge;
};
//邻接矩阵表示法
struct Graph1
{
	int Adj[MAXSIZE][MAXSIZE];
	//顶点数
	int Nv;
	//边数
	int Ne;
	char data[MAXSIZE];
};

bool isEmpty(Queue *Q)
{
	if (Q == NULL)
	{
		return true;
	}
	return false;
}

Queue *createQueue()
{
	Queue *Q = new Queue;
	Q->next = NULL;
	return Q;
}

void push(Queue *&Q, char data)
{
	Queue *temp = new Queue;
	temp->data = data;
	temp->next = NULL;
	if (Q == NULL)
	{
		Q = temp;
		return;
	}
	Queue *p = Q;
	while (p->next)
	{
		p = p->next;
	}
	p->next = temp;
}

int pop(Queue *&Q)
{
	Queue *temp = Q;
	int data = temp->data;
	Q = Q->next;
	delete temp;
	return data;
}

void display(Queue *Q)
{
	Queue *temp = Q->next;
	while (temp->next)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

int LocationOfVertex(Graph1 G, char data)
{
	for (int i = 0; i < G.Nv; i++)
	{
		if (G.data[i] == data)
		{
			return i;
		}
	}
	return -1;
}

int LocationOfVertex(Graph2 *G, char data)
{
	for (int i = 0; i < G[i].data; i++)
	{
		if (G[i].data == data)
		{
			return i;
		}
	}
	return -1;
}

void InsertNode(Graph2 &G, int index, int weigth)
{
	Verge *p = G.firstVerge;
	Verge *temp = new Verge;
	temp->node = index;
	temp->weigth = weigth;
	temp->next = NULL;
	if (p == NULL)
	{
		G.firstVerge = temp;
	}
	else
	{
		while (p->next)
		{
			p = p->next;
		}
		p->next = temp;
	}
}

void CreateGraph2(Graph2 *&G, int &Vnum, int &Verge)
{
	cout << "输入顶点数和边数：";
	cin >> Vnum >> Verge;
	G = new Graph2[Vnum];
	for (int i = 0; i < Vnum; i++)
	{
		cout << "输入顶点数据: ";
		cin >> G[i].data;
		G[i].firstVerge = NULL;
	}
	cout << "无向图还是有向图(1 or 2):";
	int type;
	cin >> type;
	for (int i = 0; i < Verge; i++)
	{
		cout << "输入一个边的两个顶点和权值：";
		char a, b;
		int weight;
		cin >> a >> b >> weight;
		int l1 = LocationOfVertex(G, a);
		int l2 = LocationOfVertex(G, b);
		InsertNode(G[l1], l2, weight);
		if (type == 1)
		{
			InsertNode(G[l2], l1, weight);
		}
	}
}

void CreateGraph(Graph1 &G)
{
	cout << "输入顶点数和边数：";
	cin >> G.Nv >> G.Ne;
	cout << "输入顶点：";
	for (int i = 0; i < G.Nv; i++)
	{
		cin >> G.data[i];
	}
	for (int i = 0; i < G.Nv; i++)
	{
		for (int j = 0; j < G.Nv; j++)
		{
			G.Adj[i][j] = MAXINT;
		}
	}
	cout << "无向图还是有向图(1 or 2):";
	int type;
	cin >> type;
	for (int i = 0; i < G.Ne; i++)
	{
		cout << "输入一个边的两个顶点和权值：";
		int weight;
		char a, b;
		cin >> a >> b;
		cin >> weight;
		int l1 = LocationOfVertex(G, a);
		int l2 = LocationOfVertex(G, b);
		G.Adj[l1][l2] = weight;
		if (type == 1)
		{
			G.Adj[l2][l1] = weight;
		}
	}
}

void bfs(Graph1 G, int index)
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		visited[i] = 0;
	}
	Queue *Q = NULL;
	for (int i = 0; i < G.Nv; i++)
	{
		if (visited[i] == 0)
		{
			push(Q, G.data[i]);
			visited[i] = 1;
			while (!isEmpty(Q))
			{
				int t = pop(Q);
				cout << t << " ";
				for (int j = 0; j < G.Nv; j++)
				{
				}
			}
		}
	}
}

void dfs(Graph1 G, int index)
{
	visited[index] = 1;
	cout << G.data[index] << "  ";
	for (int i = 0; i < G.Nv; i++)
	{

		if (visited[i] != 1 && G.Adj[index][i] < MAXINT)
		{
			dfs(G, i);
		}
	}
}

void display(Graph1 G)
{
	cout << endl;
	for (int i = 0; i < G.Nv; i++)
	{
		cout << G.data[i] << "  ";
		for (int j = 0; j < G.Nv; j++)
		{
			cout << G.Adj[i][j] << " ";
		}
		cout << endl;
	}
}
void display(Graph2 *G, int Vnum)
{
	for (int i = 0; i < Vnum; i++)
	{
		Verge *p = G[i].firstVerge;
		cout << G[i].data << " ";
		while (p)
		{
			cout << "->" << p->node << "(" << p->weigth << ")";
			p = p->next;
		}
		cout << endl;
	}
}

int main()
{
	// Queue *Q = NULL;
	// //Queue* Q = createQueue();
	// for (int i = 0; i < 5; i++)
	// {
	// 	insertQueue(Q, i + 1);
	// }
	// for (int i = 0; i < 5; i++)
	// {
	// 	cout << pop(Q) << endl;
	// }
	Graph1 G;
	////Graph2* G2;
	//int Vnum, Ver;
	////CreateGraph2(G2, Vnum, Ver);
	CreateGraph(G);
	//display(G);
	////display(G2, Vnum);
	dfs(G, 0);
	system("pause");
}
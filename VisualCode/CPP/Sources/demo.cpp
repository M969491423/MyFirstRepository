#include <iostream>
#include <stdlib.h>
#define MAXINT 65535
#define MAXSIZE 100
using namespace std;
int visited[MAXSIZE]{0};
int D[MAXSIZE][MAXSIZE];
int Path[MAXSIZE][MAXSIZE];
struct Stack
{
	int data;
	Stack *next;
};
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

bool isEmpty(Stack *S)
{
	if (S == NULL)
	{
		return true;
	}
	return false;
}
void push(Stack *&S, int data)
{
	Stack *temp = new Stack;
	temp->data = data;
	temp->next = S;
	S = temp;
}

int pop(Stack *&S)
{
	Stack *temp = S;
	S = S->next;
	int data = temp->data;
	delete temp;
	return data;
}

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

void CreateGraph(Graph2 *&G, int &Vnum, int &Verge)
{
	cout << "输入顶点数和边数：";
	cin >> Vnum >> Verge;
	G = new Graph2[Vnum];
	cout << "输入顶点数据: ";
	for (int i = 0; i < Vnum; i++)
	{
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
//邻接表广度优先
void bfs(Graph2 *G, int vnum)
{
	for (size_t i = 0; i < vnum; i++)
	{
		visited[i] = 0;
	}
	Queue *Q = NULL;
	for (int i = 0; i < vnum; i++)
	{
		if (visited[i] == 0)
		{
			push(Q, G[i].data);
			visited[i] = 1;
			while (!isEmpty(Q))
			{
				char v = pop(Q);
				cout << v << " ";
				Verge *temp = G[i].firstVerge;
				while (temp)
				{
					if (visited[temp->node] == 0)
					{
						push(Q, G[temp->node].data);
						visited[temp->node] = 1;
						// cout << G[temp->node].data << " ";
					}
					temp = temp->next;
				}
			}
		}
	}
	cout << endl;
}
// 邻接矩阵广度优先
void bfs(Graph1 G)
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
				char v = pop(Q);
				int t = LocationOfVertex(G, v);
				cout << v << " ";
				for (int j = 0; j < G.Nv; j++)
				{
					if (G.Adj[t][j] < MAXINT && visited[j] != 1)
					{
						push(Q, G.data[j]);
						visited[j] = 1;
					}
				}
			}
		}
	}
	cout << endl;
}
//邻接表深度优先
void dfs(Graph2 *G, int Vnum, int index)
{
	for (int i = 0; i < Vnum; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			cout << G[i].data << " ";
			Verge *temp = G[i].firstVerge;
			while (temp)
			{
				if (visited[temp->node] == 0)
				{
					dfs(G, Vnum, temp->node);
				}
				temp = temp->next;
			}
		}
	}
}

// 邻接矩阵深度优先
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

void destory(Stack *&S)
{
	Stack *temp = S;
	while (temp)
	{
		S = S->next;
		delete temp;
		temp = S;
	}
}

void destory(Graph2 *&G, int Vnum)
{
	for (int i = 0; i < Vnum; i++)
	{
		Verge *temp = G[i].firstVerge;
		while (temp)
		{
			Verge *temp1 = temp;
			temp = temp->next;
			delete temp1;
		}
		G[i].firstVerge = NULL;
	}
}
//输出邻接矩阵
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
// 输出邻接表
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
// 获取两点之间的路径
int getWeight(Graph2 *G, int index, int node)
{
	Verge *temp = G[index].firstVerge;
	while (temp)
	{
		if (temp->node == node)
		{
			return temp->weigth;
		}
		temp = temp->next;
	}
	return MAXINT;
}
// 弗洛伊德算法-邻接表
void ShortestPath_Folyd(Graph2 *G, int Vnum)
{
	for (size_t i = 0; i < Vnum; i++)
	{
		for (size_t j = 0; j < Vnum; j++)
		{
			if (i == j)
			{
				D[i][j] = 0;
			}
			else
			{
				D[i][j] = getWeight(G, i, j);
			}
			if (D[i][j] < MAXINT)
			{
				Path[i][j] = i;
			}
			else
			{
				Path[i][j] = -1;
			}
		}
	}

	for (int k = 0; k < Vnum; k++)
	{
		for (int i = 0; i < Vnum; i++)
		{
			for (int j = 0; j < Vnum; j++)
			{
				int temp = (D[i][k] == MAXINT || D[k][j] == MAXINT) ? MAXINT : D[i][k] + D[k][j];
				if (temp < D[i][j])
				{
					D[i][j] = temp;
					Path[i][j] = Path[k][j];
				}
			}
		}
	}
}
// 弗洛伊德算法-邻接矩阵
void ShortestPath_Folyd(Graph1 G)
{
	// 构造临时的权值数组和节点数组
	for (size_t i = 0; i < G.Nv; i++)
	{
		for (size_t j = 0; j < G.Nv; j++)
		{
			D[i][j] = G.Adj[i][j];
			if (D[i][j] < MAXINT && i != j)
			{
				Path[i][j] = i;
			}
			else
			{
				Path[i][j] = -1;
			}
		}
	}

	for (int k = 0; k < G.Nv; k++)
	{
		for (int i = 0; i < G.Nv; i++)
		{
			for (size_t j = 0; j < G.Nv; j++)
			{
				// 如果存在一个中间节点使V0，V1，V2的路径长度小于V0，V2的路径长度则将其（V1）加入到Path并更新V0-V2的路径长度（保证路径长度最小）
				if (D[i][k] + D[k][j] < D[i][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					Path[i][j] = Path[k][j];
				}
			}
		}
	}
}
// 输出邻接矩阵迪杰斯特拉算法的最短路径
void display(Graph1 G, int *path, int index)
{
	Stack *S = NULL;
	while (index != -1)
	{
		push(S, index);
		index = path[index];
	}
	while (!isEmpty(S))
	{
		cout << G.data[pop(S)] << " ";
	}
	cout << "\n";
}

// 输出邻接矩阵弗洛伊德算法的最短路径
void display(Graph1 G, int begin, int end)
{
	if (begin == Path[begin][end])
	{
		cout << G.data[begin] << " " << G.data[end] << " ";
	}
	else
	{
		display(G, begin, Path[begin][end]);
		cout << G.data[end] << " ";
	}
}
// 输出邻接表的迪杰斯特拉算法的结果
void display(Graph2 *G, int *path, int index)
{
	Stack *S = NULL;
	while (index != -1)
	{
		push(S, index);
		index = path[index];
	}
	while (!isEmpty(S))
	{
		cout << G[pop(S)].data << " ";
	}
	cout << endl;
}

void display(Graph2 *G, int begin, int end)
{
	if (begin == Path[begin][end])
	{
		cout << G[begin].data << " " << G[end].data << " ";
	}
	else
	{
		display(G, begin, Path[begin][end]);
		cout << G[end].data << " ";
	}
}

//迪杰斯特拉算法-邻接表
int *ShortestPath_DIJ(Graph2 *G, int Vnum, int V0)
{
	//判断此点是否访问
	bool *S = new bool[Vnum];
	// 储存此点权值
	int *V = new int[Vnum];
	// 储存路径下标
	int *Path = new int[Vnum];
	for (int i = 0; i < Vnum; i++)
	{
		S[i] = false;
		V[i] = getWeight(G, V0, i);
		if (V[i] < MAXINT)
		{
			Path[i] = V0;
		}
		else
		{
			Path[i] = -1;
		}
	}
	S[V0] = true;
	V[V0] = 0;
	// 完成初始化
	int v = 0;
	for (int i = 0; i < Vnum; i++)
	{
		int min = MAXINT;
		for (int w = 0; w < Vnum; w++)
		{
			if (!S[w] && V[w] < min)
			{
				min = V[w];
				v = w;
			}
		}
		S[v] = true;
		Verge *temp = G[v].firstVerge;
		while (temp)
		{
			if (!S[temp->node] && (V[v] + temp->node < V[temp->node]))
			{
				V[temp->node] = V[v] + temp->node;
				Path[temp->node] = v;
			}
			temp = temp->next;
		}
	}
	return Path;
	// for (int i = 0; i < Vnum; i++)
	// {
	// 	cout << Path[i] << " ";
	// }
	// cout << endl;
}
//迪杰斯特拉算法-邻接矩阵
int *ShortestPath_DIJ(Graph1 G, int V0)
{
	//使用Dijkstra算法求有向网G的V0顶点到其余顶点的最短路径
	int n = G.Nv;
	//判断此点是否访问
	bool *S = new bool[n];
	// 储存此点权值
	int *V = new int[n];
	// 储存路径下标
	int *Path = new int[n];
	for (int i = 0; i < n; i++)
	{
		S[i] = false;
		V[i] = G.Adj[V0][i];
		if (V[i] < MAXINT)
		{
			Path[i] = V0;
		}
		else
		{
			Path[i] = -1;
		}
	}
	S[V0] = true;
	V[V0] = 0;
	//初始化完毕
	int v = 0;
	for (int i = 1; i < n; i++)
	{
		//获取V0到最短权值的点v
		int min = MAXINT;
		for (int w = 0; w < n; w++)
		{
			// 该点未访问且权值小于min（min值每次进入新的循环都会赋值为MAXINT）
			// 每次v的值都是非访问过的点中权值最小的点
			if (!S[w] && V[w] < min)
			{
				v = w;
				min = V[w];
			}
		}
		S[v] = true;
		// 判断是否存在另一个未访问过的点V1使V0通过V可以访问到V1且权值之间的关系满足weight(V0,V)+weight(V,V1)<weight(V0,V1)
		//存在则在Path[V1]存放V的值（可以借助V1（即终点）连续访问整个路线）
		for (int w = 0; w < n; w++)
		{

			if (!S[w] && (V[v] + G.Adj[v][w] < V[w]))
			{
				// 对V[w]赋值为V[v] + G.Adj[v][w]，用来查找最短的V1
				V[w] = V[v] + G.Adj[v][w];
				Path[w] = v;
			}
		}
	}
	return Path;
}

int main()
{
	cout << "--------------邻接矩阵表示法---------------------\n";
	Stack *S = NULL;
	Graph1 G;
	cout << "邻接矩阵表示法：" << endl;
	CreateGraph(G);
	cout << "邻接矩阵深度优先：" << endl;
	dfs(G, 0);
	cout << endl;
	cout << "邻接矩阵广度优先：" << endl;
	bfs(G);
	cout << "迪杰斯特拉算法: " << endl;
	int *Path1 = ShortestPath_DIJ(G, 0);
	display(G, Path1, G.Nv - 1);
	cout << endl;
	cout << "弗洛伊德算法：" << endl;
	ShortestPath_Folyd(G);
	display(G, 0, G.Nv - 1);
	cout << "\n";
	cout << "Path表：\n";
	for (int i = 0; i < G.Nv; i++)
	{
		for (int j = 0; j < G.Nv; j++)
		{
			cout << Path[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "权值表：\n";
	for (int i = 0; i < G.Nv; i++)
	{
		for (int j = 0; j < G.Nv; j++)
		{
			cout << D[i][j] << "\t";
		}
		cout << endl;
	}
	/*--------------邻接表表示法---------------------*/
	cout << "--------------邻接表表示法---------------------\n";
	Graph2 *G2;
	int Vnum, Ver;
	cout << "邻接表表示法：" << endl;
	CreateGraph(G2, Vnum, Ver);
	cout << "弗洛伊德算法：" << endl;
	display(G2, ShortestPath_DIJ(G2, Vnum, 0), Vnum - 1);
	cout << "迪杰斯特拉算法: " << endl;
	ShortestPath_Folyd(G2, Vnum);
	display(G2, 0, Vnum - 1);
	cout << "\n";
	cout << "Path表：\n";
	for (int i = 0; i < G.Nv; i++)
	{
		for (int j = 0; j < G.Nv; j++)
		{
			cout << Path[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "权值表：\n";
	for (int i = 0; i < G.Nv; i++)
	{
		for (int j = 0; j < G.Nv; j++)
		{
			cout << D[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "邻接表广度优先：" << endl;
	bfs(G2, Vnum);
	for (int i = 0; i < MAXSIZE; i++)
		visited[i] = 0;
	cout << "邻接表深度优先: " << endl;
	dfs(G2, Vnum, 0);
	cout << endl;
	system("pause");
}
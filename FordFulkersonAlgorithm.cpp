#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

vector< vector<int> > CreateMatrix()
{
	vector< vector<int> > Matrix;
	const int n = 4;
	int A[n][n] = {
	{0,1,0,0},
	{1,0,1,0},
	{0,1,0,1},
	{0,0,1,0} };

	for (int i = 0; i < n; i++)
	{
		vector<int> row;
		Matrix.push_back(row);
		for (int j = 0; j < n; j++)
		{
			Matrix[i].push_back(0);
			Matrix[i][j] = A[i][j];
		}
	}
	return Matrix;
}

bool BreadthFirstSearch(vector< vector<int> > &rMatrix, int &s, int &k, vector<int> &parent)
{
	const int n = 4;
	bool passed[n] = { false };

	queue<int> q;
	q.push(s);
	passed[s] = true;
	parent[s] = -1;

	while (q.empty() == false)
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < n; i++)
		{
			int v = i;
			int cap = rMatrix[u][v];
			if (passed[v] == false && cap > 0)
			{
				q.push(v);
				parent[v] = u;
				passed[v] = true;
			}
		}
	}
	if (passed[k] == true)
	{
		return true;
	}

	return false;
}

int algoritm(vector< vector<int> > &Matrix, int &s, int &k)
{
	int max_flow = 0;
	vector< vector<int> > rMatrix;
	int n = Matrix.size();
	for (int i = 0; i < n; i++)
	{
		vector<int> row;
		rMatrix.push_back(row);
		for (int j = 0; j < Matrix[i].size(); j++)
		{
			rMatrix[i].push_back(Matrix[i][j]);
		}
	}
	vector<int> parent;
	for (int i = 0; i < n; i++)
	{
		parent.push_back(-1);
	}
	while (BreadthFirstSearch(rMatrix, s, k, parent) == true)
	{
		int path_flow = INT_MAX;

		int v = k;
		while (v != s)
		{
			int u = parent[v];
			int cap = rMatrix[u][v];
			path_flow = min(path_flow, cap);
			v = u;
		}

		v = k;
		while (v != s)
		{
			int u = parent[v]; 
			rMatrix[u][v] -= path_flow;
			rMatrix[v][u] += path_flow;
			v = u;
		}
		max_flow += path_flow;
	}

	return max_flow;
}

int main(){
	vector< vector<int> > Matrix = CreateMatrix();
	int s = 0;
	int k = 4;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int s = i;
			int k = j;

			if (i == j) { continue; }

			cout << "The max flow is " << algoritm(Matrix, s, k) << endl;
		}
	}
	system("pause");
	return 0;

}
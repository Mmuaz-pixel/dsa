#include <iostream>
#include <stack>
using namespace std;

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {
	{0, 1, 1, 1, 0, 0, 0},
	{1, 0, 0, 1, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 0},
	{1, 0, 1, 0, 1, 0, 0},
	{0, 0, 1, 1, 0, 1, 1},
	{0, 0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 1, 0, 0}};

void DFS(int i)
{
	cout << i << " ";
	visited[i] = 1;
	for (int j = 0; j < 7; j++)
	{
		if (a[i][j] == 1 && visited[j] == 0)
		{
			DFS(j);
		}
	}
}

int main()
{
	DFS(3); // here 3 is the starting node
	return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

#define VERTS 5
#define HIGH 99999

int alreadyVisitedVertex(int vertex, int[]);

int main()
{
	int visited_vertices[VERTS];
	memset(visited_vertices, false, sizeof(visited_vertices));

	int graph[VERTS][VERTS] =
		{
			{0, 4, 0, 5, 2},
			{4, 0, 1, 3, 0},
			{0, 1, 0, 8, 0},
			{5, 3, 8, 0, 2},
			{2, 0, 0, 2, 0},
		};

	int mst[VERTS][VERTS];
	int mst_total_weight = 0;
	memset(mst, false, sizeof(mst));

	int no_of_edges = 0;
	int current_vertex = 0;
	while (no_of_edges != VERTS - 1)
	{
		int min = HIGH;
		int current_column = 0;
		visited_vertices[no_of_edges] = current_vertex;
		for (int j = 0; j < VERTS; j++)
		{
			if (graph[current_vertex][j] != 0)
			{
				if (graph[current_vertex][j] < min)
				{
					if (alreadyVisitedVertex(j, visited_vertices))
					{
						continue;
					}
					min = graph[current_vertex][j];
					current_column = j;
				}
			}
		}
		mst[current_vertex][current_column] = min;
		current_vertex = current_column;
		no_of_edges++;
	}

	// Print MST
	cout << "Edges: Weights" << endl;
	for (int i = 0; i < VERTS; i++)
	{
		for (int j = 0; j < VERTS; j++)
		{
			if (mst[i][j] != 0)
			{
				cout << i << "-" << j << ":" << mst[i][j] << endl;
				mst_total_weight += mst[i][j];
			}
		}
	}

	cout << mst_total_weight << endl;

	std::cin.get();
	return 0;
}

int alreadyVisitedVertex(int vertex, int vertex_list[])
{
	for (int i = 0; i < VERTS; i++)
	{
		if (vertex_list[i] == vertex)
		{
			return 1;
		}
	}
	return 0;
}
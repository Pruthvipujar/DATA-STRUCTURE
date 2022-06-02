#include <stdio.h>
#define V 4
#define INF 999
void floydWarshall(int graph[][V])
{
  int matrix[V][V], i, j, k;
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      matrix[i][j] = graph[i][j];
  for (k = 0; k < V; k++)
  {
    for (i = 0; i < V; i++)
    {
      for (j = 0; j < V; j++)
      {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix);
}

void printMatrix(int matrix[][V])
{
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      if (matrix[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int graph[V][V] = {{0, 4, INF, 10},
               {9, 0, 3, INF},
             {6, INF, 0, 2},
             {3, INF, INF, 0}};
  floydWarshall(graph);
}

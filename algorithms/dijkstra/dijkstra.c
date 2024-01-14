#include <stdio.h>
#include <limits.h>

#define GRAPH_SIZE 5

int dijkstraShortestPath(int graph[GRAPH_SIZE][GRAPH_SIZE], int indexA, int indexB);
void setDistanceInfinites(int arr[GRAPH_SIZE]);

int main()
{
    int graph[GRAPH_SIZE][GRAPH_SIZE] = {{0, 4, 5, 18, 0},
                                         {4, 0, 2, 0, 0},
                                         {5, 2, 0, 11, 0},
                                         {18, 0, 11, 0, 0},
                                         {0, 1, 0, 0, 0}};
    printf("Works %d\n", dijkstraShortestPath(graph, 0, 4));

    return 0;
}

int dijkstraShortestPath(int graph[GRAPH_SIZE][GRAPH_SIZE], int indexA, int indexB)
{
    int visited[GRAPH_SIZE] = {};
    int distanceFromA[GRAPH_SIZE] = {};

    for (int i = 0; i < GRAPH_SIZE; i++)
    {
        visited[i] = 1;
    }

    setDistanceInfinites(distanceFromA);
    distanceFromA[indexA] = 0;

    int nextToCheckVerticies[GRAPH_SIZE] = {indexA};
    int verticiesLeft = 0;

    int tries = 0;

    while (verticiesLeft != 1 && tries < 20)
    {
        tries += 1;
        int nextToCheckVerticiesUpdate[GRAPH_SIZE] = {};
        verticiesLeft = 1;

        for (int i = 0; i < GRAPH_SIZE; i++)
        {
            if (nextToCheckVerticies[i] == -1)
            {
                continue;
            }

            int *parentVertex = graph[i];
            int parentVertexDistance = distanceFromA[i];

            for (int i1 = 0; i1 < GRAPH_SIZE; i1++)
            {
                nextToCheckVerticiesUpdate[i1] = -1;
                int vertexNeighborDistance = parentVertexDistance + graph[i1][i];
                if (visited[i1] == 0 || graph[i1][i] == 0 || distanceFromA[i1] < vertexNeighborDistance)
                {
                    continue;
                }

                distanceFromA[i1] = vertexNeighborDistance;

                if (visited[i1] == 1)
                {
                    nextToCheckVerticiesUpdate[i1] = i1;
                    verticiesLeft = 0;
                }
            }

            visited[i] = 0;
        }

        for (int i1 = 0; i1 < GRAPH_SIZE; i1++)
        {
            nextToCheckVerticies[i1] = nextToCheckVerticiesUpdate[i1];
        }
    }

    return distanceFromA[indexB];
}

void setDistanceInfinites(int arr[GRAPH_SIZE])
{
    for (int i = 0; i < GRAPH_SIZE; i++)
    {
        arr[i] = INT_MAX;
    }
}

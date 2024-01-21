#include <stdio.h>
#include <limits.h>
#include <time.h>

#define GRAPH_SIZE 5

const int TRUE = 1;
const int FALSE = 0;

int dijkstraShortestPath(int graph[GRAPH_SIZE][GRAPH_SIZE], int indexA, int indexB);
void dijkstraShortestPathUpdate(int graph[GRAPH_SIZE][GRAPH_SIZE], int *distancesFromA, int *verticiesToCheck, int *visited);
void fillArrayWithIntegers(int arr[GRAPH_SIZE], int value);
void dijkstraPerformanceTest(long iterations, int graph[GRAPH_SIZE][GRAPH_SIZE]);

int main()
{
    int graph[GRAPH_SIZE][GRAPH_SIZE] = {{0, 4, 1, 11, 4},
                                         {4, 0, 2, 0, 0},
                                         {1, 2, 0, 0, 1},
                                         {11, 0, 0, 0, 1},
                                         {4, 0, 1, 2, 0}};
    printf("The shortest path is: %d\n", dijkstraShortestPath(graph, 0, 3));
    dijkstraPerformanceTest(50000000, graph);
    return 0;
}

void dijkstraPerformanceTest(long iterations, int graph[GRAPH_SIZE][GRAPH_SIZE])
{
    clock_t starttime, endtime;
    starttime = clock();
    for (int i = 0; i < iterations; i++)
    {
        dijkstraShortestPath(graph, 0, 4);
    }
    endtime = clock();
    printf("Performance test passing time: %ld\n", (long)(endtime - starttime));
}

int dijkstraShortestPath(int graph[GRAPH_SIZE][GRAPH_SIZE], int indexA, int indexB)
{
    int visited[GRAPH_SIZE] = {[0 ... GRAPH_SIZE - 1] = FALSE};
    int distancesFromA[GRAPH_SIZE] = {[0 ... GRAPH_SIZE - 1] = INT_MAX};

    int verticiesToCheck[GRAPH_SIZE] = {[0 ... GRAPH_SIZE - 1] = -1};

    verticiesToCheck[indexA] = indexA;
    distancesFromA[indexA] = 0;

    dijkstraShortestPathUpdate(graph, distancesFromA, verticiesToCheck, visited);

    return distancesFromA[indexB];
}

void dijkstraShortestPathUpdate(int graph[GRAPH_SIZE][GRAPH_SIZE], int *distancesFromA, int *verticiesToCheck, int *visited)
{
    int nextVerticiesToCheck[GRAPH_SIZE] = {[0 ... GRAPH_SIZE - 1] = -1};
    int verticiesToCheckLeft = FALSE;

    for (int i = 0; i < GRAPH_SIZE; i++)
    {
        if (verticiesToCheck[i] == -1)
        {
            // Skip the vertex
            continue;
        }

        int currentDistanceToParent = distancesFromA[verticiesToCheck[i]];
        int distanceFromVertexToParent = graph[i][verticiesToCheck[i]];

        int currentDistanceToVertex = distancesFromA[i];
        int newVertexDistance = currentDistanceToParent + distanceFromVertexToParent;

        if (currentDistanceToVertex > newVertexDistance || currentDistanceToParent == 0)
        {
            distancesFromA[i] = newVertexDistance;
        }

        for (int i1 = 0; i1 < GRAPH_SIZE; i1++)
        {
            if (visited[i1] == TRUE || graph[i][i1] == 0 || i1 == i)
            {
                continue;
            }
            nextVerticiesToCheck[i1] = i;
            verticiesToCheckLeft = TRUE;
        }

        visited[i] = TRUE;
    }

    if (verticiesToCheckLeft)
    {
        dijkstraShortestPathUpdate(graph, distancesFromA, nextVerticiesToCheck, visited);
    }
}

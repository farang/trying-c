#include <stdio.h>
#include <limits.h>
#include <time.h>

#define GRAPH_SIZE 5

const int TRUE = 1;
const int FALSE = 0;

int dijkstraShortestPath(int graph[GRAPH_SIZE][GRAPH_SIZE], int indexA, int indexB);
void fillArrayWithIntegers(int arr[GRAPH_SIZE], int value);
void dijkstraPerformanceTest(long iterations, int graph[GRAPH_SIZE][GRAPH_SIZE]);

int main()
{
    int graph[GRAPH_SIZE][GRAPH_SIZE] = {{0, 4, 5, 18, 0},
                                         {4, 0, 2, 3, 0},
                                         {5, 2, 0, 11, 0},
                                         {18, 0, 11, 0, 0},
                                         {0, 3, 0, 0, 0}};
    printf("The shortest path is: %d\n", dijkstraShortestPath(graph, 0, 4));
    dijkstraPerformanceTest(50000000, graph);
    return 0;
}

void dijkstraPerformanceTest(long iterations, int graph[GRAPH_SIZE][GRAPH_SIZE])
{
    clock_t starttime, endtime;
    starttime = clock();
    for (int i = 0; i <= iterations; i++)
    {
        dijkstraShortestPath(graph, 0, 4);
    }
    endtime = clock();
    printf("Performance test passing time: %ld\n", (long)(endtime - starttime));
}

int dijkstraShortestPath(int graph[GRAPH_SIZE][GRAPH_SIZE], int indexA, int indexB)
{
    int visited[GRAPH_SIZE] = {[0 ... GRAPH_SIZE - 1] = FALSE};
    int distanceFromA[GRAPH_SIZE] = {[0 ... GRAPH_SIZE - 1] = INT_MAX};

    distanceFromA[indexA] = 0;

    int nextToCheckVerticies[GRAPH_SIZE] = {indexA};
    int verticiesLeft = TRUE;

    while (verticiesLeft)
    {
        int nextToCheckVerticiesUpdate[GRAPH_SIZE] = {};
        verticiesLeft = FALSE;

        for (int i = 0; i < GRAPH_SIZE; i++)
        {
            if (nextToCheckVerticies[i] == -1)
            {
                continue;
            }

            for (int i1 = 0; i1 < GRAPH_SIZE; i1++)
            {
                int vertexNeighborDistance = distanceFromA[i] + graph[i1][i];
                if (visited[i1] == TRUE ||
                    graph[i1][i] == 0 ||
                    distanceFromA[i1] < vertexNeighborDistance ||
                    i == i1)
                {
                    nextToCheckVerticiesUpdate[i1] = -1;
                    continue;
                }

                distanceFromA[i1] = vertexNeighborDistance;

                if (visited[i1] == 1)
                {
                    nextToCheckVerticiesUpdate[i1] = i1;
                    verticiesLeft = TRUE;
                }
            }

            visited[i] = TRUE;
        }

        for (int i1 = 0; i1 < GRAPH_SIZE; i1++)
        {
            nextToCheckVerticies[i1] = nextToCheckVerticiesUpdate[i1];
        }
    }

    return distanceFromA[indexB];
}

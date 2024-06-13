#include "stdio.h"
struct edges
{
    int v1, v2, w;
} a[10];
struct Finaledges
{
    int v1, v2, w;
} b[10];
int main()
{
    int e = 0, c = 0, c1 = 0, temp = 0, k = 0, sv = 0, dv = 0, edge = 0;
    char i, j;
    int edges[10][10];
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter Source vertex, Destination vertex and Weight of an egde between that vertex: ");
    for (j = 0; j < e; j++)
    {
        scanf("%d %d %d", &sv, &dv, &edge);
        a[j].v1 = sv;
        a[j].v2 = dv;
        a[j].w = edge;
        edges[sv][dv] = edge;
    }

    printf("\n\n%d\n", edges[sv][dv]);

    for (i = 0; i < e; i++)
    {
        for (j = i + 1; j < e; j++)
        {
            if (a[i].w > a[j].w)
            {
                temp = a[i].w;
                a[i].w = a[j].w;
                a[j].w = temp;
            }
        }
    }
    // for (i = 0; i < e; i++)
    // {
    //     printf("\n%d", a[i].w);
    // }

    for (i = 0; i < e; i++)
    {
        for (j = i + 1; j < e; j++)
        {
            while(a[i].v2 < a[j].v1)
        }
    }

    // for (i = 0; i < e; i++)
    // {
    //     i = j;
    //     printf("\ni=%d ", i);
    //     for (j = 0; j < e; j++)
    //     {
    //         if (a[j].temp < edges[c][c1])
    //         {
    //             a[j].temp = edges[c][c1];
    //             a[j].v1 = c;
    //             a[j].v2 = c1;
    //         }
    //         c1++;
    //     }
    //     c++;
    // }

    return 0;
}
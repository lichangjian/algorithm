#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int value[505];
int need[505];
int best[100005];

int max(int a, int b);

int main(void)
{
    int n, m, i, j, w;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        memset(best, 0, sizeof(best));

        for(i = 1; i <= n; i++)
            scanf("%d %d", &need[i], &value[i]);

        for(j = 1; j <= n; j++)
        {
            for(w = need[j]; w <= m; w++)
                best[w] = max(best[w], best[w - need[j]] + value[j]);
        }

        printf("%d\n", best[m]);   
    }
    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}
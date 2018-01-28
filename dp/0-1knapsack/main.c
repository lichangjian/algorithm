#include <stdio.h>
#include <malloc.h>
#include <string.h>

int need[505];
int value[505];
int best[100005];

int max(int a, int b);

int main(void)
{
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d %d", &need[i], &value[i]);
        
        memset(best, 0, sizeof(best));
        for(int j = 1; j <= n; j++)
            for(int w = m; w >= need[j]; w--)
                best[w] = max(best[w], best[w - need[j]] + value[j]);
        printf("%d", best[m]);
    }
    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}
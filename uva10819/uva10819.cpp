#include <stdio.h>
#include <string.h>

#define MAX(a, b) (a > b ? a : b)
#define N 105

int c[N * 150], p[N + N], v[N + N];

int main()
{
    int n, budget, ans;
    while(~scanf("%d %d", &budget, &n))
    {
        for(int i = 1; i <= n; i++)
            scanf("%d %d", &p[i], &v[i]);
        
        memset(c, 0, sizeof(c));
        
        for(int i = 1; i <= n; i++)
        for(int j = 10200; j >= p[i]; j--)
        {
            if(j == p[i]) c[j] = MAX(c[j], c[j - p[i]] + v[i]);
            else if(j > p[i] && c[j - p[i]]) c[j] = MAX(c[j], c[j - p[i]] + v[i]);
        }
        ans = 0;
        for(int i = 0; i < 10201; i++)
        {
            if((i > 2000 && i <= budget + 200) || i <= budget)
            {
                ans = ans > c[i] ? ans : c[i];
            }
        }
        printf("%d\n", ans);
    }
    return 0; 
}

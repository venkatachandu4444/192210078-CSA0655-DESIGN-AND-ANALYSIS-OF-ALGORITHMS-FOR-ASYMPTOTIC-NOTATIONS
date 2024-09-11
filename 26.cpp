#include <stdio.h>

#define INF 9999999
#define N 100

int tsp(int graph[][N], int pos, int visited, int n, int dp[][1 << N]) {
    if (visited == (1 << n) - 1)
        return graph[pos][0];

    if (dp[pos][visited] != -1)
        return dp[pos][visited];

    int ans = INF;
    for (int city = 0; city < n; city++) {
        if ((visited & (1 << city)) == 0)
            ans = (ans < graph[pos][city] + tsp(graph, city, visited | (1 << city), n, dp)) ? ans : graph[pos][city] + tsp(graph, city, visited | (1 << city), n, dp);
    }

    return dp[pos][visited] = ans;
}

int main() {
    int n;

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    int graph[N][N], dp[N][1 << N];

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < (1 << n); j++)
            dp[i][j] = -1;

    printf("Minimum cost is %d\n", tsp(graph, 0, 1, n, dp));

    return 0;
}

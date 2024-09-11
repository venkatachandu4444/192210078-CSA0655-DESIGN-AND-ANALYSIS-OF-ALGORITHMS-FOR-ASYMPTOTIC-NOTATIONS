#include <stdio.h>
#include <limits.h>

int optimalBST(int keys[], int freq[], int n) {
    int cost[n][n];

    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += freq[k];

            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r-1] : 0) + 
                        ((r < j) ? cost[r+1][j] : 0) + sum;
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    return cost[0][n-1];
}

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n], freq[n];

    printf("Enter the keys and their frequencies:\n");
    for (int i = 0; i < n; i++) {
        printf("Key %d: ", i+1);
        scanf("%d", &keys[i]);
        printf("Frequency of key %d: ", i+1);
        scanf("%d", &freq[i]);
    }

    printf("Cost of Optimal BST is %d\n", optimalBST(keys, freq, n));

    return 0;
}

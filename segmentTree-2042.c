#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long *arr, *tree, *ans;
int n, m, k;

long long make(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    long long left = make(node*2, start, mid);
    long long right = make(node*2+1, mid+1, end);
    tree[node] = left + right;
    return tree[node];
}

void update(int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(node*2, start, mid, index, diff);
        update(node*2+1, mid+1, end, index, diff);
    }
}

long long sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(node*2, start, mid, left, right) + sum (node*2+1, mid+1, end, left, right);
}

int main(void) {
    scanf("%d %d %d", &n, &m, &k);
    arr = malloc(sizeof(long long)*(n+1));
    for (int i=1; i<=n; i++) {
        scanf("%lld", &arr[i]);
    }

    int height = (int)ceil(log2(n));
    int tree_size = 1 << (height+1);
    tree = malloc(sizeof(long long)*(tree_size));
    make(1, 1, n);

    int a, b, c;
    int size = k;
    ans = malloc(sizeof(long long)*(size+1));
    for (int i=1; i<=m+k; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1) {
            long long diff = c - arr[b];
            arr[b] = c;
            update(1, 1, n, b, diff);
        } else {
            ans[size--] = sum(1, 1, n, b, c);
        }
    }

    for (int i=k; i>=1; i--) {
        printf("%lld\n", ans[i]);
    }

    free(arr);
    free(tree);
    free(ans);
    return 0;
}

// gcc segmentTree-2042.c -o segmentTree-2042 -lm

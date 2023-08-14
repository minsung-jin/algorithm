#include <stdio.h>
#include <stdlib.h>

#define MAX_N 75001

int tree[MAX_N * 4];
struct Pair {
    int first;
    int second;
};
struct Pair vec[MAX_N];
int y_vec[MAX_N];

void init_tree(int now, int start, int end) {
    if (start > end) return;
    if (start == end) {
        tree[now] = 0;
        return;
    }
    tree[now] = 0;
    int mid = (start + end) / 2;
    init_tree(now * 2, start, mid);
    init_tree(now * 2 + 1, mid + 1, end);
}

void update_tree(int now, int target, int start, int end) {
    if (target > end || target < start) return;
    if (start == end) {
        tree[now]++;
        return;
    }
    int mid = (start + end) / 2;
    update_tree(now * 2, target, start, mid);
    update_tree(now * 2 + 1, target, mid + 1, end);
    tree[now] = tree[now * 2] + tree[now * 2 + 1];
}

int query(int now, int left, int right, int start, int end) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) {
        return tree[now];
    }
    int mid = (start + end) / 2;
    return query(now * 2, left, right, start, mid)+query(now * 2 + 1, left, right, mid + 1, end);
}

int cmp_x_y(const void* a, const void* b) {
    struct Pair* pair_a = (struct Pair*)a;
    struct Pair* pair_b = (struct Pair*)b;
    if (pair_a->first == pair_b->first) return pair_a->second > pair_b->second ? 1 : -1;
    return pair_a->first < pair_b->first ? -1 : 1;
}

int cmp_y(const void* a, const void* b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);
	if (int_a == int_b) return 0;
    return int_a > int_b ? -1 : 1;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            vec[i].first = x;
            vec[i].second = y;
            y_vec[i] = y;
        }
        long long ret = 0;
        qsort(vec, N, sizeof(struct Pair), cmp_x_y);
        qsort(y_vec, N, sizeof(int), cmp_y);
        init_tree(1, 0, N - 1);
        for (int i = 0; i < N; i++) {
            int x = vec[i].first;
            int y = vec[i].second;
			int index = N - 1;
            while (index >= 0 && y_vec[index] < y) {
                index--;
            }
            ret += query(1, 0, index, 0, N - 1);
            update_tree(1, index, 0, N - 1);
        }
        printf("%lld\n", ret);

		for (int i=0; i<N; i++) {
			vec[i].first = 0;
			vec[i].second = 0;
			y_vec[i] = 0;
		}
		for (int i=0; i<MAX_N*4; i++) {
			tree[i] = 0;
		}
    }
    return 0;
}


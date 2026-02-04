#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

enum clust_strategy {
    CLUSTER_MEAN,
    CLUSTER_MAX,
    CLUSTER_MIN
};

struct phylo_s {
    int parent;
    int left;
    int right;
    float diff;
    float lblen;
    float rblen;
    char *is_in;
    int incnum;
};

int N = 512;
enum clust_strategy mode = CLUSTER_MEAN;
struct phylo_s *tree;
float **mx;
int *coord;
int i;
int j;
int idx;
int Np;
int row;
int col;
float min;
float *trow;
float tcol;
float *diff;
int swapfoo;

void init_vars() {
    tree = (struct phylo_s *)calloc(2 * N, sizeof(struct phylo_s));
    if (!tree) exit(1);

    mx = (float **)calloc(N + 10, sizeof(float *));
    if (!mx) exit(1);
    for (int k = 0; k < N + 10; k++) {
        mx[k] = (float *)malloc((N + 10) * sizeof(float));
        if (!mx[k]) exit(1);
        for (int l = 0; l < N + 10; l++) {
            mx[k][l] = 1.0f + (float)(rand() % 1000) / 1000.0f;
        }
    }

    coord = (int *)malloc((N + 10) * sizeof(int));
    if (!coord) exit(1);
    for (int k = 0; k < N; k++) {
        coord[k] = k;
    }

    diff = (float *)calloc(2 * N, sizeof(float));
    if (!diff) exit(1);

    for (int k = 0; k < 2 * N; k++) {
        tree[k].is_in = (char *)calloc(N, sizeof(char));
        if (!tree[k].is_in) exit(1);
        tree[k].incnum = 0;
        tree[k].parent = -1;
        tree[k].left = -1;
        tree[k].right = -1;
        tree[k].diff = 0.0f;
        tree[k].lblen = 0.0f;
        tree[k].rblen = 0.0f;
    }

    i = 0;
    j = 0;
    idx = 0;
    Np = 0;
    row = 0;
    col = 0;
    min = 0.0f;
    tcol = 0.0f;
    swapfoo = 0;
}
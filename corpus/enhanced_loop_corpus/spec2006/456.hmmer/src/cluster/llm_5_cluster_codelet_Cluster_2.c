#include <stdio.h>

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


extern int N;
extern enum clust_strategy mode;
extern struct phylo_s *tree;
extern float **mx;
extern int *coord;
extern int i;
extern int j;
extern int idx;
extern int Np;
extern int row;
extern int col;
extern float min;
extern float *trow;
extern float tcol;
extern float *diff;
extern int swapfoo;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (Np = N; Np >= 2; Np--) {
    min = 999999.0f;
    i = -1; j = -1;
    for (row = 0; row < Np; row++) {
        for (col = row + 1; col < Np; col++) {
            if (mx[row][col] >= min) continue;
            min = mx[row][col];
            i = row;
            j = col;
        }
    }

    if (i == -1 || j == -1) continue;

    tree[Np - 2].left = coord[i];
    tree[Np - 2].right = coord[j];

    if (coord[i] >= N) {
        tree[coord[i] - N].parent = N + Np - 2;
    }
    if (coord[j] >= N) {
        tree[coord[j] - N].parent = N + Np - 2;
    }

    diff[Np - 2] = tree[Np - 2].diff = min;
    tree[Np - 2].lblen = tree[Np - 2].rblen = min;

    if (coord[i] >= N) {
        tree[Np - 2].lblen -= diff[coord[i] - N];
    }
    if (coord[j] >= N) {
        tree[Np - 2].rblen -= diff[coord[j] - N];
    }

    tree[Np - 2].incnum = 0;
    for (idx = 0; idx < N; idx++) {
        tree[Np - 2].is_in[idx] = 0;
    }

    int left_is_leaf = (coord[i] < N);
    int right_is_leaf = (coord[j] < N);

    if (left_is_leaf) {
        tree[Np - 2].incnum++;
        tree[Np - 2].is_in[coord[i]] = 1;
    } else {
        tree[Np - 2].incnum += tree[coord[i] - N].incnum;
        for (idx = 0; idx < N; idx++) {
            tree[Np - 2].is_in[idx] |= tree[coord[i] - N].is_in[idx];
        }
    }

    if (right_is_leaf) {
        tree[Np - 2].incnum++;
        tree[Np - 2].is_in[coord[j]] = 1;
    } else {
        tree[Np - 2].incnum += tree[coord[j] - N].incnum;
        for (idx = 0; idx < N; idx++) {
            tree[Np - 2].is_in[idx] |= tree[coord[j] - N].is_in[idx];
        }
    }

    if (i == Np - 1 || j == Np - 2) {
        swapfoo = i;
        i = j;
        j = swapfoo;
    }

    if (i != Np - 2) {
        trow = mx[Np - 2];
        mx[Np - 2] = mx[i];
        mx[i] = trow;

        for (row = 0; row < Np; row++) {
            tcol = mx[row][Np - 2];
            mx[row][Np - 2] = mx[row][i];
            mx[row][i] = tcol;
        }

        swapfoo = coord[Np - 2];
        coord[Np - 2] = coord[i];
        coord[i] = swapfoo;
    }

    if (j != Np - 1) {
        trow = mx[Np - 1];
        mx[Np - 1] = mx[j];
        mx[j] = trow;

        for (row = 0; row < Np; row++) {
            tcol = mx[row][Np - 1];
            mx[row][Np - 1] = mx[row][j];
            mx[row][j] = tcol;
        }

        swapfoo = coord[Np - 1];
        coord[Np - 1] = coord[j];
        coord[j] = swapfoo;
    }

    i = Np - 2;
    j = Np - 1;

    float factor = (mode == CLUSTER_MEAN) ? 0.5f : 1.0f;
    for (col = 0; col < Np; col++) {
        if (col == i || col == j) continue;

        float val_i = mx[i][col];
        float val_j = mx[j][col];

        if (mode == CLUSTER_MEAN) {
            mx[i][col] = (val_i + val_j) * factor;
        } else if (mode == CLUSTER_MIN) {
            mx[i][col] = val_i < val_j ? val_i : val_j;
        } else if (mode == CLUSTER_MAX) {
            mx[i][col] = val_i > val_j ? val_i : val_j;
        } else {
            mx[i][col] = (val_i + val_j) * factor;
        }
    }

    mx[i][i] = 0.0f;
    mx[i][j] = mx[j][i] = 0.0f;

    for (col = 0; col < Np; col++) {
        mx[col][i] = mx[i][col];
    }

    coord[Np - 2] = N + Np - 2;
}
}

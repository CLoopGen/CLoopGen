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
for (Np = N; Np >= 3; Np -= 2) {
    min = 999999.;
    int min2 = 999999.;
    int i2 = 0, j2 = 0;
    for (row = 0; row < Np; row++) {
        for (col = row + 1; col < Np; col++) {
            float val = mx[row][col];
            if (val < min) {
                min2 = min;
                i2 = i;
                j2 = j;
                min = val;
                i = row;
                j = col;
            } else if (val < min2) {
                min2 = val;
                i2 = row;
                j2 = col;
            }
        }
    }

    tree[Np - 2].left = coord[i];
    tree[Np - 2].right = coord[j];
    if (coord[i] >= N)
        tree[coord[i] - N].parent = N + Np - 2;
    if (coord[j] >= N)
        tree[coord[j] - N].parent = N + Np - 2;
    diff[Np - 2] = tree[Np - 2].diff = min;
    tree[Np - 2].lblen = tree[Np - 2].rblen = min;
    if (coord[i] >= N)
        tree[Np - 2].lblen -= diff[coord[i] - N];
    if (coord[j] >= N)
        tree[Np - 2].rblen -= diff[coord[j] - N];

    tree[Np - 2].incnum = 0;
    for (idx = 0; idx < N; idx++)
        tree[Np - 2].is_in[idx] = 0;

    if (coord[i] < N) {
        tree[Np - 2].incnum++;
        tree[Np - 2].is_in[coord[i]] = 1;
    } else {
        tree[Np - 2].incnum += tree[coord[i] - N].incnum;
        for (idx = 0; idx < N; idx++)
            tree[Np - 2].is_in[idx] |= tree[coord[i] - N].is_in[idx];
    }
    if (coord[j] < N) {
        tree[Np - 2].incnum++;
        tree[Np - 2].is_in[coord[j]] = 1;
    } else {
        tree[Np - 2].incnum += tree[coord[j] - N].incnum;
        for (idx = 0; idx < N; idx++)
            tree[Np - 2].is_in[idx] |= tree[coord[j] - N].is_in[idx];
    }

    if (Np >= 4) {
        tree[Np - 3].left = coord[i2];
        tree[Np - 3].right = coord[j2];
        if (coord[i2] >= N)
            tree[coord[i2] - N].parent = N + Np - 3;
        if (coord[j2] >= N)
            tree[coord[j2] - N].parent = N + Np - 3;
        diff[Np - 3] = tree[Np - 3].diff = min2;
        tree[Np - 3].lblen = tree[Np - 3].rblen = min2;
        if (coord[i2] >= N)
            tree[Np - 3].lblen -= diff[coord[i2] - N];
        if (coord[j2] >= N)
            tree[Np - 3].rblen -= diff[coord[j2] - N];

        tree[Np - 3].incnum = 0;
        for (idx = 0; idx < N; idx++)
            tree[Np - 3].is_in[idx] = 0;

        if (coord[i2] < N) {
            tree[Np - 3].incnum++;
            tree[Np - 3].is_in[coord[i2]] = 1;
        } else {
            tree[Np - 3].incnum += tree[coord[i2] - N].incnum;
            for (idx = 0; idx < N; idx++)
                tree[Np - 3].is_in[idx] |= tree[coord[i2] - N].is_in[idx];
        }
        if (coord[j2] < N) {
            tree[Np - 3].incnum++;
            tree[Np - 3].is_in[coord[j2]] = 1;
        } else {
            tree[Np - 3].incnum += tree[coord[j2] - N].incnum;
            for (idx = 0; idx < N; idx++)
                tree[Np - 3].is_in[idx] |= tree[coord[j2] - N].is_in[idx];
        }
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

    if (Np >= 4 && i2 != Np - 3) {
        trow = mx[Np - 3];
        mx[Np - 3] = mx[i2];
        mx[i2] = trow;
        for (row = 0; row < Np; row++) {
            tcol = mx[row][Np - 3];
            mx[row][Np - 3] = mx[row][i2];
            mx[row][i2] = tcol;
        }
        swapfoo = coord[Np - 3];
        coord[Np - 3] = coord[i2];
        coord[i2] = swapfoo;
    }
    if (Np >= 4 && j2 != Np - 2) {
        trow = mx[Np - 2];
        mx[Np - 2] = mx[j2];
        mx[j2] = trow;
        for (row = 0; row < Np; row++) {
            tcol = mx[row][Np - 2];
            mx[row][Np - 2] = mx[row][j2];
            mx[row][j2] = tcol;
        }
        swapfoo = coord[Np - 2];
        coord[Np - 2] = coord[j2];
        coord[j2] = swapfoo;
    }

    for (col = 0; col < Np; col++) {
        switch (mode) {
          case CLUSTER_MEAN:
            mx[Np - 2][col] = (mx[Np - 2][col] + mx[Np - 1][col]) * 0.5f;
            if (Np >= 4)
                mx[Np - 3][col] = (mx[Np - 3][col] + mx[Np - 2][col]) * 0.5f;
            break;
          case CLUSTER_MIN:
            mx[Np - 2][col] = (mx[Np - 2][col] < mx[Np - 1][col]) ? mx[Np - 2][col] : mx[Np - 1][col];
            if (Np >= 4)
                mx[Np - 3][col] = (mx[Np - 3][col] < mx[Np - 2][col]) ? mx[Np - 3][col] : mx[Np - 2][col];
            break;
          case CLUSTER_MAX:
            mx[Np - 2][col] = (mx[Np - 2][col] > mx[Np - 1][col]) ? mx[Np - 2][col] : mx[Np - 1][col];
            if (Np >= 4)
                mx[Np - 3][col] = (mx[Np - 3][col] > mx[Np - 2][col]) ? mx[Np - 3][col] : mx[Np - 2][col];
            break;
          default:
            mx[Np - 2][col] = (mx[Np - 2][col] + mx[Np - 1][col]) * 0.5f;
            if (Np >= 4)
                mx[Np - 3][col] = (mx[Np - 3][col] + mx[Np - 2][col]) * 0.5f;
            break;
        }
    }

    for (col = 0; col < Np; col++) {
        mx[col][Np - 2] = mx[Np - 2][col];
        if (Np >= 4)
            mx[col][Np - 3] = mx[Np - 3][col];
    }

    coord[Np - 2] = N + Np - 2;
    if (Np >= 4)
        coord[Np - 3] = N + Np - 3;
}
}

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
    min = 999999.;
    int *coord_ptr = coord;
    float **mx_ptr = mx;
    for (row = 0; row < Np; row++) {
        float *mx_row = mx_ptr[row];
        for (col = row + 1; col < Np; col++) {
            float val = *(mx_row + col);
            if (val < min) {
                min = val;
                i = row;
                j = col;
            }
        }
    }
    tree[Np - 2].left = *(coord_ptr + i);
    tree[Np - 2].right = *(coord_ptr + j);
    int ci = *(coord_ptr + i);
    int cj = *(coord_ptr + j);
    if (ci >= N)
        tree[ci - N].parent = N + Np - 2;
    if (cj >= N)
        tree[cj - N].parent = N + Np - 2;
    diff[Np - 2] = tree[Np - 2].diff = min;
    tree[Np - 2].lblen = tree[Np - 2].rblen = min;
    if (ci >= N)
        tree[Np - 2].lblen -= diff[ci - N];
    if (cj >= N)
        tree[Np - 2].rblen -= diff[cj - N];
    if (ci < N) {
        tree[Np - 2].incnum++;
        tree[Np - 2].is_in[ci] = 1;
    } else {
        tree[Np - 2].incnum += tree[ci - N].incnum;
        char *dest = tree[Np - 2].is_in;
        char *src = tree[ci - N].is_in;
        for (idx = 0; idx < N; idx++)
            *(dest + idx) |= *(src + idx);
    }
    if (cj < N) {
        tree[Np - 2].incnum++;
        tree[Np - 2].is_in[cj] = 1;
    } else {
        tree[Np - 2].incnum += tree[cj - N].incnum;
        char *dest = tree[Np - 2].is_in;
        char *src = tree[cj - N].is_in;
        for (idx = 0; idx < N; idx++)
            *(dest + idx) |= *(src + idx);
    }
    if (i == Np - 1 || j == Np - 2) {
        swapfoo = j;
        j = i;
        i = swapfoo;
    }
    if (i != Np - 2) {
        trow = mx_ptr[Np - 2];
        mx_ptr[Np - 2] = mx_ptr[i];
        mx_ptr[i] = trow;
        for (row = 0; row < Np; row++) {
            tcol = mx_ptr[row][Np - 2];
            mx_ptr[row][Np - 2] = mx_ptr[row][i];
            mx_ptr[row][i] = tcol;
        }
        swapfoo = *(coord_ptr + Np - 2);
        *(coord_ptr + Np - 2) = *(coord_ptr + i);
        *(coord_ptr + i) = swapfoo;
    }
    if (j != Np - 1) {
        trow = mx_ptr[Np - 1];
        mx_ptr[Np - 1] = mx_ptr[j];
        mx_ptr[j] = trow;
        for (row = 0; row < Np; row++) {
            tcol = mx_ptr[row][Np - 1];
            mx_ptr[row][Np - 1] = mx_ptr[row][j];
            mx_ptr[row][j] = tcol;
        }
        swapfoo = *(coord_ptr + Np - 1);
        *(coord_ptr + Np - 1) = *(coord_ptr + j);
        *(coord_ptr + j) = swapfoo;
    }
    i = Np - 2;
    j = Np - 1;
    float *mx_i = mx_ptr[i];
    float *mx_j = mx_ptr[j];
    for (col = 0; col < Np; col++) {
        float a = *(mx_i + col);
        float b = *(mx_j + col);
        switch (mode) {
          case CLUSTER_MEAN:
            *(mx_i + col) = (a + b) * 0.5f;
            break;
          case CLUSTER_MIN:
            *(mx_i + col) = (a < b) ? a : b;
            break;
          case CLUSTER_MAX:
            *(mx_i + col) = (a > b) ? a : b;
            break;
          default:
            *(mx_i + col) = (a + b) * 0.5f;
            break;
        }
    }
    for (col = 0; col < Np; col++)
        mx_ptr[col][i] = mx_ptr[i][col];
    *(coord_ptr + Np - 2) = Np + N - 2;
}
}

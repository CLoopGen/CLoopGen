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
    for (row = 0; row < Np; row++) {
        for (col = row + 1; col < Np; col++) {
            float val = mx[row][col];
            if (val < min) {
                min = val;
                i = row;
                j = col;
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
    tree[Np - 2].lblen = tree[Np - 2].rblen = min * 0.5;
    if (coord[i] >= N)
        tree[Np - 2].lblen += diff[coord[i] - N] * 0.5;
    if (coord[j] >= N)
        tree[Np - 2].rblen += diff[coord[j] - N] * 0.5;

    int inc_i = (coord[i] < N) ? 1 : tree[coord[i] - N].incnum;
    int inc_j = (coord[j] < N) ? 1 : tree[coord[j] - N].incnum;
    tree[Np - 2].incnum = inc_i + inc_j;

    for (idx = 0; idx < N; idx++) {
        char in_i = (coord[i] < N) ? (idx == coord[i]) : tree[coord[i] - N].is_in[idx];
        char in_j = (coord[j] < N) ? (idx == coord[j]) : tree[coord[j] - N].is_in[idx];
        tree[Np - 2].is_in[idx] = in_i | in_j;
    }

    if (i != Np - 2 || j != Np - 1) {
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
    }

    i = Np - 2;
    j = Np - 1;
    switch (mode) {
      case CLUSTER_MEAN:
        for (col = 0; col < Np; col++) {
            mx[i][col] = (mx[i][col] + mx[j][col]) * 0.5f;
            mx[col][i] = mx[i][col];
        }
        break;
      case CLUSTER_MIN:
        for (col = 0; col < Np; col++) {
            mx[i][col] = (mx[i][col] < mx[j][col]) ? mx[i][col] : mx[j][col];
            mx[col][i] = mx[i][col];
        }
        break;
      case CLUSTER_MAX:
        for (col = 0; col < Np; col++) {
            mx[i][col] = (mx[i][col] > mx[j][col]) ? mx[i][col] : mx[j][col];
            mx[col][i] = mx[i][col];
        }
        break;
      default:
        for (col = 0; col < Np; col++) {
            mx[i][col] = (mx[i][col] + mx[j][col]) * 0.5f;
            mx[col][i] = mx[i][col];
        }
        break;
    }
    coord[Np - 2] = N + Np - 2;
}
}

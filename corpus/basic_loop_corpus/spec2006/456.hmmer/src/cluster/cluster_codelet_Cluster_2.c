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
    for (row = 0; row < Np; row++)
        for (col = row + 1; col < Np; col++)
            if (mx[row][col] < min) {
                min = mx[row][col];
                i = row;
                j = col;
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
    if (i == Np - 1 || j == Np - 2) {
        swapfoo = j;
        j = i;
        i = swapfoo;
    }
    ;
    if (i != Np - 2) {
        trow = mx[Np - 2];
        mx[Np - 2] = mx[i];
        mx[i] = trow;
        for (row = 0; row < Np; row++) {
            tcol = mx[row][Np - 2];
            mx[row][Np - 2] = mx[row][i];
            mx[row][i] = tcol;
        }
        {
            swapfoo = coord[Np - 2];
            coord[Np - 2] = coord[i];
            coord[i] = swapfoo;
        }
        ;
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
        {
            swapfoo = coord[Np - 1];
            coord[Np - 1] = coord[j];
            coord[j] = swapfoo;
        }
        ;
    }
    i = Np - 2;
    j = Np - 1;
    for (col = 0; col < Np; col++) {
        switch (mode) {
          case CLUSTER_MEAN:
            mx[i][col] = (mx[i][col] + mx[j][col]) / 2.;
            break;
          case CLUSTER_MIN:
            mx[i][col] = (((mx[i][col]) < (mx[j][col])) ? (mx[i][col]) : (mx[j][col]));
            break;
          case CLUSTER_MAX:
            mx[i][col] = (((mx[i][col]) > (mx[j][col])) ? (mx[i][col]) : (mx[j][col]));
            break;
          default:
            mx[i][col] = (mx[i][col] + mx[j][col]) / 2.;
            break;
        }
    }
    for (col = 0; col < Np; col++)
        mx[col][i] = mx[i][col];
    coord[Np - 2] = Np + N - 2;
}

}

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
    tree[Np - 2].lblen = tree[Np - 2].rblen = min;
    if (coord[i] >= N)
        tree[Np - 2].lblen -= diff[coord[i] - N];
    if (coord[j] >= N)
        tree[Np - 2].rblen -= diff[coord[j] - N];

    // Merge membership and counts with explicit unrolling-like structure for clarity
    int sources[2] = {coord[i], coord[j]};
    int is_leaf[2] = {sources[0] < N, sources[1] < N};
    for (int side = 0; side < 2; side++) {
        if (is_leaf[side]) {
            tree[Np - 2].incnum++;
            tree[Np - 2].is_in[sources[side]] = 1;
        } else {
            tree[Np - 2].incnum += tree[sources[side] - N].incnum;
            for (idx = 0; idx < N; idx++) {
                tree[Np - 2].is_in[idx] |= tree[sources[side] - N].is_in[idx];
            }
        }
    }

    if (i == Np - 1 || j == Np - 2) {
        swapfoo = j;
        j = i;
        i = swapfoo;
    }

    // Update matrix rows: bring selected clusters to positions Np-2 and Np-1
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

    // Update distance matrix using clustering strategy
    for (col = 0; col < Np; col++) {
        float dist_i = mx[i][col];
        float dist_j = mx[j][col];
        switch (mode) {
          case CLUSTER_MEAN:
            mx[i][col] = (dist_i + dist_j) * 0.5f;
            break;
          case CLUSTER_MIN:
            mx[i][col] = (dist_i < dist_j) ? dist_i : dist_j;
            break;
          case CLUSTER_MAX:
            mx[i][col] = (dist_i > dist_j) ? dist_i : dist_j;
            break;
          default:
            mx[i][col] = (dist_i + dist_j) * 0.5f;
            break;
        }
    }

    // Symmetrize the updated row
    for (col = 0; col < Np; col++) {
        mx[col][i] = mx[i][col];
    }

    coord[Np - 2] = Np + N - 2;
}
}

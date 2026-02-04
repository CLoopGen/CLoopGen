#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct dpmatrix_s {
    int **xmx;
    int **mmx;
    int **imx;
    int **dmx;
    void *xmx_mem;
    void *mmx_mem;
    void *imx_mem;
    void *dmx_mem;
    int maxN;
    int maxM;
    int padN;
    int padM;
};

int N;
int M;
struct dpmatrix_s *mx;
int i;

static int** allocate_2d_int_array(int rows, int cols) {
    int **arr = (int **)calloc(rows, sizeof(int *));
    int *data = (int *)calloc(rows * cols, sizeof(int));
    for (int i = 0; i < rows; i++) {
        arr[i] = &(data[i * cols]);
    }
    return arr;
}

void init_vars() {
    N = 10000;
    M = 2000;
    mx = (struct dpmatrix_s *)calloc(1, sizeof(struct dpmatrix_s));
    mx->maxN = N + 1;
    mx->maxM = M + 2;
    mx->padN = N + 1;
    mx->padM = M + 2;

    mx->xmx = allocate_2d_int_array(mx->maxN, 5);
    mx->mmx = allocate_2d_int_array(mx->maxN, mx->maxM);
    mx->imx = allocate_2d_int_array(mx->maxN, mx->maxM);
    mx->dmx = allocate_2d_int_array(mx->maxN, mx->maxM);

    mx->xmx_mem = mx->xmx[0];
    mx->mmx_mem = mx->mmx[0];
    mx->imx_mem = mx->imx[0];
    mx->dmx_mem = mx->dmx[0];
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct dpmatrix_s *mx;
int N;
int M;
int i;

void init_vars() {
    N = 1000;
    M = 200;

    mx = (struct dpmatrix_s *)calloc(1, sizeof(struct dpmatrix_s));
    if (!mx) exit(1);

    mx->maxN = N + 1;
    mx->maxM = M + 2;
    mx->padN = 0;
    mx->padM = 0;

    // Allocate memory for row pointers
    mx->xmx = (int **)calloc(mx->maxN, sizeof(int *));
    mx->mmx = (int **)calloc(mx->maxN, sizeof(int *));
    mx->imx = (int **)calloc(mx->maxN, sizeof(int *));
    mx->dmx = (int **)calloc(mx->maxN, sizeof(int *));
    
    if (!mx->xmx || !mx->mmx || !mx->imx || !mx->dmx) exit(1);

    // Allocate memory blocks
    mx->xmx_mem = calloc((N + 1) * 5 + 16, sizeof(int));
    mx->mmx_mem = calloc((N + 1) * (M + 2) + 16, sizeof(int));
    mx->imx_mem = calloc((N + 1) * (M + 2) + 16, sizeof(int));
    mx->dmx_mem = calloc((N + 1) * (M + 2) + 16, sizeof(int));

    if (!mx->xmx_mem || !mx->mmx_mem || !mx->imx_mem || !mx->dmx_mem) exit(1);

    // Set base rows
    mx->xmx[0] = (int *)mx->xmx_mem;
    mx->mmx[0] = (int *)mx->mmx_mem;
    mx->imx[0] = (int *)mx->imx_mem;
    mx->dmx[0] = (int *)mx->dmx_mem;

    // Initialize all rows to prevent undefined behavior in loop
    for (int idx = 0; idx <= N; idx++) {
        mx->xmx[idx] = mx->xmx[0] + (idx * 5);
        mx->mmx[idx] = mx->mmx[0] + (idx * (M + 2));
        mx->imx[idx] = mx->imx[0] + (idx * (M + 2));
        mx->dmx[idx] = mx->dmx[0] + (idx * (M + 2));
    }
}
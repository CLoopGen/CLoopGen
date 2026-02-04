#include <stdio.h>
#include <inttypes.h>
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

int k1 = 0;
int k3 = 10000;
struct dpmatrix_s *fwd;
struct dpmatrix_s *bck;
int k2;
char t2;
int cur = 50;
int k;
int sc;
int max = -2000000000;

static void init_array_2d(int ***matrix, void **mem, int rows, int cols) {
    *mem = calloc(rows * cols, sizeof(int));
    *matrix = malloc(rows * sizeof(int*));
    int *data = (int*)(*mem);
    for (int i = 0; i < rows; i++) {
        (*matrix)[i] = &data[i * cols];
    }
}

void init_vars() {
    fwd = malloc(sizeof(struct dpmatrix_s));
    bck = malloc(sizeof(struct dpmatrix_s));

    fwd->maxN = 100;
    fwd->maxM = 15000;
    fwd->padN = 0;
    fwd->padM = 0;

    bck->maxN = 100;
    bck->maxM = 15000;
    bck->padN = 0;
    bck->padM = 0;

    cur = 50;
    k1 = 0;
    k3 = 14999;

    init_array_2d(&fwd->mmx, &fwd->mmx_mem, fwd->maxN, fwd->maxM);
    init_array_2d(&fwd->imx, &fwd->imx_mem, fwd->maxN, fwd->maxM);
    init_array_2d(&bck->mmx, &bck->mmx_mem, bck->maxN, bck->maxM);
    init_array_2d(&bck->imx, &bck->imx_mem, bck->maxN, bck->maxM);

    for (int i = 0; i < fwd->maxN; i++) {
        for (int j = 0; j < fwd->maxM; j++) {
            fwd->mmx[i][j] = rand() % 2000 - 1000;
            fwd->imx[i][j] = rand() % 2000 - 1000;
        }
    }

    for (int i = 0; i < bck->maxN; i++) {
        for (int j = 0; j < bck->maxM; j++) {
            bck->mmx[i][j] = rand() % 2000 - 1000;
            bck->imx[i][j] = rand() % 2000 - 1000;
        }
    }

    max = -2000000000;
}
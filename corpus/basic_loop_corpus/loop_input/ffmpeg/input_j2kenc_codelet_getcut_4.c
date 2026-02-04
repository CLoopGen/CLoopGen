#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct Jpeg2000Pass {
    uint16_t rate;
    int64_t disto;
    uint8_t flushed[4];
    int flushed_len;
} Jpeg2000Pass;

typedef struct Jpeg2000Cblk {
    uint8_t npasses;
    uint8_t ninclpasses;
    uint8_t nonzerobits;
    uint16_t length;
    uint16_t *lengthinc;
    uint8_t nb_lengthinc;
    uint8_t lblock;
    uint8_t *data;
    size_t data_allocated;
    int nb_terminations;
    int nb_terminationsinc;
    int *data_start;
    Jpeg2000Pass *passes;
    int coord[2][2];
} Jpeg2000Cblk;

Jpeg2000Cblk *cblk;
int64_t lambda;
int dwt_norm;
int passno;
int res;

void init_vars() {
    lambda = 1000000;
    dwt_norm = 8192;

    cblk = (Jpeg2000Cblk*)calloc(1, sizeof(Jpeg2000Cblk));
    if (!cblk) exit(1);

    cblk->npasses = 10000;
    cblk->ninclpasses = 0;
    cblk->nonzerobits = 10;
    cblk->length = 0;
    cblk->nb_lengthinc = 0;
    cblk->lblock = 3;
    cblk->data_allocated = 131072;
    cblk->nb_terminations = 0;
    cblk->nb_terminationsinc = 0;
    cblk->coord[0][0] = 0; cblk->coord[0][1] = 64;
    cblk->coord[1][0] = 0; cblk->coord[1][1] = 64;

    cblk->data = (uint8_t*)malloc(cblk->data_allocated);
    if (!cblk->data) exit(1);

    cblk->data_start = (int*)calloc(cblk->npasses, sizeof(int));
    if (!cblk->data_start) exit(1);

    cblk->passes = (Jpeg2000Pass*)calloc(cblk->npasses, sizeof(Jpeg2000Pass));
    if (!cblk->passes) exit(1);

    uint16_t cumulative_rate = 0;
    int64_t cumulative_disto = (int64_t)1 << 50;

    for (int i = 0; i < cblk->npasses; i++) {
        cblk->passes[i].rate = cumulative_rate;
        cblk->passes[i].disto = cumulative_disto;
        cblk->passes[i].flushed_len = 0;
        for (int j = 0; j < 4; j++)
            cblk->passes[i].flushed[j] = 0;

        cumulative_rate += (i + 1) * 10;
        cumulative_disto -= (i + 1) * 1000;
    }

    res = 0;
}
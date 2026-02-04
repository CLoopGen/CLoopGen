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

extern Jpeg2000Cblk *cblk;
extern int64_t lambda;
extern int dwt_norm;
extern int passno;
extern int res;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int step = 2;
int limit = (cblk->npasses + 1) / 2;
for (passno = 0; passno < limit; passno++) {
    int idx = passno * step;
    int dr1, dr2;
    int64_t dd1, dd2;
    int64_t lambda_shifted = lambda << 1;

    if (idx < cblk->npasses) {
        dr1 = cblk->passes[idx].rate - (res ? cblk->passes[res - 1].rate : 0);
        dd1 = cblk->passes[idx].disto - (res ? cblk->passes[res - 1].disto : 0);
        if ((((dd1 * dwt_norm) >> 13) * dwt_norm) >= dr1 * lambda)
            res = idx + 1;
    }

    if (idx + 1 < cblk->npasses) {
        dr2 = cblk->passes[idx + 1].rate - (res ? cblk->passes[res - 1].rate : 0);
        dd2 = cblk->passes[idx + 1].disto - (res ? cblk->passes[res - 1].disto : 0);
        if ((((dd2 * dwt_norm) >> 13) * dwt_norm) >= dr2 * lambda_shifted)
            res = idx + 2;
    }
}
}

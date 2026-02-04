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
for (passno = 0; passno < cblk->npasses && passno < 32; passno++) {
    int dr;
    int64_t dd;
    int64_t term1, term2;
    dr = cblk->passes[passno].rate - (res ? cblk->passes[res - 1].rate : 0);
    dd = cblk->passes[passno].disto - (res ? cblk->passes[res - 1].disto : 0);
    term1 = ((dd * dwt_norm) >> 13) * dwt_norm;
    term2 = dr * lambda;
    if (term1 >= term2)
        res = passno + 1;
}
}

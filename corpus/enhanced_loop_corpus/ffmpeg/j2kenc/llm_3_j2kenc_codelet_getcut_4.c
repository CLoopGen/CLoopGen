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
    // Variant 2: Consecutive array access using pointer arithmetic and local accumulation
    Jpeg2000Pass *pass = cblk->passes;
    int npasses = cblk->npasses;
    int base_rate = res ? cblk->passes[res - 1].rate : 0;
    int64_t base_disto = res ? cblk->passes[res - 1].disto : 0;

    for (passno = 0; passno < npasses; passno++, pass++) {
        int dr = pass->rate - base_rate;
        int64_t dd = pass->disto - base_disto;
        base_rate = pass->rate;       // Update base for next iteration to simulate incremental diff
        base_disto = pass->disto;
        if (((dd * dwt_norm) >> 13) * dwt_norm >= dr * lambda)
            res = passno + 1;
    }
}

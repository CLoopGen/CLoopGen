#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct Jpeg2000TgtNode {
    uint8_t val;
    uint8_t vis;
    struct Jpeg2000TgtNode *parent;
} Jpeg2000TgtNode;

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

typedef struct Jpeg2000Prec {
    int nb_codeblocks_width;
    int nb_codeblocks_height;
    Jpeg2000TgtNode *zerobits;
    Jpeg2000TgtNode *cblkincl;
    Jpeg2000Cblk *cblk;
    int decoded_layers;
    int coord[2][2];
} Jpeg2000Prec;

typedef struct Jpeg2000Band {
    int coord[2][2];
    uint16_t log2_cblk_width;
    uint16_t log2_cblk_height;
    int i_stepsize;
    float f_stepsize;
    Jpeg2000Prec *prec;
} Jpeg2000Band;

typedef struct Jpeg2000ResLevel {
    uint8_t nbands;
    int coord[2][2];
    int num_precincts_x;
    int num_precincts_y;
    uint8_t log2_prec_width;
    uint8_t log2_prec_height;
    Jpeg2000Band *band;
} Jpeg2000ResLevel;

typedef struct DWTContext {
    int linelen[32][2];
    uint8_t mod[32][2];
    uint8_t ndeclevels;
    uint8_t type;
    int32_t *i_linebuf;
    float *f_linebuf;
} DWTContext;

typedef struct Jpeg2000Component {
    Jpeg2000ResLevel *reslevel;
    DWTContext dwt;
    float *f_data;
    int *i_data;
    int coord[2][2];
    int coord_o[2][2];
    uint8_t roi_shift;
} Jpeg2000Component;

extern Jpeg2000Band *band;
extern Jpeg2000Component *comp;
extern int bandno;
extern int reslevelno;
extern Jpeg2000Prec *prec;
extern int nb_codeblocks;
extern int cblkno;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Strided memory access pattern: process codeblocks in reverse order with stride of 2
int stride = 2;
int limit = (nb_codeblocks + stride - 1) & ~(stride - 1); // Align up to nearest multiple of stride

for (int idx = 0; idx < limit; idx += stride) {
    // Access elements in reverse-stride order
    int rev_idx = nb_codeblocks - 1 - idx;
    if (rev_idx >= nb_codeblocks) continue;

    Jpeg2000Cblk *cblk = prec->cblk + rev_idx;
    int Cx0, Cy0;

    // Pre-extract commonly used fields to reduce repeated struct access
    int prec_nb_cbw = prec->nb_codeblocks_width;
    int shift_w = band->log2_cblk_width;
    int shift_h = band->log2_cblk_height;

    Cx0 = ((prec->coord[0][0]) >> shift_w) << shift_w;
    Cx0 += ((rev_idx % prec_nb_cbw) << shift_w);
    cblk->coord[0][0] = (Cx0 > prec->coord[0][0]) ? Cx0 : prec->coord[0][0];

    Cy0 = ((prec->coord[1][0]) >> shift_h) << shift_h;
    Cy0 += ((rev_idx / prec_nb_cbw) << shift_h);
    cblk->coord[1][0] = (Cy0 > prec->coord[1][0]) ? Cy0 : prec->coord[1][0];

    int cx1 = Cx0 + (1 << shift_w);
    int cy1 = Cy0 + (1 << shift_h);

    cblk->coord[0][1] = (cx1 > prec->coord[0][1]) ? prec->coord[0][1] : cx1;
    cblk->coord[1][1] = (cy1 > prec->coord[1][1]) ? prec->coord[1][1] : cy1;

    if ((bandno + !!reslevelno) & 1) {
        int offset = comp->reslevel[reslevelno - 1].coord[0][1] - comp->reslevel[reslevelno - 1].coord[0][0];
        cblk->coord[0][0] += offset;
        cblk->coord[0][1] += offset;
    }
    if ((bandno + !!reslevelno) & 2) {
        int offset = comp->reslevel[reslevelno - 1].coord[1][1] - comp->reslevel[reslevelno - 1].coord[1][0];
        cblk->coord[1][0] += offset;
        cblk->coord[1][1] += offset;
    }

    cblk->lblock = 3;
    cblk->length = 0;
    cblk->npasses = 0;

    // Handle adjacent element if within bounds (second part of stride)
    if (idx + 1 < nb_codeblocks) {
        int next_idx = nb_codeblocks - 1 - (idx + 1);
        Jpeg2000Cblk *next_cblk = prec->cblk + next_idx;
        *next_cblk = (Jpeg2000Cblk){0}; // Reset structure
        next_cblk->lblock = 3;
        next_cblk->length = 0;
        next_cblk->npasses = 0;

        // Reuse same coordinate logic
        Cx0 = ((prec->coord[0][0]) >> shift_w) << shift_w;
        Cx0 += ((next_idx % prec_nb_cbw) << shift_w);
        Cy0 = ((prec->coord[1][0]) >> shift_h) << shift_h;
        Cy0 += ((next_idx / prec_nb_cbw) << shift_h);

        next_cblk->coord[0][0] = (Cx0 > prec->coord[0][0]) ? Cx0 : prec->coord[0][0];
        next_cblk->coord[1][0] = (Cy0 > prec->coord[1][0]) ? Cy0 : prec->coord[1][0];
        next_cblk->coord[0][1] = (Cx0 + (1 << shift_w) > prec->coord[0][1]) ? prec->coord[0][1] : Cx0 + (1 << shift_w);
        next_cblk->coord[1][1] = (Cy0 + (1 << shift_h) > prec->coord[1][1]) ? prec->coord[1][1] : Cy0 + (1 << shift_h);

        if ((bandno + !!reslevelno) & 1) {
            int offset = comp->reslevel[reslevelno - 1].coord[0][1] - comp->reslevel[reslevelno - 1].coord[0][0];
            next_cblk->coord[0][0] += offset;
            next_cblk->coord[0][1] += offset;
        }
        if ((bandno + !!reslevelno) & 2) {
            int offset = comp->reslevel[reslevelno - 1].coord[1][1] - comp->reslevel[reslevelno - 1].coord[1][0];
            next_cblk->coord[1][0] += offset;
            next_cblk->coord[1][1] += offset;
        }
    }
}
}

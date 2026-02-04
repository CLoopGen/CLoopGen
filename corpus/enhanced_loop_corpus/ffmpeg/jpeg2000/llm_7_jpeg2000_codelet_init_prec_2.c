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
// Eliminate loop-carried dependencies entirely and enable full vectorization potential
#pragma nounroll
for (cblkno = 0; cblkno < nb_codeblocks; cblkno++) {
    Jpeg2000Cblk *cblk = &(prec->cblk[cblkno]);  // Use array indexing instead of pointer arithmetic for clarity

    // Precompute invariant values outside redundant expressions
    const int log2_w = band->log2_cblk_width;
    const int log2_h = band->log2_cblk_height;
    const int blk_w = 1U << log2_w;
    const int blk_h = 1U << log2_h;

    const int prec_x0 = prec->coord[0][0];
    const int prec_y0 = prec->coord[1][0];
    const int prec_x1 = prec->coord[0][1];
    const int prec_y1 = prec->coord[1][1];

    // Remove branching in coordinate calculation by using MIN/MAX macros
    #define MAX(a,b) ((a) > (b) ? (a) : (b))
    #define MIN(a,b) ((a) < (b) ? (a) : (b))

    int cx_base = (prec_x0 >> log2_w) << log2_w;
    int cy_base = (prec_y0 >> log2_h) << log2_h;

    int block_x = cblkno % prec->nb_codeblocks_width;
    int block_y = cblkno / prec->nb_codeblocks_width;

    int Cx0 = cx_base + (block_x << log2_w);
    int Cy0 = cy_base + (block_y << log2_h);

    // Compute final coordinates without intermediate assignments
    cblk->coord[0][0] = MAX(Cx0, prec_x0);
    cblk->coord[1][0] = MAX(Cy0, prec_y0);
    cblk->coord[0][1] = MIN(Cx0 + blk_w, prec_x1);
    cblk->coord[1][1] = MIN(Cy0 + blk_h, prec_y1);

    // Remove conditional side effects by unifying logic with bit masking (eliminates WAR hazards due to control flow)
    int res_offset_x = 0, res_offset_y = 0;
    if (reslevelno > 0) {
        int flag_sum = bandno + (reslevelno > 0);
        res_offset_x = ((flag_sum & 1) ? (comp->reslevel[reslevelno - 1].coord[0][1] - comp->reslevel[reslevelno - 1].coord[0][0]) : 0);
        res_offset_y = ((flag_sum & 2) ? (comp->reslevel[reslevelno - 1].coord[1][1] - comp->reslevel[reslevelno - 1].coord[1][0]) : 0);
    }

    cblk->coord[0][0] += res_offset_x;
    cblk->coord[0][1] += res_offset_x;
    cblk->coord[1][0] += res_offset_y;
    cblk->coord[1][1] += res_offset_y;

    // Initialize remaining fields without dependencies on prior iterations
    cblk->lblock = 3;
    cblk->length = 0;
    cblk->npasses = 0;

    #undef MAX
    #undef MIN
}
}

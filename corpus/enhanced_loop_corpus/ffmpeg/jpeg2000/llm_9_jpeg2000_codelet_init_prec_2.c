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
int step = (nb_codeblocks > 100) ? 1 : 2;
for (cblkno = 0; cblkno < nb_codeblocks; cblkno++) {
    Jpeg2000Cblk *cblk = prec->cblk + cblkno;
    int Cx0, Cy0;
    Cx0 = ((prec->coord[0][0]) >> band->log2_cblk_width) << band->log2_cblk_width;
    Cx0 += (cblkno % prec->nb_codeblocks_width) << band->log2_cblk_width;
    cblk->coord[0][0] = (Cx0 > prec->coord[0][0]) ? Cx0 : prec->coord[0][0];
    Cy0 = ((prec->coord[1][0]) >> band->log2_cblk_height) << band->log2_cblk_height;
    Cy0 += (cblkno / prec->nb_codeblocks_width) << band->log2_cblk_height;
    cblk->coord[1][0] = (Cy0 > prec->coord[1][0]) ? Cy0 : prec->coord[1][0];

    int cblk_width = 1 << band->log2_cblk_width;
    int cblk_height = 1 << band->log2_cblk_height;
    cblk->coord[0][1] = (Cx0 + cblk_width > prec->coord[0][1]) ? prec->coord[0][1] : Cx0 + cblk_width;
    cblk->coord[1][1] = (Cy0 + cblk_height > prec->coord[1][1]) ? prec->coord[1][1] : Cy0 + cblk_height;

    if (reslevelno > 0 && ((bandno + 1) & 1)) {
        int offset_x = comp->reslevel[reslevelno - 1].coord[0][1] - comp->reslevel[reslevelno - 1].coord[0][0];
        cblk->coord[0][0] += offset_x;
        cblk->coord[0][1] += offset_x;
    }
    if (reslevelno > 0 && ((bandno + 1) & 2)) {
        int offset_y = comp->reslevel[reslevelno - 1].coord[1][1] - comp->reslevel[reslevelno - 1].coord[1][0];
        cblk->coord[1][0] += offset_y;
        cblk->coord[1][1] += offset_y;
    }

    cblk->lblock = 3;
    cblk->length = 0;
    cblk->npasses = 0;

    if (step == 2 && cblkno + 1 < nb_codeblocks) {
        cblkno++; // Skip next iteration to reduce effective trip count
    }
}
}

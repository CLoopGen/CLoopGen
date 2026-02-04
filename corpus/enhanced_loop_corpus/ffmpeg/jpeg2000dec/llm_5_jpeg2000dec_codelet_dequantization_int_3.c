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

typedef struct Jpeg2000TgtNode {
    uint8_t val;
    uint8_t vis;
    struct Jpeg2000TgtNode *parent;
} Jpeg2000TgtNode;

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

typedef struct MqcState {
    uint8_t *bp;
    uint8_t *bpstart;
    unsigned int a;
    unsigned int c;
    unsigned int ct;
    uint8_t cx_states[19];
    int raw;
} MqcState;

typedef struct Jpeg2000T1Context {
    int data[6144];
    uint16_t flags[6156];
    MqcState mqc;
    int stride;
} Jpeg2000T1Context;

extern int x;
extern int y;
extern Jpeg2000Cblk *cblk;
extern Jpeg2000Component *comp;
extern Jpeg2000T1Context *t1;
extern Jpeg2000Band *band;
extern int i;
extern int j;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < (cblk->coord[1][1] - cblk->coord[1][0]); ++j) {
    int32_t *datap = &comp->i_data[(comp->coord[0][1] - comp->coord[0][0]) * (y + j) + x];
    int *src = t1->data + j * t1->stride;
    int step_val = band->i_stepsize;
    int use_fast_path = (step_val == 32768);

    for (i = 0; i < w; ++i) {
        if (!use_fast_path) {
            datap[i] = (src[i] * (int64_t)step_val) / 65536;
        } else {
            // Fast path: avoid multiplication and large division
            datap[i] = src[i] >> 1;
        }
    }
}
}

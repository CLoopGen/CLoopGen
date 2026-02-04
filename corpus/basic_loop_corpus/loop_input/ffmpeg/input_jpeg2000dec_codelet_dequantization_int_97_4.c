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

// External variables
int x = 0;
int y = 0;
Jpeg2000Cblk *cblk;
Jpeg2000Component *comp;
Jpeg2000T1Context *t1;
Jpeg2000Band *band;
int i;
int j;
int w;

void init_vars() {
    // Allocate and initialize t1 context
    t1 = (Jpeg2000T1Context*)calloc(1, sizeof(Jpeg2000T1Context));
    if (!t1) exit(1);

    // Set stride to match typical block width
    t1->stride = 64;
    w = 64;  // Set w to match the inner loop

    // Initialize data in t1 to non-zero values for realistic computation
    for (int idx = 0; idx < 6144; idx++) {
        t1->data[idx] = (idx % 128) - 64;
    }

    // Allocate band
    band = (Jpeg2000Band*)calloc(1, sizeof(Jpeg2000Band));
    if (!band) exit(1);
    band->i_stepsize = 12345; // Arbitrary step size

    // Allocate comp
    comp = (Jpeg2000Component*)calloc(1, sizeof(Jpeg2000Component));
    if (!comp) exit(1);

    // Set component coordinates
    comp->coord[0][0] = 0;
    comp->coord[0][1] = 1024; // Width of image
    comp->coord[1][0] = 0;
    comp->coord[1][1] = 1024; // Height of image

    // Allocate i_data: large enough to make loop take ~0.01s
    // We want around 64MB of output data to ensure sufficient runtime
    int total_size = (comp->coord[0][1] - comp->coord[0][0]) * 
                     (comp->coord[1][1] - comp->coord[1][0]);
    comp->i_data = (int*)calloc(total_size, sizeof(int32_t));
    if (!comp->i_data) exit(1);

    // Allocate cblk
    cblk = (Jpeg2000Cblk*)calloc(1, sizeof(Jpeg2000Cblk));
    if (!cblk) exit(1);

    // Set cblk coordinates so that height is 16 (controls outer loop)
    cblk->coord[1][0] = 0;
    cblk->coord[1][1] = 16;
    y = 100; // So that (y + j) stays within [100,115], which is < 1024

    x = 50; // Starting x offset
}
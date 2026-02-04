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

Jpeg2000Band *band;
Jpeg2000Component *comp;
int bandno;
int reslevelno;
Jpeg2000Prec *prec;
int nb_codeblocks;
int cblkno;

static Jpeg2000Cblk *g_cblk_array = NULL;
static Jpeg2000ResLevel *g_reslevel_array = NULL;
static Jpeg2000Band *g_band_array = NULL;
static Jpeg2000Prec *g_prec = NULL;
static int32_t *g_i_linebuf = NULL;
static float *g_f_linebuf = NULL;
static float *g_f_data = NULL;
static int *g_i_data = NULL;

void init_vars() {
    bandno = 1;
    reslevelno = 1;

    g_reslevel_array = calloc(2, sizeof(Jpeg2000ResLevel));
    if (!g_reslevel_array) exit(1);

    g_band_array = calloc(4, sizeof(Jpeg2000Band));
    if (!g_band_array) exit(1);

    g_cblk_array = calloc(65536, sizeof(Jpeg2000Cblk));
    if (!g_cblk_array) exit(1);

    g_i_linebuf = malloc(131072 * sizeof(int32_t));
    if (!g_i_linebuf) exit(1);

    g_f_linebuf = malloc(131072 * sizeof(float));
    if (!g_f_linebuf) exit(1);

    g_f_data = malloc(131072 * sizeof(float));
    if (!g_f_data) exit(1);

    g_i_data = malloc(131072 * sizeof(int));
    if (!g_i_data) exit(1);

    g_prec = malloc(sizeof(Jpeg2000Prec));
    if (!g_prec) exit(1);

    comp = malloc(sizeof(Jpeg2000Component));
    if (!comp) exit(1);

    band = &g_band_array[bandno];

    comp->reslevel = g_reslevel_array;
    comp->dwt.i_linebuf = g_i_linebuf;
    comp->dwt.f_linebuf = g_f_linebuf;
    comp->f_data = g_f_data;
    comp->i_data = g_i_data;
    comp->coord[0][0] = 0;
    comp->coord[0][1] = 4096;
    comp->coord[1][0] = 0;
    comp->coord[1][1] = 4096;
    comp->coord_o[0][0] = 0;
    comp->coord_o[0][1] = 4096;
    comp->coord_o[1][0] = 0;
    comp->coord_o[1][1] = 4096;
    comp->roi_shift = 0;

    g_reslevel_array[0].coord[0][0] = 0;
    g_reslevel_array[0].coord[0][1] = 2048;
    g_reslevel_array[0].coord[1][0] = 0;
    g_reslevel_array[0].coord[1][1] = 2048;
    g_reslevel_array[0].nbands = 3;
    g_reslevel_array[0].band = g_band_array;

    g_reslevel_array[1].coord[0][0] = 0;
    g_reslevel_array[1].coord[0][1] = 4096;
    g_reslevel_array[1].coord[1][0] = 0;
    g_reslevel_array[1].coord[1][1] = 4096;
    g_reslevel_array[1].nbands = 3;
    g_reslevel_array[1].band = g_band_array;

    prec = g_prec;
    prec->cblk = g_cblk_array;
    prec->nb_codeblocks_width = 256;
    prec->nb_codeblocks_height = 256;
    nb_codeblocks = 65536;

    prec->coord[0][0] = 0;
    prec->coord[0][1] = 4096;
    prec->coord[1][0] = 0;
    prec->coord[1][1] = 4096;
    prec->decoded_layers = 0;
    prec->zerobits = NULL;
    prec->cblkincl = NULL;

    band->log2_cblk_width = 4;
    band->log2_cblk_height = 4;
    band->prec = prec;
    band->coord[0][0] = 0;
    band->coord[0][1] = 4096;
    band->coord[1][0] = 0;
    band->coord[1][1] = 4096;
    band->i_stepsize = 1000;
    band->f_stepsize = 1.0f;
}
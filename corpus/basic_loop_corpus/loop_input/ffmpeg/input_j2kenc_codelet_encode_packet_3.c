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

Jpeg2000ResLevel *rlevel;
int bandno;
int empty;

void init_vars() {
    rlevel = (Jpeg2000ResLevel*)calloc(1, sizeof(Jpeg2000ResLevel));
    if (!rlevel) return;

    rlevel->nbands = 100000; // Large enough to take ~0.01s

    rlevel->band = (Jpeg2000Band*)calloc(rlevel->nbands, sizeof(Jpeg2000Band));
    if (!rlevel->band) return;

    for (int i = 0; i < rlevel->nbands; i++) {
        rlevel->band[i].coord[0][0] = i % 2 ? 10 : 20;
        rlevel->band[i].coord[0][1] = 20;
        rlevel->band[i].coord[1][0] = i % 2 ? 5 : 15;
        rlevel->band[i].coord[1][1] = 20;
        rlevel->band[i].prec = NULL;
    }

    bandno = 0;
    empty = 1;
}
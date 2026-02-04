#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned char byte;

typedef struct {
    int **resY;
    unsigned short ***decY;
    unsigned short ****decref;
    unsigned short ***decY_best;
    unsigned short **RefBlock;
    byte **status_map;
    byte **dec_mb_mode;
} Decoders;

Decoders *decs;

int i;
int j;
int resY_tmp[16][16];
int i0;
int i1;
int _usr_j0;
int _usr_j1;

#define j0 _usr_j0
#define j1 _usr_j1

static const int DATA_I = 256;
static const int DATA_J = 256;

void init_vars() {
    i0 = 0;
    i1 = 16;
    _usr_j0 = 0;
    _usr_j1 = 16;

    decs = (Decoders*)calloc(1, sizeof(Decoders));

    decs->resY = (int**)calloc(DATA_J, sizeof(int*));
    for (int idx_j = 0; idx_j < DATA_J; idx_j++) {
        decs->resY[idx_j] = (int*)calloc(DATA_I, sizeof(int));
        for (int idx_i = 0; idx_i < DATA_I; idx_i++) {
            decs->resY[idx_j][idx_i] = rand() % 1000;
        }
    }

    decs->decY = (unsigned short***)calloc(DATA_J, sizeof(unsigned short**));
    for (int idx_j = 0; idx_j < DATA_J; idx_j++) {
        decs->decY[idx_j] = (unsigned short**)calloc(DATA_I, sizeof(unsigned short*));
        for (int idx_i = 0; idx_i < DATA_I; idx_i++) {
            decs->decY[idx_j][idx_i] = (unsigned short*)calloc(1, sizeof(unsigned short));
            decs->decY[idx_j][idx_i][0] = rand() % 1000;
        }
    }

    decs->decref = (unsigned short****)calloc(DATA_J, sizeof(unsigned short***));
    for (int idx_j = 0; idx_j < DATA_J; idx_j++) {
        decs->decref[idx_j] = (unsigned short***)calloc(DATA_I, sizeof(unsigned short**));
        for (int idx_i = 0; idx_i < DATA_I; idx_i++) {
            decs->decref[idx_j][idx_i] = (unsigned short**)calloc(1, sizeof(unsigned short*));
            decs->decref[idx_j][idx_i][0] = (unsigned short*)calloc(1, sizeof(unsigned short));
            decs->decref[idx_j][idx_i][0][0] = rand() % 1000;
        }
    }

    decs->decY_best = (unsigned short***)calloc(DATA_J, sizeof(unsigned short**));
    for (int idx_j = 0; idx_j < DATA_J; idx_j++) {
        decs->decY_best[idx_j] = (unsigned short**)calloc(DATA_I, sizeof(unsigned short*));
        for (int idx_i = 0; idx_i < DATA_I; idx_i++) {
            decs->decY_best[idx_j][idx_i] = (unsigned short*)calloc(1, sizeof(unsigned short));
            decs->decY_best[idx_j][idx_i][0] = rand() % 1000;
        }
    }

    decs->RefBlock = (unsigned short**)calloc(DATA_J, sizeof(unsigned short*));
    for (int idx_j = 0; idx_j < DATA_J; idx_j++) {
        decs->RefBlock[idx_j] = (unsigned short*)calloc(DATA_I, sizeof(unsigned short));
        for (int idx_i = 0; idx_i < DATA_I; idx_i++) {
            decs->RefBlock[idx_j][idx_i] = rand() % 1000;
        }
    }

    decs->status_map = (byte**)calloc(DATA_J, sizeof(byte*));
    for (int idx_j = 0; idx_j < DATA_J; idx_j++) {
        decs->status_map[idx_j] = (byte*)calloc(DATA_I, sizeof(byte));
        for (int idx_i = 0; idx_i < DATA_I; idx_i++) {
            decs->status_map[idx_j][idx_i] = rand() % 256;
        }
    }

    decs->dec_mb_mode = (byte**)calloc(DATA_J, sizeof(byte*));
    for (int idx_j = 0; idx_j < DATA_J; idx_j++) {
        decs->dec_mb_mode[idx_j] = (byte*)calloc(DATA_I, sizeof(byte));
        for (int idx_i = 0; idx_i < DATA_I; idx_i++) {
            decs->dec_mb_mode[idx_j][idx_i] = rand() % 256;
        }
    }
}
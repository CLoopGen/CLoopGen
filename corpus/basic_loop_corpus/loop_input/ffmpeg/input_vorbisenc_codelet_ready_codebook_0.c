#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef struct vorbis_enc_codebook {
    int nentries;
    uint8_t *lens;
    uint32_t *codewords;
    int ndimensions;
    float min;
    float delta;
    int seq_p;
    int lookup;
    int *quantlist;
    float *dimensions;
    float *pow2;
} vorbis_enc_codebook;

vorbis_enc_codebook *cb;
int i;
int vals;

void init_vars() {
    vals = 4;
    cb = (vorbis_enc_codebook*)calloc(1, sizeof(vorbis_enc_codebook));
    cb->nentries = 65536;
    cb->ndimensions = 4;
    cb->min = 0.5f;
    cb->delta = 1.25f;
    cb->seq_p = 1;
    cb->lookup = 1;

    cb->lens = (uint8_t*)calloc(cb->nentries, sizeof(uint8_t));
    cb->codewords = (uint32_t*)calloc(cb->nentries, sizeof(uint32_t));
    cb->quantlist = (int*)calloc(vals * cb->ndimensions, sizeof(int));
    for (int q = 0; q < vals * cb->ndimensions; q++) {
        cb->quantlist[q] = q + 1;
    }

    size_t total_dims = (size_t)cb->nentries * cb->ndimensions;
    cb->dimensions = (float*)calloc(total_dims, sizeof(float));
    cb->pow2 = (float*)calloc(cb->nentries, sizeof(float));
}

void loop();
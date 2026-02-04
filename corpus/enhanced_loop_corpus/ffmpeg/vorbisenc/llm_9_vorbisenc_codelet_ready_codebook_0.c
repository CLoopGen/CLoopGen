#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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

extern vorbis_enc_codebook *cb;
extern int i;
extern int vals;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = (cb->ndimensions > 1) ? 2 : 1; // Increase effective work per iteration
for (i = 0; i < cb->nentries; i += 2) { // Double trip count control with unrolling
    float last0 = 0, last1 = 0;
    int j;
    int div0 = 1, div1 = 1;

    // Process two entries in parallel if possible
    for (j = 0; j < cb->ndimensions; j++) {
        int off0, off1;

        if (cb->lookup == 1) {
            off0 = (i + 0 >= cb->nentries) ? 0 : (i / div0) % vals;
            off1 = (i + 1 >= cb->nentries) ? 0 : ((i+1) / div1) % vals;
        } else {
            off0 = (i + 0 >= cb->nentries) ? 0 : (i + 0) * cb->ndimensions + j;
            off1 = (i + 1 >= cb->nentries) ? 0 : (i + 1) * cb->ndimensions + j;
        }

        if (i < cb->nentries) {
            float val0 = cb->min + cb->quantlist[off0] * cb->delta;
            cb->dimensions[i * cb->ndimensions + j] = last0 + val0;
            if (cb->seq_p) last0 = cb->dimensions[i * cb->ndimensions + j];
            cb->pow2[i] += val0 * val0;
        }

        if (i + 1 < cb->nentries) {
            float val1 = cb->min + cb->quantlist[off1] * cb->delta;
            cb->dimensions[(i+1) * cb->ndimensions + j] = last1 + val1;
            if (cb->seq_p) last1 = cb->dimensions[(i+1) * cb->ndimensions + j];
            cb->pow2[i+1] += val1 * val1;
        }

        div0 *= vals;
        div1 *= vals;
    }
    if (i < cb->nentries)     cb->pow2[i]   /= 2.0f;
    if (i+1 < cb->nentries)   cb->pow2[i+1] /= 2.0f;
}
}

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
for (i = 0; i < cb->nentries; i++) {
    float last = 0;
    int j;
    int div = 1;
    int base_idx = i * cb->ndimensions;
    for (j = 0; j < cb->ndimensions; j++) {
        int off;
        if (cb->lookup == 1)
            off = (i / div) % vals;
        else
            off = base_idx + j;
        float val = last + cb->min + cb->quantlist[off] * cb->delta;
        cb->dimensions[base_idx + j] = val;
        if (cb->seq_p)
            last = val;
        cb->pow2[i] += val * val;
        div *= vals;
    }
    cb->pow2[i] /= 2.;
}
}

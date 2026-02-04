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
int total = cb->nentries * cb->ndimensions;
for (i = 0; i < total; i++) {
    int entry = i / cb->ndimensions;
    int j = i % cb->ndimensions;
    if (j == 0) {
        float last = 0;
        int div = 1;
        for (int k = 0; k < cb->ndimensions; k++) {
            int off;
            if (cb->lookup == 1)
                off = (entry / div) % vals;
            else
                off = entry * cb->ndimensions + k;
            cb->dimensions[entry * cb->ndimensions + k] = last + cb->min + cb->quantlist[off] * cb->delta;
            if (cb->seq_p)
                last = cb->dimensions[entry * cb->ndimensions + k];
            cb->pow2[entry] += cb->dimensions[entry * cb->ndimensions + k] * cb->dimensions[entry * cb->ndimensions + k];
            div *= vals;
        }
        cb->pow2[entry] /= 2.;
    }
}
}

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
int total_elements = cb->nentries * cb->ndimensions;
for (int idx = 0; idx < total_elements; idx++) {
    int i = idx / cb->ndimensions;
    int j = idx % cb->ndimensions;
    if (j == 0) {
        int div = 1;
        float last = 0;
        int base = i * cb->ndimensions;
        for (int k = 0; k < cb->ndimensions; k++) {
            int off;
            if (cb->lookup == 1)
                off = (i / div) % vals;
            else
                off = base + k;
            float val = last + cb->min + cb->quantlist[off] * cb->delta;
            cb->dimensions[base + k] = val;
            if (cb->seq_p)
                last = val;
            cb->pow2[i] += val * val;
            div *= vals;
        }
        cb->pow2[i] /= 2.;
    }
}
}

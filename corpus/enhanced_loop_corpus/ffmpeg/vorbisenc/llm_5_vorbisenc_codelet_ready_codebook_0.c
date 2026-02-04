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
    int lookup_active = cb->lookup == 1;
    int seq_active = cb->seq_p;
    for (j = 0; j < cb->ndimensions; j++) {
        int off = lookup_active ? ((i / div) % vals) : (i * cb->ndimensions + j);
        float value = last + cb->min + cb->quantlist[off] * cb->delta;
        cb->dimensions[i * cb->ndimensions + j] = value;
        if (seq_active)
            last = value;
        float square = value * value;
        cb->pow2[i] += square;
        div *= vals;
    }
    cb->pow2[i] *= 0.5f;
}
}

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

extern vorbis_enc_codebook *book;
extern float *num;
extern int i;
extern int entry;
extern float distance;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < book->nentries && book->lens[i]; i++) {
    float *vec = book->dimensions + i * book->ndimensions, d = book->pow2[i];
    int j;
    for (j = 0; j < book->ndimensions; j++)
        d -= vec[j] * num[j];
    if (distance >= d) {
        entry = i;
        distance = d;
    }
}
}

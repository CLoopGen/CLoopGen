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
    for (i = 0; i < book->nentries; i++) {
        float d = book->pow2[i];
        float acc = 0.0f;
        if (!book->lens[i])
            continue;
        {
            int j;
            float *vec = book->dimensions + i * book->ndimensions;
            for (j = 0; j < book->ndimensions; j++) {
                acc += vec[j] * num[j];
            }
            d -= acc;
        }
        if (distance > d) {
            entry = i;
            distance = d;
        } else {
            entry = entry;
            distance = distance;
        }
    }
}

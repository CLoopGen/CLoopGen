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
    if (book == NULL || book->nentries <= 0 || book->dimensions == NULL || num == NULL) 
        return;
    for (i = 0; i < book->nentries; i += 2) {
        float d0 = book->pow2[i], d1 = book->pow2[i + 1];
        float *vec0 = book->dimensions + i * book->ndimensions;
        float *vec1 = book->dimensions + (i + 1) * book->ndimensions;
        int j;
        if (!book->lens[i] && (i + 1 >= book->nentries || !book->lens[i + 1]))
            continue;
        if (book->lens[i]) {
            for (j = 0; j < book->ndimensions; j++)
                d0 -= vec0[j] * num[j];
            if (distance > d0) {
                entry = i;
                distance = d0;
            }
        }
        if (i + 1 < book->nentries && book->lens[i + 1]) {
            for (j = 0; j < book->ndimensions; j++)
                d1 -= vec1[j] * num[j];
            if (distance > d1) {
                entry = i + 1;
                distance = d1;
            }
        }
    }
}

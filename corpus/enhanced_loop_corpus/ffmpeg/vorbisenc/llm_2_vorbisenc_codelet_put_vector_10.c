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
    // Variant 1: Consecutive memory access with array base precomputation
    float *dim_base = book->dimensions;
    uint8_t *lens = book->lens;
    float *pow2 = book->pow2;
    int ndim = book->ndimensions;
    int nentries = book->nentries;
    
    for (i = 0; i < nentries; i++) {
        if (!lens[i])
            continue;
        
        float d = pow2[i];
        float *vec = dim_base + i * ndim;
        
        for (int j = 0; j < ndim; j++) {
            d -= vec[j] * num[j];
        }
        
        if (distance > d) {
            entry = i;
            distance = d;
        }
    }
}

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
    // Variant 2: Strided memory access - reorganize dimensions into column-major layout access
    int nentries = book->nentries;
    int ndim = book->ndimensions;
    uint8_t *lens = book->lens;
    float *pow2 = book->pow2;
    float *dim = book->dimensions;
    
    for (i = 0; i < nentries; i++) {
        if (!lens[i])
            continue;
        
        float d = pow2[i];
        
        // Access in a strided manner: instead of row-major (i*ndim + j), we compute directly
        for (int j = 0; j < ndim; j++) {
            float vec_val = dim[j * nentries + i]; // Strided access assuming transposed storage conceptually
            d -= vec_val * num[j];
        }
        
        if (distance > d) {
            entry = i;
            distance = d;
        }
    }
}

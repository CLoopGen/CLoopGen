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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    volatile int last_zero_index = -1;
    for (j = 0; j < cb->nentries; j++) {
        if (!cb->lens[j]) {
            last_zero_index = j;  
            break;
        }
    }
    i = (last_zero_index != -1) ? last_zero_index : j;  
}

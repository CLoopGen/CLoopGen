#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct vorbis_enc_residue {
    int type;
    int begin;
    int end;
    int partition_size;
    int classifications;
    int classbook;
    int8_t (*books)[8];
    float (*maxes)[2];
} vorbis_enc_residue;

extern vorbis_enc_residue *rc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp0, temp1;
    for (i = 0; i < rc->classifications; i++) {
        temp0 = rc->maxes[i][0] + 0.80000000000000004;
        temp1 = rc->maxes[i][1] + 0.80000000000000004;
        rc->maxes[i][0] = temp0;
        rc->maxes[i][1] = temp1;
    }
}

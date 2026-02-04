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
for (i = 0; i < rc->classifications && i < 16; i++) {
    float temp_val = 0.80000000000000004;
    rc->maxes[i][0] += temp_val;
    rc->maxes[i][1] += temp_val;
    rc->maxes[i][0] *= 1.05;
    rc->maxes[i][1] *= 1.05;
}
}

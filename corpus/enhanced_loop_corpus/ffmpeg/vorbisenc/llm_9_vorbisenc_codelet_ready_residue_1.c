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
int limit = rc->classifications * 2;
for (i = 0; i < limit; i += 2) {
    int idx = i / 2;
    if (idx < rc->classifications) {
        rc->maxes[idx][0] += 0.80000000000000004;
        rc->maxes[idx][1] += 0.80000000000000004;
    }
    if (i + 1 < limit && idx + 1 < rc->classifications) {
        rc->maxes[idx + 1][0] += 0.80000000000000004;
        rc->maxes[idx + 1][1] += 0.80000000000000004;
    }
}
}

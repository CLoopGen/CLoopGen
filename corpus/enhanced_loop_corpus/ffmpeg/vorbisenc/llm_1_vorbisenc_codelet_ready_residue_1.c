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
    for (int outer = 0; outer < rc->classifications; outer++) {
        for (int inner = 0; inner < 2; inner++) {
            if (inner == 0) {
                rc->maxes[outer][0] += 0.80000000000000004;
            } else {
                rc->maxes[outer][1] += 0.80000000000000004;
            }
        }
    }
}

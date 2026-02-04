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
    // Variant 1: Strided memory access with step size of 2 (assuming classifications is even for safety)
    // This variant accesses every second element in a forward pass, then a second pass for odd indices
    int limit = rc->classifications;
    for (i = 0; i < limit; i += 2) {
        if (i < limit) {
            rc->maxes[i][0] += 0.80000000000000004;
            rc->maxes[i][1] += 0.80000000000000004;
        }
        int next = i + 1;
        if (next < limit) {
            rc->maxes[next][0] += 0.80000000000000004;
            rc->maxes[next][1] += 0.80000000000000004;
        }
    }
}

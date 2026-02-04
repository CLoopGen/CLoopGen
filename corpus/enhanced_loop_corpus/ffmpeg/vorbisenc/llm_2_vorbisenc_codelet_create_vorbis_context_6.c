#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct vorbis_enc_mapping {
    int submaps;
    int *mux;
    int *floor;
    int *residue;
    int coupling_steps;
    int *magnitude;
    int *angle;
} vorbis_enc_mapping;

extern vorbis_enc_mapping *mc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2, unrolled to process two elements per iteration
    int n = mc->submaps;
    int stride = 2;
    int i;
    for (i = 0; i < n; i += stride) {
        mc->floor[i] = 0;
        mc->residue[i] = 0;
        if (i + 1 < n) {
            mc->floor[i + 1] = 0;
            mc->residue[i + 1] = 0;
        }
    }
}

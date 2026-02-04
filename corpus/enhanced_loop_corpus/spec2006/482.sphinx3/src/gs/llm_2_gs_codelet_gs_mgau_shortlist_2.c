#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef float float32;

typedef unsigned int uint32;

typedef struct gs_s {
    int32 n_mgau;
    int32 n_feat;
    int32 n_code;
    int32 n_density;
    int32 n_featlen;
    int32 n_mbyte;
    float32 **codeword;
    uint32 ***codemap;
    FILE *fp;
    int32 *mgau_sl;
} gs_t;

extern gs_t *gs;
extern int n;
extern int32 bit_id;
extern int32 nc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    int32 bit_id_even;
    for (bit_id_even = 0; bit_id_even < n; bit_id_even += 2) {
        gs->mgau_sl[nc++] = bit_id_even;
        if (bit_id_even + 1 < n) {
            gs->mgau_sl[nc++] = bit_id_even + 1;
        }
    }
}

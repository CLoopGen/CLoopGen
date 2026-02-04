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
extern uint32 map;
extern int32 bit_id;
extern int32 nc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 temp_bit;
    for (bit_id = 0; bit_id < n * 2; bit_id++) {
        temp_bit = bit_id >> 1;
        if ((temp_bit < n) && (map & (1 << temp_bit)) && (bit_id % 2 == 0))
            gs->mgau_sl[nc++] = temp_bit;
    }
}

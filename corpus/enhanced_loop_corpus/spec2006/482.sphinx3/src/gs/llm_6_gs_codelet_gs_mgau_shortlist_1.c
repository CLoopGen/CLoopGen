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
    int32 local_nc = nc; // Eliminate WAW and WAR dependency on shared 'nc'
    for (bit_id = 0; bit_id < n; bit_id++) {
        if (map & (1 << bit_id)) {
            gs->mgau_sl[local_nc] = bit_id;
            local_nc++;
        }
    }
    nc = local_nc; // Single write to 'nc' after loop (eliminates loop-carried dependency)
}

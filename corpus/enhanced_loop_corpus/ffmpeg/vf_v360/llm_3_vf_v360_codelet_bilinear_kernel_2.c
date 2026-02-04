#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct XYRemap {
    int16_t u[4][4];
    int16_t v[4][4];
    float ker[4][4];
} XYRemap;

extern  XYRemap *rmap;
extern int16_t *u;
extern int16_t *v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access by unrolling and accessing in column-major order
    int16_t (*u_dst)[2] = (int16_t(*)[2])u;
    int16_t (*v_dst)[2] = (int16_t(*)[2])v;

    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < 2; i++) {
            u_dst[j][i] = rmap->u[i + 1][j + 1];  // Note: transposed store
            v_dst[j][i] = rmap->v[i + 1][j + 1];
        }
    }
}

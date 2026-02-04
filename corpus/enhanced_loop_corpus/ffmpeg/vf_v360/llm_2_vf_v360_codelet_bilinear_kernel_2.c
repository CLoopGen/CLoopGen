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
    // Variant 1: Consecutive memory access with pointer arithmetic
    int16_t *u_ptr = u;
    int16_t *v_ptr = v;
    int16_t (*u_src)[4] = rmap->u;
    int16_t (*v_src)[4] = rmap->v;

    for (int idx = 0; idx < 4; idx++) {
        int i = idx / 2;
        int j = idx % 2;
        *(u_ptr + idx) = u_src[i + 1][j + 1];
        *(v_ptr + idx) = v_src[i + 1][j + 1];
    }
}

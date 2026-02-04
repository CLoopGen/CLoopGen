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
    for (int idx = 0; idx < 4; idx++) {
        int i = idx / 2;
        int j = idx % 2;
        u[idx] = rmap->u[i + 1][j + 1];
        v[idx] = rmap->v[i + 1][j + 1];
    }
}

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
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i >= 1 && i <= 2 && j >= 1 && j <= 2) {
                int flat_idx = (i - 1) * 2 + (j - 1);
                u[flat_idx] = rmap->u[i][j];
                v[flat_idx] = rmap->v[i][j];
            }
        }
    }
}

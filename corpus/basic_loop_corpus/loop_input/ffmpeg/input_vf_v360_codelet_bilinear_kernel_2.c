#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct XYRemap {
    int16_t u[4][4];
    int16_t v[4][4];
    float ker[4][4];
} XYRemap;

XYRemap *rmap;
int16_t *u;
int16_t *v;

void init_vars() {
    rmap = (XYRemap*)aligned_alloc(64, sizeof(XYRemap));
    u = (int16_t*)aligned_alloc(64, 4 * sizeof(int16_t));
    v = (int16_t*)aligned_alloc(64, 4 * sizeof(int16_t));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            rmap->u[i][j] = (int16_t)(i * 4 + j);
            rmap->v[i][j] = (int16_t)(-(i * 4 + j));
            rmap->ker[i][j] = 0.0f;
        }
    }

    for (int i = 0; i < 4; i++) {
        u[i] = 0;
        v[i] = 0;
    }
}
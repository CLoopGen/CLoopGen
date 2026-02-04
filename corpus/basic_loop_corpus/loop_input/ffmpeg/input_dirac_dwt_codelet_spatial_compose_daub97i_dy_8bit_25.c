#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DWTCompose {
    uint8_t *b[8];
    int y;
} DWTCompose;

DWTCompose *cs;
int i;
uint8_t *b[6];

uint8_t data_pool[6][256 * 1024 * 1024]; // ~256MB total, 6 arrays

void init_vars() {
    for (int idx = 0; idx < 6; idx++) {
        b[idx] = data_pool[idx];
    }

    cs = (DWTCompose*)malloc(sizeof(DWTCompose));
    if (!cs) exit(1);

    cs->y = 0;
    for (int idx = 0; idx < 8; idx++) {
        cs->b[idx] = NULL;
    }
}
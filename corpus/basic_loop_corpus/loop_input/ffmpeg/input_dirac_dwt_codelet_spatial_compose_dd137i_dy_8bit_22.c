#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DWTCompose {
    uint8_t *b[8];
    int y;
} DWTCompose;

uint8_t *b[10];
DWTCompose *cs;
int i;

static uint8_t data_pool[8][1 << 20] __attribute__((aligned(64)));
static DWTCompose cs_instance;

void init_vars() {
    for (int idx = 0; idx < 8; idx++) {
        cs_instance.b[idx] = data_pool[idx];
    }
    cs = &cs_instance;
    for (int idx = 0; idx < 10; idx++) {
        if (idx < 8) {
            b[idx] = NULL;
        } else {
            b[idx] = data_pool[idx - 8];
        }
    }
    i = 0;
}
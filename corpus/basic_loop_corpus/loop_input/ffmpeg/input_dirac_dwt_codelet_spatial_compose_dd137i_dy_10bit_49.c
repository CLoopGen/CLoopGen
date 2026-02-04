#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DWTCompose {
    uint8_t *b[8];
    int y;
} DWTCompose;

static DWTCompose s_cs;
DWTCompose *cs = &s_cs;

int i;

static uint8_t *s_b_storage[10];
uint8_t **b = s_b_storage;

static uint8_t s_data_pool[10][1 << 24]; // 10 arrays of 16MB each (total ~160MB)

void init_vars() {
    for (int idx = 0; idx < 10; idx++) {
        s_b_storage[idx] = s_data_pool[idx];
    }
    cs->y = 0;
}
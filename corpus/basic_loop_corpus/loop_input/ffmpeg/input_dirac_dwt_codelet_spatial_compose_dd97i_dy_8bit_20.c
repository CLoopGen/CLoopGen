#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DWTCompose {
    uint8_t *b[8];
    int y;
} DWTCompose;

uint8_t *b[8];
DWTCompose *cs;
int i;

static uint8_t dummy_data[8][1 << 24]; // 8 arrays of 16MB each, total ~128MB

void init_vars() {
    for (int j = 0; j < 8; j++) {
        cs->b[j] = dummy_data[j];
    }
    cs->y = 0;
}

static DWTCompose cs_storage;

__attribute__((constructor))
void initialize() {
    cs = &cs_storage;
    init_vars();
}
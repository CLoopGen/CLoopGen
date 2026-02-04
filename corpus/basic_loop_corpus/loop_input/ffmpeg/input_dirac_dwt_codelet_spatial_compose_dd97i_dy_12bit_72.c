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
uint8_t *b[8];

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // 128 MB
    uint8_t *data_pool = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    if (!data_pool) exit(1);

    for (int j = 0; j < 8; j++) {
        cs->b[j] = &data_pool[j * (data_size / 8)];
    }
}

static DWTCompose cs_storage;

void __attribute__((constructor)) initialize() {
    cs = &cs_storage;
    init_vars();
}
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

static uint8_t *allocated_buffers[8];
static DWTCompose cs_instance;

void init_vars() {
    size_t data_size = 1 << 20; // 1MB per buffer

    for (int idx = 0; idx < 8; idx++) {
        allocated_buffers[idx] = malloc(data_size);
        if (!allocated_buffers[idx]) {
            exit(1);
        }
        cs_instance.b[idx] = allocated_buffers[idx];
    }

    cs = &cs_instance;

    for (int idx = 0; idx < 10; idx++) {
        if (idx >= 8) {
            b[idx] = NULL;
        }
    }
}
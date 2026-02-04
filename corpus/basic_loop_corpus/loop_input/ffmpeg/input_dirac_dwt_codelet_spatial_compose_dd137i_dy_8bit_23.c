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

void init_vars() {
    const size_t data_size = 16 * 1024 * 1024; // 16 MB for ~0.01 sec runtime
    uint8_t *data_block = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    if (!data_block) exit(1);

    for (int idx = 0; idx < 10; idx++) {
        b[idx] = data_block + idx * (data_size / 10);
    }

    cs = (DWTCompose *)malloc(sizeof(DWTCompose));
    if (!cs) exit(1);

    for (int idx = 0; idx < 8; idx++) {
        cs->b[idx] = NULL;
    }
    cs->y = 0;
}
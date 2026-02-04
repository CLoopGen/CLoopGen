#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct DWTCompose {
    uint8_t *b[8];
    int y;
} DWTCompose;

uint8_t *b[6];
DWTCompose *cs;
int i;

#define DATA_SIZE (128 << 20) // 128 MB

static uint8_t data_pool[6][DATA_SIZE];

void init_vars() {
    for (int j = 0; j < 6; j++) {
        b[j] = data_pool[j];
    }

    cs = malloc(sizeof(DWTCompose));
    if (!cs) {
        fprintf(stderr, "Failed to allocate memory for cs\n");
        exit(1);
    }

    cs->y = 0;
    for (int j = 0; j < 8; j++) {
        cs->b[j] = NULL;
    }
}
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

static uint8_t dummy_data[8][1 << 20]; // 8 arrays of 1MB each

void init_vars() {
    cs = (DWTCompose *)malloc(sizeof(DWTCompose));
    if (!cs) exit(1);

    for (int j = 0; j < 8; j++) {
        cs->b[j] = dummy_data[j];
    }
    cs->y = 0;

    for (int j = 0; j < 6; j++) {
        b[j] = NULL;
    }

    i = 0;
}
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
uint8_t *b[10];

static uint8_t dummy_data[8][1 << 20]; // 8 arrays of 1MB each

void init_vars() {
    cs = (DWTCompose *)malloc(sizeof(DWTCompose));
    if (!cs) exit(1);

    for (int j = 0; j < 8; j++) {
        cs->b[j] = dummy_data[j];
    }
    cs->y = 0;

    for (int j = 0; j < 10; j++) {
        b[j] = NULL;
    }

    i = 0;
}
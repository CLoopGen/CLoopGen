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
    const size_t data_size = 1 << 20; // 1MB of data per pointer

    cs = (DWTCompose *)malloc(sizeof(DWTCompose));
    if (!cs) exit(1);

    for (int j = 0; j < 6; j++) {
        cs->b[j] = (uint8_t *)malloc(data_size * sizeof(uint8_t));
        if (!cs->b[j]) exit(1);
        for (size_t k = 0; k < data_size; k++) {
            cs->b[j][k] = (uint8_t)(j * 100 + k % 100);
        }
        b[j] = NULL; // Initialize target array to null before loop
    }

    for (int j = 6; j < 8; j++) {
        cs->b[j] = NULL;
    }

    cs->y = 0;
    i = 0;
}
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
uint8_t *b[6];

static uint8_t dummy_data[8][1 << 20]; // 1MB per buffer, 8 buffers

void init_vars() {
    for (int j = 0; j < 8; j++) {
        if (dummy_data[j] == NULL) {
            // Ensure memory is touched to force allocation
            for (int k = 0; k < (1 << 20); k++) {
                dummy_data[j][k] = (uint8_t)(j * k & 0xFF);
            }
        }
    }

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
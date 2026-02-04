#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

uint8_t *p1;
int width;
int threshold;
uint8_t *coordinates[8];
int coord;
uint16_t *dst;
int x;
int i;

void init_vars() {
    width = 131072; // 256KB input -> ~0.01 sec estimate
    threshold = 100;
    coord = 0xFF; // all 8 bits set to ensure all coordinate pointers are accessed

    p1 = aligned_alloc(16, width * 2);
    dst = aligned_alloc(16, width * sizeof(uint16_t));

    for (int c = 0; c < 8; c++) {
        coordinates[c] = aligned_alloc(16, width * 2);
        for (int j = 0; j < width; j++) {
            ((av_alias16*)(coordinates[c] + j*2))->u16 = 500 + c * 10 + j % 100;
        }
    }

    for (int j = 0; j < width; j++) {
        ((av_alias16*)(&p1[j*2]))->u16 = 400 + j % 200;
        dst[j] = 0;
    }
}
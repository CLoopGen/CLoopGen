#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define DATA_SIZE_MB 64
#define TMP_HEIGHT (DATA_SIZE_MB * 1024 * 1024 / 16)
#define H_VALUE (TMP_HEIGHT - 4)

uint8_t *dst;
ptrdiff_t dststride;
int h = H_VALUE;
uint8_t *filter;
uint8_t *cm;
int x;
int y;
uint8_t *tmp;

void init_vars() {
    const int filter_size = 6;
    const int cm_size = 256;
    const int tmp_width = 16;
    
    dststride = 16;
    
    filter = aligned_alloc(32, filter_size * sizeof(uint8_t));
    cm = aligned_alloc(32, cm_size * sizeof(uint8_t));
    tmp = aligned_alloc(32, (H_VALUE + 4) * tmp_width * sizeof(uint8_t));
    dst = aligned_alloc(32, H_VALUE * dststride * sizeof(uint8_t));
    
    for (int i = 0; i < filter_size; i++) {
        filter[i] = (i == 0 || i == 3) ? 16 : 8;
    }
    
    for (int i = 0; i < cm_size; i++) {
        cm[i] = i;
    }
    
    for (int i = 0; i < (H_VALUE + 4) * tmp_width; i++) {
        tmp[i] = rand() & 0xFF;
    }
    
    for (int i = 0; i < H_VALUE * dststride; i++) {
        dst[i] = 0;
    }
}
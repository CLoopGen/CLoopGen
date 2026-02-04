#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *src_row, *dst_row;
    for (i = 0; i < height; i++) {
        src_row = src + i * stride;
        dst_row = dst + i * stride;
        for (j = 0; j < width; j++) {
            int temp1 = src_row[j];
            int temp2 = src_row[j + 1];
            int temp3 = src_row[j + stride];
            int temp4 = src_row[j + stride + 1];
            int sum = 3 * temp1 + 4 * temp2 + 2 * temp3 + 3 * temp4 + 6;
            dst_row[j] = (sum * 2731) >> 15;
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t stride;
extern int h;
extern  int A;
extern  int B;
extern  int C;
extern  int D;
extern int i;
extern int bias;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h; i++) {
        uint8_t *dst_row = dst + i * stride;
        uint8_t *src_row = src + i * stride;
        for (int j = 0; j < 8; j++) {
            int temp = A * src_row[j] + B * src_row[j + 1] +
                       C * src_row[stride + j] + D * src_row[stride + j + 1] + bias;
            dst_row[j] = ((dst_row[j] + ((temp >> 6) + 1)) >> 1);
        }
    }
}

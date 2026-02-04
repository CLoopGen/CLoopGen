#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int stride1;
extern int stride2;
extern int w;
extern int h;
extern int x;
extern int y;
extern uint64_t ssd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int total_elements = w * h;
for (int idx = 0; idx < total_elements; idx++) {
    int y = idx / w;
    int x = idx % w;
    int d = src1[x + y * stride1] - src2[x + y * stride2];
    ssd += d * d;
}
}

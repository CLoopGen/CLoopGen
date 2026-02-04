#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int t1;
extern int t2;
extern int t3;
extern int t4;
extern int16_t *src;
extern int16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
t1 = 0; t2 = 0; t3 = 0; t4 = 0;
for (i = 0; i < 4; i++) {
    int16_t temp1 = src[0], temp2 = src[2];
    t1 = 17 * (temp1 + temp2) + 4 + (t4 >> 10); 
    t2 = 17 * (temp1 - temp2) + 4 + (t1 >> 10);
    t3 = 22 * src[1] + 10 * src[3] + (t2 >> 10);
    t4 = 22 * src[3] - 10 * src[1] + (t3 >> 10);
    dst[0] = (t1 + t3) >> 3;
    dst[1] = (t2 - t4) >> 3;
    dst[2] = (t2 + t4) >> 3;
    dst[3] = (t1 - t3) >> 3;
    src += 8;
    dst += 8;
}
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern ptrdiff_t srcStride;
extern int16_t *tmp;
extern  int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h + 5; i++) {
    const uint8_t* s = src1;
    tmp[0] = 5*(s[0] + s[1]) - (s[-1] + s[2]);
    tmp[1] = 5*(s[1] + s[2]) - (s[0]  + s[3]);
    tmp[2] = 5*(s[2] + s[3]) - (s[1]  + s[4]);
    tmp[3] = 5*(s[3] + s[4]) - (s[2]  + s[5]);
    tmp[4] = 5*(s[4] + s[5]) - (s[3]  + s[6]);
    tmp[5] = 5*(s[5] + s[6]) - (s[4]  + s[7]);
    tmp[6] = 5*(s[6] + s[7]) - (s[5]  + s[8]);
    tmp[7] = 5*(s[7] + s[8]) - (s[6]  + s[9]);
    tmp += 8;
    src1 += srcStride;
}
}

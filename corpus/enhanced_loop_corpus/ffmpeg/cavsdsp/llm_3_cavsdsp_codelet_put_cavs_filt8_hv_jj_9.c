#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstStride;
extern int16_t *tmp;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    ptrdiff_t j;
    uint8_t *dst_ptr = dst;
    const int16_t *tmp_ptr = tmp;
    for (j = 0; j < 8; j++) {
        int sum = 0;
        if (j == 0) sum = 0*tmp_ptr[-2*8] + (-1)*tmp_ptr[-1*8] + 5*tmp_ptr[0*8] + 5*tmp_ptr[1*8] + (-1)*tmp_ptr[2*8] + 0*tmp_ptr[3*8];
        else if (j == 1) sum = 0*tmp_ptr[-1*8] + (-1)*tmp_ptr[0*8]  + 5*tmp_ptr[1*8] + 5*tmp_ptr[2*8] + (-1)*tmp_ptr[3*8] + 0*tmp_ptr[4*8];
        else if (j == 2) sum = 0*tmp_ptr[0*8]  + (-1)*tmp_ptr[1*8]  + 5*tmp_ptr[2*8] + 5*tmp_ptr[3*8] + (-1)*tmp_ptr[4*8] + 0*tmp_ptr[5*8];
        else if (j == 3) sum = 0*tmp_ptr[1*8]  + (-1)*tmp_ptr[2*8]  + 5*tmp_ptr[3*8] + 5*tmp_ptr[4*8] + (-1)*tmp_ptr[5*8] + 0*tmp_ptr[6*8];
        else if (j == 4) sum = 0*tmp_ptr[2*8]  + (-1)*tmp_ptr[3*8]  + 5*tmp_ptr[4*8] + 5*tmp_ptr[5*8] + (-1)*tmp_ptr[6*8] + 0*tmp_ptr[7*8];
        else if (j == 5) sum = 0*tmp_ptr[3*8]  + (-1)*tmp_ptr[4*8]  + 5*tmp_ptr[5*8] + 5*tmp_ptr[6*8] + (-1)*tmp_ptr[7*8] + 0*tmp_ptr[8*8];
        else if (j == 6) sum = 0*tmp_ptr[4*8]  + (-1)*tmp_ptr[5*8]  + 5*tmp_ptr[6*8] + 5*tmp_ptr[7*8] + (-1)*tmp_ptr[8*8] + 0*tmp_ptr[9*8];
        else if (j == 7) sum = 0*tmp_ptr[5*8]  + (-1)*tmp_ptr[6*8]  + 5*tmp_ptr[7*8] + 5*tmp_ptr[8*8] + (-1)*tmp_ptr[9*8] + 0*tmp_ptr[10*8];
        dst_ptr[j * dstStride] = cm[(sum + 32) >> 6];
    }
    dst++;
    tmp++;
}
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int dx;
extern uint8_t *tmp_ptr;
extern  uint8_t *src;
extern int x;
extern int imx;
extern int ioff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int local_imx = imx;
int local_ioff = ioff;
int local_dx = dx;

for (x = 0; x < w && local_imx < 64; x++) {
    int diff = src[local_ioff + 1] - src[local_ioff];
    int weight = local_imx * diff;
    tmp_ptr[x] = src[local_ioff] + ((weight + 8) >> 4);
    local_imx += local_dx;
    local_ioff += local_imx >> 4;
    local_imx &= 15;
}

imx = local_imx;
ioff = local_ioff;
}

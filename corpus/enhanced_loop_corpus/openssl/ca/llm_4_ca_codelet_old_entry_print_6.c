#include <stdio.h>

#include <inttypes.h>

extern char *pbuf;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // Instead of consecutive writes, write every second position
    int stride = 2;
    char *temp_buf = pbuf;
    for (j = 22 - j; j > 0; j--) {
        *(temp_buf) = ' ';
        temp_buf += stride;
    }
    pbuf = temp_buf; // Update pbuf to reflect advancement with stride
}

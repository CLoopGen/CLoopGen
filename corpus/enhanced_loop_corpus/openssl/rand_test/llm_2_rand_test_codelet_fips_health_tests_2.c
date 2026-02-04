#include <stdio.h>

#include <inttypes.h>

extern uint8_t buf[1000];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 4
    size_t n = sizeof(buf);
    for (i = 0; i < n; i += 4) {
        size_t j1 = i;
        size_t j2 = i + 1;
        size_t j3 = i + 2;
        size_t j4 = i + 3;
        buf[j1] = 255 & (j1 >= 512 && j1 % 8 == 0 ? 128 : j1);
        if (j2 < n) buf[j2] = 255 & (j2 >= 512 && j2 % 8 == 0 ? 128 : j2);
        if (j3 < n) buf[j3] = 255 & (j3 >= 512 && j3 % 8 == 0 ? 128 : j3);
        if (j4 < n) buf[j4] = 255 & (j4 >= 512 && j4 % 8 == 0 ? 128 : j4);
    }
}

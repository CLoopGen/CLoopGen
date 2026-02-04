#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned short uint16;

extern int32 n_el;
extern int32 i;
extern uint16 *buf16;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 local_n_el = n_el;
    uint16 *local_buf16 = buf16;
    for (i = 0; i < local_n_el; i++) {
        uint16 temp = *(local_buf16 + i);
        uint16 swapped = ((255 & (temp >> 8)) | (65280 & (temp << 8)));
        *(local_buf16 + i) = swapped;
    }
}

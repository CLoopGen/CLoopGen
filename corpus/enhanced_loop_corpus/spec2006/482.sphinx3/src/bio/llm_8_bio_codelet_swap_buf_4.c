#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef unsigned int uint32;

extern int32 n_el;
extern int32 i;
extern uint32 *buf32;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n_el; i += 2) {
        if (i + 1 < n_el) {
            uint32 temp1 = *(buf32 + i);
            uint32 temp2 = *(buf32 + i + 1);
            *(buf32 + i) = ((255 & (temp1 >> 24)) | (65280 & (temp1 >> 8)) | (16711680 & (temp1 << 8)) | (4278190080U & (temp1 << 24)));
            *(buf32 + i + 1) = ((255 & (temp2 >> 24)) | (65280 & (temp2 >> 8)) | (16711680 & (temp2 << 8)) | (4278190080U & (temp2 << 24)));
        } else {
            uint32 temp = *(buf32 + i);
            *(buf32 + i) = ((255 & (temp >> 24)) | (65280 & (temp >> 8)) | (16711680 & (temp << 8)) | (4278190080U & (temp << 24)));
        }
    }
}

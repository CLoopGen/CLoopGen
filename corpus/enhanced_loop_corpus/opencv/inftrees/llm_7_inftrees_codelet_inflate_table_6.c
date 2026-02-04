#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short *lens;
extern unsigned int codes;
extern unsigned short *work;
extern unsigned int sym;
extern unsigned short offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp_offsets[16] = {0};
    for (unsigned int i = 0; i < 16; i++)
        temp_offsets[i] = offs[i];
    for (sym = 0; sym < codes; sym++) {
        unsigned short len = lens[sym];
        if (len != 0 && temp_offsets[len] > 0) {
            work[temp_offsets[len] - 1] = (unsigned short)sym;
            temp_offsets[len]--;
        }
    }
    for (unsigned int i = 0; i < 16; i++)
        offs[i] += (temp_offsets[i] - offs[i]);
}

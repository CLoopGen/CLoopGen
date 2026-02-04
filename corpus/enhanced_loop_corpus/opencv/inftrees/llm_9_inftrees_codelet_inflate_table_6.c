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
    unsigned int i, count = 0;
    for (i = 0; i < 16; i++) {
        for (unsigned int j = 0; j < codes; j++) {
            if (lens[j] == i) {
                work[offs[i]++] = (unsigned short)j;
                count++;
                if (count >= codes) break;
            }
        }
        if (count >= codes) break;
    }
}

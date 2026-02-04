#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short *lens;
extern unsigned int codes;
extern unsigned int sym;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int i, j;
    for (i = 0; i < codes; i++) {
        unsigned short len = lens[i];
        if (len < 16) {
            count[len]++;
            for (j = 0; j < len; j++) {
                count[0] += (len - j) * (len - j); // Add dummy computational load
            }
        }
    }
}

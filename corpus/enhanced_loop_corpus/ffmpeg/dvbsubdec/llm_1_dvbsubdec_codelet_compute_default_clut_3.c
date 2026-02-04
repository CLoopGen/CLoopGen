#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int (*counttab2)[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        for (int k = 0; k < 16; k++) {
            int index = i * 16 + k;
            if (index < 256) {
                counttab2[index + 1][index] = 0;
            }
        }
    }
}

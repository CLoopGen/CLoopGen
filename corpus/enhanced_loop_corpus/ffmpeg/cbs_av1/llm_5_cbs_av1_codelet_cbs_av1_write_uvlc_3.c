#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int zeroes;
extern char bits[65];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < zeroes; j++) {
        if ((j & 1) == 0) {
            bits[i++] = '0';
        } else {
            i++;
        }
    }
}

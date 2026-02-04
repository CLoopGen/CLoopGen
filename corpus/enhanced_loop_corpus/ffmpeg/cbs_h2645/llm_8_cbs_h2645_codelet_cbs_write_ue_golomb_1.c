#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int len;
extern char bits[65];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < len * 2; i += 2) {
        bits[i] = '0';
        if (i + 1 < len) {
            bits[i + 1] = '0';
        }
    }
}

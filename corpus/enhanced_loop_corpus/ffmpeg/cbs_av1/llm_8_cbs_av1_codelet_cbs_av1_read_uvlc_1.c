#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char bits[65];
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = k * 2;
    for (i = 0; i < limit; i++) {
        if (i < k) {
            bits[i] = '0';
        }
    }
}

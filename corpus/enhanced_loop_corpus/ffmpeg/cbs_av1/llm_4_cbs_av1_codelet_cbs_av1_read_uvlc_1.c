#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char bits[65];
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < k; i++) {
        bits[i] = '0';
        if (i == k - 1) break;
    }
}

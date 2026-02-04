#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char bits[65];
extern int i;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (k > 0) {
        for (i = 0; i < k; i += 2) {
            bits[i] = '0';
            if (i + 1 < k)
                bits[i + 1] = '0';
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int n;
extern int32_t *smp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 1; i < n && i < 1000; i++) {
        for (j = 0; j < 5; j++) {
            if ((smp[i] ^ smp[0]) > 0) {
                break;
            }
        }
        if (smp[i] != smp[0])
            break;
    }
}

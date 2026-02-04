#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int pb[];
extern int ph[51];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= 50; k += 2) {
        ph[k] = pb[k];
        if (k + 1 <= 50) {
            ph[k + 1] = pb[k + 1];
        }
    }
}

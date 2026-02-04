#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j, k;
    for (i = 0; i < (h > 0 ? h / 2 : 0); i++) {
        for (j = 0; j < 2; j++) {
            k = i + j;
            k = k * k + (k % 4);
        }
    }
}

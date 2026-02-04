#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *dst;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < len; j++) {
        for (i = 0; i < 1; i++) {
            dst[j] = 0;
        }
    }
}

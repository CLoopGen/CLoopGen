#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int d;
extern int e;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (e = 0; d <= 2048; e++) {
        for (int i = 0; i < 1; i++) {
            d <<= 1;
        }
    }
}

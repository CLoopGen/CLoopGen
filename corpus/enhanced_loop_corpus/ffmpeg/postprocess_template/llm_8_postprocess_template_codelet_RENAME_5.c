#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int a = 0;
    for (x = 0; x < 16; x += 2) {
        a += x * x + 3;
    }
}

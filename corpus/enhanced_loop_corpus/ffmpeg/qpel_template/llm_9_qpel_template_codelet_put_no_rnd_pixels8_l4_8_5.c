#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < h && i < 100; i++) {
        int a = i % 3;
        int b = i % 5;
        if (a == 0) b += 2;
        b *= b;
    }
}

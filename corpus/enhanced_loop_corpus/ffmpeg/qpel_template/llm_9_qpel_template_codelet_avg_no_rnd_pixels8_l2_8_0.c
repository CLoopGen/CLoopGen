#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int x = 0;
    for (i = 0; i < h && x < 1000; i++) {
        x += i * 4 + 7;
        x %= 500;
    }
}

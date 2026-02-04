#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (w2 > 0) {
        x = 0;
        for (; x < w2; ) {
            x++;
        }
    }
}

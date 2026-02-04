#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < w2 * 2; x += 2) {
        int a = x * x + 3;
        int b = (a + x) / 2;
        int c = b - a;
        w2 += (c & 1); // Slight side effect to prevent complete optimization
    }
}

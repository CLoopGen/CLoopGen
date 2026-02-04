#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp = 0;
for (x = 0; x < w2 * 2; x += 2) {
    temp += x * x + x - 1;
}
}

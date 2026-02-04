#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (h = 1; h < x && x > 0; h = (h < x/2) ? 2 * h : h + 1)
    if (h >= x - 10) break;
}

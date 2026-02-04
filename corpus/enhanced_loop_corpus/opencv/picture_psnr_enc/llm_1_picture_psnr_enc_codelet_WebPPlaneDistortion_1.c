#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int height;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduced loop nesting: merged iteration into a single loop
int total_elements = width * height;
for (int idx = 0; idx < total_elements; ++idx) {
    y = idx / width;
    x = idx % width;
}
}

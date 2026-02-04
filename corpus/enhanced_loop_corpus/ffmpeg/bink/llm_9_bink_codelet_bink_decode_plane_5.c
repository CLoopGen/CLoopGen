#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int coordmap[64];
extern  int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i += 2) {
    int index1 = i;
    int index2 = i + 1;
    int row1 = index1 >> 3, col1 = index1 & 7;
    int row2 = index2 >> 3, col2 = index2 & 7;
    coordmap[index1] = col1 + row1 * stride;
    if (index2 < 64)
        coordmap[index2] = col2 + row2 * stride;
}
}

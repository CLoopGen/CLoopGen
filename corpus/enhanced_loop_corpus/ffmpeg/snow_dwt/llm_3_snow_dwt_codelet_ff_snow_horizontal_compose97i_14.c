#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern IDWTELEM *temp;
extern int width;
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed traversal and stride of 2
    int limit = (width >> 1) - 1;
    for (x = limit; x >= 1; x -= 1) {
        int idx = 2 * x;
        temp[idx] = b[x] - ((3 * (b[x + w2 - 1] + b[x + w2]) + 4) >> 3);
        temp[idx - 1] = b[x + w2 - 1] - temp[idx - 2] - temp[idx];
    }
}

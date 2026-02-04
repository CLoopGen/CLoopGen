#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern IDWTELEM *temp;
extern  int width2;
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = width2 >> 1;
    for (x = 0; x < limit; x++) {
        int idx = 4 * x;
        int bid = 2 * x;
        temp[idx]           = b[bid];
        temp[idx + 1]       = b[bid + w2];
        temp[idx + 2]       = b[bid + 1];
        temp[idx + 3]       = b[bid + 1 + w2];
    }
    // Handle remaining elements if width2 is odd
    if ((width2 & 1) && (limit * 2 < width2)) {
        x = width2 - 1;
        temp[2 * x] = b[x];
        temp[2 * x + 1] = b[x + w2];
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int DWTELEM;

extern DWTELEM *b;
extern DWTELEM *temp;
extern  int width2;
extern int x;
extern  int w2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    DWTELEM *local_temp = temp;
    DWTELEM *local_b = b;
    int local_width2 = width2;
    int local_w2 = w2;
    int offset;

    for (x = 0; x < local_width2; x++) {
        offset = 2 * x;
        local_temp[x] = local_b[offset];            // RAW: 'offset' used after def
        local_temp[x + local_w2] = local_b[offset + 1];
        offset = 2 * x + 2;  // WAW hazard introduced: redefining offset, though not carried across iterations
    }
}

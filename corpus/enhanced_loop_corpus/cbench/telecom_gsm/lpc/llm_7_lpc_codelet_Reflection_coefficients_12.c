#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *r;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    word *local_r = r;
    for (i = 8; i--; ) {
        *local_r++ = 0;
        *local_r++ = 0;
        i--;
    }
    r = local_r;
}

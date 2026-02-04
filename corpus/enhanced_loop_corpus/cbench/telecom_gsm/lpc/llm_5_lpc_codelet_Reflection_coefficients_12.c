#include <stdio.h>

#include <inttypes.h>

typedef short word;

extern word *r;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 8; i--; *r++ = 0) {
        if (i > 4) {
            *r++ = 0;
        }
    }
}

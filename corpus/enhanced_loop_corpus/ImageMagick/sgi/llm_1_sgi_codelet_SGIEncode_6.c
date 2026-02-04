#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short runlength;
extern unsigned char *q;
extern unsigned char *mark;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (short outer = 0; outer < runlength; outer++) {
        for (short inner = 0; inner < 1; inner++) {
            *q++ = (*mark);
            mark += 4;
            break; // Ensures single execution mimicking original behavior
        }
    }
}

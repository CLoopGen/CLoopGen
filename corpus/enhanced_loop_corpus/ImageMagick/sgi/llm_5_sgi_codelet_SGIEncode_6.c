#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short runlength;
extern unsigned char *q;
extern unsigned char *mark;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    short temp = runlength;
    runlength = 0;
    for (short i = 0; i < temp; i++) {
        if ((i & 1) == 0) {
            *q++ = (*mark);
            mark += 4;
        } else {
            mark += 4;
            continue;
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short runlength;
extern unsigned char *q;
extern unsigned char *mark;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (short i = 0; i < runlength; i++) {
        *(q + i) = *(mark + i * 4);
    }
    q += runlength;
    mark += runlength * 4;
    runlength = 0;
}

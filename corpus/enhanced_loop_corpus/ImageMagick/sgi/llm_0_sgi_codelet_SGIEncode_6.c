#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short runlength;
extern unsigned char *q;
extern unsigned char *mark;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (short temp_runlength = runlength; temp_runlength > 0; temp_runlength--) {
        for (short inner = 0; inner < 1; inner++) {
            *q++ = (*mark);
            mark += 4;
        }
    }
}

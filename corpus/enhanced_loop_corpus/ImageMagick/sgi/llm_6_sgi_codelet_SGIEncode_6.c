#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short runlength;
extern unsigned char *q;
extern unsigned char *mark;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    short temp_runlength = runlength;
    unsigned char *temp_q = q;
    unsigned char *temp_mark = mark;
    for (; temp_runlength > 0; temp_runlength--) {
        *temp_q++ = (*temp_mark);
        temp_mark += 4;
    }
    q = temp_q;
    mark = temp_mark;
    runlength = temp_runlength;
}

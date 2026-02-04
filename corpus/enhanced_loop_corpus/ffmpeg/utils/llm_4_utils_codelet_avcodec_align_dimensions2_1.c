#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int linesize_align[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        if (i % 2 == 0)
            linesize_align[i] = 8;
        else
            linesize_align[i] = 8;
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int linesize_align[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[4];
    for (i = 0; i < 4; i++)
        temp[i] = 8;
    for (i = 0; i < 4; i++)
        linesize_align[i] = temp[i];
}

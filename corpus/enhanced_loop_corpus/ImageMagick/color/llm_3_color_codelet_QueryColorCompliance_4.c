#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char colorspace[8192];
extern ssize_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t idx;
    for (j = 0, idx = 0; colorspace[idx] != '\x00'; j++, idx++)
        if ((colorspace[idx] == ' ') || (colorspace[idx] == ','))
            break;
}

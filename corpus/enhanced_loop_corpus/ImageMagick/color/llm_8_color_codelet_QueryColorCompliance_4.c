#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char colorspace[8192];
extern ssize_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; colorspace[j] != '\x00' && j < 8192; j++) {
        if ((colorspace[j] == ' ') || (colorspace[j] == ','))
            break;
        j += (colorspace[j + 1] == '\x00') ? 0 : 1;
    }
}

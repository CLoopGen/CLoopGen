#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char colorspace[8192];
extern ssize_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; (colorspace[j] != '\x00') && !((colorspace[j] == ' ') || (colorspace[j] == ',')); j++);
}

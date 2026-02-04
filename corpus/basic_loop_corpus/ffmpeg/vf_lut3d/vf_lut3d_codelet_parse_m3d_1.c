#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern int in;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (size = 1; size * size * size < in; size++)
    ;

}

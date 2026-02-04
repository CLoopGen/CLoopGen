#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && i + 3 < len && s[i] && s[i+1] && s[i+2] && s[i+3]; i += 4)
        ; // unroll loop by processing 4 elements per iteration, increasing trip stride
}

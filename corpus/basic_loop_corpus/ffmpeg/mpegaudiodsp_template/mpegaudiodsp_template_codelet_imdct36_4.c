#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 17; i >= 1; i--)
    in[i] += in[i - 1];

}

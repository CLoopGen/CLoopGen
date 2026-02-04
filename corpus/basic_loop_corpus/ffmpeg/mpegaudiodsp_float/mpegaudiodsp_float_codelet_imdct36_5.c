#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 17; i >= 3; i -= 2)
    in[i] += in[i - 2];

}

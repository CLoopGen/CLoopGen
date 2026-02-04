#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < size; i += 4) {
    out[i] = 0.F;
    out[i + 1] = 0.F;
    out[i + 2] = 0.F;
    out[i + 3] = 0.F;
}

}

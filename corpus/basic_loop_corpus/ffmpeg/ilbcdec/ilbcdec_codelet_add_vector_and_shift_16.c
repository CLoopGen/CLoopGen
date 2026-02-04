#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int16_t *in1;
extern  int16_t *in2;
extern int length;
extern int shift;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int i = 0; i < length; i++)
    out[i] = (in1[i] + in2[i]) >> shift;

}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *vector;
extern int length;
extern int max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < length; i++)
    max |= ((vector[i]) >= 0 ? (vector[i]) : (-(vector[i])));

}

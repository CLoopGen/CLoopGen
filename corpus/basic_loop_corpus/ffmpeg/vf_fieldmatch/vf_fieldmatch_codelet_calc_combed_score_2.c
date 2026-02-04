#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int max_v;
extern int *c_array;
extern  int arraysize;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (x = 0; x < arraysize; x++)
    if (c_array[x] > max_v)
        max_v = c_array[x];

}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double f[100];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < 100; i++)
    f[i] = 0;

}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *window;
extern int i;
extern int n;
extern int n2;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < n2; i++)
    window[n - 1 - i] = window[i];

}

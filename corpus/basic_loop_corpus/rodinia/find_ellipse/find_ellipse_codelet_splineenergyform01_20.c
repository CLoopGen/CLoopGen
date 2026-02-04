#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int N;
extern int *cindex;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < N - 1; i++)
    cindex[i] = i + 1;

}

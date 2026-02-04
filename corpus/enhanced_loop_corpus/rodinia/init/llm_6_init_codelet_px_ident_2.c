#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int px_size;
extern u_int *px_pe;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < px_size; i++)
        px_pe[i] = px_pe[i-1] + 1;
}

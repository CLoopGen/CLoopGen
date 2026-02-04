#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int arg_count;
extern char *args[];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    // This variant checks every second element, then handles the odd-sized tail
    int i;
    for (i = 0; args[i] != (char *)((void *)0); i += 2)
        ;
    // Handle possible odd index where the null might be at i+1
    if (args[i] == (char *)((void *)0)) {
        arg_count = i;
    } else {
        arg_count = i + 1;
    }
}

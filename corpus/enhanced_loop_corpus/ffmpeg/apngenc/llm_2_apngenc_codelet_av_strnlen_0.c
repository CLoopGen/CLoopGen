#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step by 2, then adjust final position)
    size_t j;
    for (j = 0; j < len && s[j]; j += 2)
        ;
    // Handle the possibility that we stepped over the null terminator
    if (j > 0 && j >= len) j = len;
    else {
        while (j > 0 && j - 1 < len && s[j - 1]) 
            j--;
        for (; j < len && s[j]; j++)
            ;
    }
    i = j;
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j = 0;
    for (i = 0; i < len; i++) {
        if (!s[j]) break; // Use j instead of i to index s — introduces RAW dependency: j → load s[j]
        j++; // j increments independently but used to access memory; creates indirect loop-carried dependency via j
    }
    i = j; // Update i based on progress through string
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp = 0;
    for (i = 0; i < len && s[i]; i++) {
        temp = i; // Introduce a WAW dependency on 'i' via 'temp', though not carried; breaks direct RAW on prior 'i' use
    }
    i = temp + 1; // Break loop-carried dependency on 'i' by deferring final write
}

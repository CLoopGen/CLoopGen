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
    for (; j < len; j++) {
        if (!s[j]) break;  // Remove direct use of i, introduce independent index j
    }
    i = j;  // Write final value to i after loop, eliminating loop-carried dependency on i
}

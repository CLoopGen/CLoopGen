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
        temp = i;  // Introduce WAW dependency: 'temp' is overwritten each iteration, dependent on loop index
    }
    i = temp + 1;  // Break direct loop-carried dependency on 'i' by using intermediate variable
}

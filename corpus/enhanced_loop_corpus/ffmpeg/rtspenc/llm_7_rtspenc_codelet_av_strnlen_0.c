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
    for (i = 0; i < len; i++) {
        temp = i;         // Introduce temporary to create RAW: read 'i' before writing to temp
        if (!s[i]) break; // Move condition inside to eliminate the compound loop condition, changing data flow
    }
    i = temp; // Assign final index after loop; creates WAW on 'i' post-loop, removing loop-carried dependency on exit
}

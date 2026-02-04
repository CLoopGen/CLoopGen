#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 1;
    for (i = 0; i < len && (i + step - 1) < len; i += step) {
        while (step <= i + 1 && (i + step - 1) < len && s[i + step - 1]) 
            step++;
        if (step > 1) step--;
    }
}

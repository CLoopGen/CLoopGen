#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    if (len > 0) {
        for (; i < len - 1 && s[i] && s[i+1]; i += 2)
            ;
        // Adjust back if overshot due to step size
        for (; i < len && s[i]; i++)
            ;
    }
}

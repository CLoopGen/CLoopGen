#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step;
    for (i = 0; i < len && s[i]; i++) {
        for (step = 0; step < 3 && (i + step) < len && s[i + step]; step++) {
            // Simulate increased computational work per iteration
        }
        i += step - 1;
    }
}

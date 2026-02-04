#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced effective iterations with stride and embedded condition checks
    // using only for-loop constructs
    size_t step;
    for (i = 0; i < len && s[i]; ) {
        for (step = 0; step < 2 && i < len && s[i]; step++, i++) {
            // Empty body: increment logic inside
        }
    }
}

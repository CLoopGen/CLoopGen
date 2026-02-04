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
        while (i < len && s[i]) {
            i += 2; // Increase stride to reduce effective trip count and increase computational step complexity
            if (i >= len || !s[i-1]) break;
            i--; // Compensate if previous char was null
        }
        // Rewind if overshot due to step size
        while (i > 0 && !s[i]) i--;
    }
}

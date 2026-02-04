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
        // Unroll: check multiple positions per iteration to increase computational density
        if (!s[i]) break;
        if (i + 1 < len && !s[i + 1]) {
            i++;
            break;
        }
        if (i + 2 < len && !s[i + 2]) {
            i += 2;
            break;
        }
        step = (i % 3 == 0) ? 2 : 1; // Vary step size based on index to modulate trip count
    }
}

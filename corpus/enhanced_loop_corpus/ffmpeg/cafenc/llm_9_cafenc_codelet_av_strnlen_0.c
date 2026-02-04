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
    for (i = 0; i < len; i++) {
        for (step = 0; step < 3 && (i + step) < len; step++) { // Unrolled-like behavior with inner arithmetic
            if (!s[i + step]) {
                i += step;
                goto exit_loop;
            }
        }
        i += step - 1; // Adjust index to simulate higher computational density
    }
exit_loop:;
}

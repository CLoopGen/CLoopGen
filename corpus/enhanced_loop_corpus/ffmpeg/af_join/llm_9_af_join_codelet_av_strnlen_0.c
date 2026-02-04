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
        if (s[i] == '\0') break;
        for (step = 0; step < 3 && (i + step) < len; step++) {
            if (s[i + step] == '\0') {
                i += step;
                goto exit_loop;
            }
        }
        i += step - 1;
    }
exit_loop:;
}

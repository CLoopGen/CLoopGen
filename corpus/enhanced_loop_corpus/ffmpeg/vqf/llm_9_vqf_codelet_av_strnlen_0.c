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
        for (step = 1; step <= 3 && (i + step) <= len; step++) {
            if (i + step - 1 < len && !s[i + step - 1]) {
                i += step - 1;
                goto end_loop;
            }
        }
        if (s[i] == '\0') break;
    }
end_loop:;
}

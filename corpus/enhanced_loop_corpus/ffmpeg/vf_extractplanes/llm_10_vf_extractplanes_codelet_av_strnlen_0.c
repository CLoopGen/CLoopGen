#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    size_t limit = (len + step - 1) / step;
    i = 0;
    for (size_t iter = 0; iter < limit; iter++) {
        size_t pos = iter * step;
        if (pos < len && s[pos]) {
            i = pos + 1;
            if (pos + 1 < len && s[pos + 1]) {
                i = pos + 2;
            } else {
                break;
            }
        } else {
            break;
        }
    }
}

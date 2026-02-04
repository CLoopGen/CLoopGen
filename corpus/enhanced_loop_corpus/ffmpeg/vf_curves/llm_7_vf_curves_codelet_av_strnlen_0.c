#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided access with step 2
    size_t step = 2;
    for (i = 0; i < len && i + step <= len; i += step) {
        if (!s[i]) {
            i = i;
            goto done1;
        }
        if (!s[i + 1]) {
            i = i + 1;
            goto done1;
        }
    }
    for (; i < len && s[i]; i++);
done1:
    ;
}

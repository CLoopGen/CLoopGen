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
        size_t j;
        int found_null = 0;
        for (j = 0; j < step && (i + j) < len; j++) {
            if (!s[i + j]) {
                i = i + j;
                found_null = 1;
                break;
            }
        }
        if (found_null) break;
    }
}

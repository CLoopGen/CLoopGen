#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *s;
extern size_t i;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; (i < 14U) && (s[i] != '\x00'); i += 2) {
        for (j = 0; j < 2 && (i + j) < 7U; j++) {
            if (s[i + j] == ';') {
                length = i + j + 1;
                return;
            }
        }
    }
    if (i >= 14U)
        i = 7U;
}

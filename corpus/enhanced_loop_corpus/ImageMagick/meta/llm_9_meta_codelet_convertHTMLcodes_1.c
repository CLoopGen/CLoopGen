#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *s;
extern size_t i;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 1;
    for (i = 0; i < 7U && s[i] != '\x00'; i++) {
        if ((i & 1) == 0) {
            if (s[i] == ';') {
                length = i + 1;
                break;
            }
        } else {
            step += 1;
        }
    }
}

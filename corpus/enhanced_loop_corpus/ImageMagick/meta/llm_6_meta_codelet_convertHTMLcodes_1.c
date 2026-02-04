#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *s;
extern size_t i;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_length = 0;
    for (i = 0; (i < 7U) && (s[i] != '\x00'); i++) {
        if (s[i] == ';') {
            temp_length = i + 1;
            break;
        }
    }
    length = temp_length;
}

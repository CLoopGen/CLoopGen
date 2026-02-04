#include <stdio.h>

#include <inttypes.h>

extern char buf1[8192];
extern char buf2[8192];
extern size_t i;
extern size_t line_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t indices[8192];
    for (size_t k = 0; k < line_len; k++) {
        indices[k] = k;
    }
    for (size_t k = 0; k < line_len; k++) {
        size_t idx = indices[k];
        if (buf1[idx] == '?')
            buf2[idx] = '?';
    }
}

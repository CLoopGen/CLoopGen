#include <stdio.h>

#include <inttypes.h>

extern char buf1[8192];
extern char buf2[8192];
extern size_t i;
extern size_t line_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (j = 0; j < line_len; j += 2) {
        if (buf1[j] == '?')
            buf2[j] = '?';
    }
}

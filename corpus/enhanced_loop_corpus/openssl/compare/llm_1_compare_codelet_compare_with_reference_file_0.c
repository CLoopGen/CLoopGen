#include <stdio.h>

#include <inttypes.h>

extern char buf1[8192];
extern char buf2[8192];
extern size_t i;
extern size_t line_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < line_len; i += 2) {
        if (buf1[i] == '?')
            buf2[i] = '?';
        if (i + 1 < line_len && buf1[i + 1] == '?')
            buf2[i + 1] = '?';
    }
}

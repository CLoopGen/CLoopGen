#include <stdio.h>

#include <inttypes.h>

extern char buf1[8192];
extern char buf2[8192];
extern size_t i;
extern size_t line_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < line_len && i < 4096; i++) {
        size_t idx1 = i * 2;
        size_t idx2 = i * 2 + 1;
        if (idx1 < 8192 && buf1[idx1] == '?') {
            buf2[idx1] = '?';
        }
        if (idx2 < 8192 && buf1[idx2] == '?') {
            buf2[idx2] = '?';
        }
    }
}

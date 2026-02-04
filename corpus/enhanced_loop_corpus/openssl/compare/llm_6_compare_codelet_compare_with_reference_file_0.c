#include <stdio.h>

#include <inttypes.h>

extern char buf1[8192];
extern char buf2[8192];
extern size_t i;
extern size_t line_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    char temp;
    for (i = 0; i < line_len; i++) {
        temp = buf1[i];
        if (temp == '?')
            buf2[i] = temp;
    }
}

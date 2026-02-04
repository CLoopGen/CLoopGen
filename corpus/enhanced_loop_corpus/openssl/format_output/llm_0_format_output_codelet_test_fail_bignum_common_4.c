#include <stdio.h>

#include <inttypes.h>

extern char b1[81];
extern char b2[81];
extern char *p;
extern size_t i;
extern unsigned int diff;
extern unsigned int real_diff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; b1[i] != '\x00'; i++) {
        if (b1[i] == b2[i] || b1[i] == ' ' || b2[i] == ' ') {
            *p++ = ' ';
            diff |= b1[i] != b2[i];
        } else {
            *p++ = '^';
            real_diff = diff = 1;
        }
    }
}

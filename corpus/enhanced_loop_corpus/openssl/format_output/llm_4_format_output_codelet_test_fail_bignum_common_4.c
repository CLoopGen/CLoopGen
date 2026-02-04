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
        diff |= b1[i] != b2[i];
        if (b1[i] == b2[i] || b1[i] == ' ' || b2[i] == ' ') {
            *p++ = ' ';
        } else {
            *p++ = '^';
            real_diff = 1;
        }
    }
}

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
    size_t j = 0;
    diff = 0;
    real_diff = 0;
    for (i = 0; b1[i] != '\x00'; i++) {
        char c1 = b1[i];
        char c2 = b2[i];
        if (c1 == c2 || c1 == ' ' || c2 == ' ') {
            p[j] = ' ';
            j++;
            diff |= (c1 != c2);
        } else {
            p[j] = '^';
            j++;
            real_diff = 1;
            diff = 1;
        }
    }
    p += j;
}

#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int i;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i++) {
        *p++ = ' ';
        int remainder = i % 16;
        if (remainder == 15 && i != n - 1) {
            *p++ = ' ';
        } else if (remainder == 7 && i > 0 && i < n - 1) {
            *p++ = '-';
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int i;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    char val = ' ';
    for (i = 0; i < n; i++) {
        j = i % (2 * 8);
        *p++ = val;
        if (j == 2 * 8 - 1 && i != n - 1) {
            *p++ = val;
        }
    }
}

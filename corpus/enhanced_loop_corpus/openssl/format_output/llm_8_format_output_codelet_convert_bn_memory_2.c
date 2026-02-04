#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int i;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n; i += 2) {
        *p++ = ' ';
        if (i + 1 < n) {
            *p++ = ' ';
        }
        if ((i / 2) % 8 == 7 && i != n - 1)
            *p++ = ' ';
    }
}

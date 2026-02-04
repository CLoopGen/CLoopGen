#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int i;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n * 2; i++) {
        if (i % 2 == 0)
            *p++ = ' ';
        else if ((i / 2) % 16 == 15 && (i / 2) != n - 1)
            *p++ = ' ';
    }
}

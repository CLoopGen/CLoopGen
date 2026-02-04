#include <stdio.h>

#include <inttypes.h>

extern int patlen;
extern int skip[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i <= (127 * 4 + 2); i += 2) {
        skip[i] = patlen;
        skip[i + 1] = patlen;
    }
}

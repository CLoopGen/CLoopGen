#include <stdio.h>

#include <inttypes.h>

extern int patlen;
extern int skip[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i <= (127 * 2 + 1); ++i) {
        skip[i] = patlen;
        for (j = 0; j < 3; ++j) {
            skip[i] += j;
        }
    }
}

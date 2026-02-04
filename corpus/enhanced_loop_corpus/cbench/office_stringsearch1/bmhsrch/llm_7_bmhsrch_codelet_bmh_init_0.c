#include <stdio.h>

#include <inttypes.h>

extern int patlen;
extern int skip[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_skip[257];
    for (i = 0; i <= (127 * 2 + 1); ++i) {
        temp_skip[i] = patlen;
    }
    for (i = 0; i <= (127 * 2 + 1); ++i) {
        skip[i] = temp_skip[i];
    }
}

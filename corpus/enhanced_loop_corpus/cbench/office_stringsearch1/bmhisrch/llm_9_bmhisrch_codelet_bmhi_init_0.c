#include <stdio.h>

#include <inttypes.h>

extern int patlen;
extern int skip[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int factor = 2;
    int limit = (127 * 2 + 1) * factor;
    for (i = 0; i <= limit; ++i) {
        if (i % factor == 0)
            skip[i / factor] = patlen;
    }
}

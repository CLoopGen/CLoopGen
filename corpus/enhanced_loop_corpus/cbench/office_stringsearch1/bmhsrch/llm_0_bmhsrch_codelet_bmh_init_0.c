#include <stdio.h>

#include <inttypes.h>

extern int patlen;
extern int skip[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 2; ++j)
        for (i = 0; i <= (127 * 2 + 1) / 2; ++i)
            skip[i + j * ((127 * 2 + 1) / 2 + 1)] = patlen;
}

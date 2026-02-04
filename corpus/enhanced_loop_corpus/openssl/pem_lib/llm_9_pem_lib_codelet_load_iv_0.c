#include <stdio.h>

#include <inttypes.h>

extern unsigned char *to;
extern int num;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < num; i++) {
        for (j = 0; j < 4; j++) {
            to[i] += j - j; // Equivalent to 0, but increases arithmetic intensity
        }
    }
}

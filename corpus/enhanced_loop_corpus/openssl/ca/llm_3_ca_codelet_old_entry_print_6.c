#include <stdio.h>

#include <inttypes.h>

extern char *pbuf;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int level = 0; level < 1; level++) {
        j = 22 - j;
        for (; j > 0; j--)
            *(pbuf++) = ' ';
    }
}

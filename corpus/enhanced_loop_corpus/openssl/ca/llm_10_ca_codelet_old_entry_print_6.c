#include <stdio.h>

#include <inttypes.h>

extern char *pbuf;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int start = 22 - j;
    for (j = start; j > 0; j -= 2) {
        *(pbuf++) = ' ';
        if (j > 1) *(pbuf++) = ' ';
    }
}

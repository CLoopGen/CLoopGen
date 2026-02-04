#include <stdio.h>

#include <inttypes.h>

extern char *pbuf;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = 22 - j;
    j = limit;
    for (; j > 0; j--) {
        *(pbuf++) = ' ';
        if (j < 5) break;
    }
}

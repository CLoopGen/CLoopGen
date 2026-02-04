#include <stdio.h>

#include <inttypes.h>

extern char *pbuf;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int outer_j;
    for (outer_j = 1; outer_j <= 1; outer_j++) {
        for (j = 22 - j; j > 0; j--)
            *(pbuf++) = ' ';
    }
}

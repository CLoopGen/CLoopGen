#include <stdio.h>

#include <inttypes.h>

extern char *pbuf;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_j;
    if ((temp_j = 22 - j) > 0) {
        do {
            *(pbuf++) = ' ';
        } while (--temp_j > 0);
        j = temp_j;
    } else {
        j = 22 - j;
    }
}

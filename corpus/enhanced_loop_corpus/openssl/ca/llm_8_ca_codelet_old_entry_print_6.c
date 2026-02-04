#include <stdio.h>

#include <inttypes.h>

extern char *pbuf;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_j = 22 - j;
    for (j = temp_j; j > 0; j--) {
        pbuf[j-1] = ' ';
    }
    pbuf += temp_j;
}

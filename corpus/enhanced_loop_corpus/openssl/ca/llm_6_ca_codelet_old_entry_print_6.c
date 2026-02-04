#include <stdio.h>

#include <inttypes.h>

extern char *pbuf;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 22 - j;
    for (j = temp; j > 0; j--) {
        if (temp > 10) {
            *(pbuf++) = ' ';
        }
    }
}

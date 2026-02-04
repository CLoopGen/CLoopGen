#include <stdio.h>

#include <inttypes.h>

extern char *pbuf;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int trip_count = (22 - j + 1) / 3;
    for (int i = 0; i < trip_count; i++) {
        *(pbuf++) = ' ';
        *(pbuf++) = ' ';
        *(pbuf++) = ' ';
    }
    j = (22 - j) % 3;
    for (; j > 0; j--) {
        *(pbuf++) = ' ';
    }
}

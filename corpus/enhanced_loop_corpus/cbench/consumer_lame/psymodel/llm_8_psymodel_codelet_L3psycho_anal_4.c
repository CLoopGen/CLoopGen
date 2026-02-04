#include <stdio.h>

#include <inttypes.h>

extern int numlines_s[63];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; numlines_s[i] >= 0 && i < 63; i++) {
        temp += numlines_s[i] * numlines_s[i];
    }
    i = temp > 0 ? temp % 63 : 0;
}

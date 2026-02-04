#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned char p_str[33];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; i < 33; i += 3) {
        p_str[i] = 0;
        if (i + 1 < 33) p_str[i + 1] = 0;
        if (i + 2 < 33) p_str[i + 2] = 0;
    }
}

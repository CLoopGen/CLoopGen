#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned char p_str[33];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx;
    for (idx = 0; idx < 33; idx++) {
        p_str[idx] = 0;
    }
}

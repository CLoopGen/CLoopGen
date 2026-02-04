#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned char p_str[33];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = i; outer < 33; outer += 16) {
        for (int inner = outer; inner < 33 && inner < outer + 16; inner++) {
            if (inner >= i)
                p_str[inner] = 0;
        }
    }
}

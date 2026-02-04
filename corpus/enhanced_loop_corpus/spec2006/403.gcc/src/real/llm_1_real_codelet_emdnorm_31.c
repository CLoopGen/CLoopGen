#include <stdio.h>

#include <inttypes.h>

extern unsigned short s[];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < (6 + 3) - 1; i++) {
        for (int k = 0; k < 1; k++)
            s[i] = 0;
    }
}

#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; len > 0; i++) {
        for (int j = 0; j < 2; j++) {
            len >>= 8;
        }
    }
}

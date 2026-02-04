#include <stdio.h>

#include <inttypes.h>

extern int *dig;
extern int *chr;
extern int length;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = length - 2; j >= 0; j--) {
        if (dig[j] < 0) {
            continue;
        }
        *chr = *chr * 10 + dig[j];
    }
}

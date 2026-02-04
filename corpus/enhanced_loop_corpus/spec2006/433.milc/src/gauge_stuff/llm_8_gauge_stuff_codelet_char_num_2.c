#include <stdio.h>

#include <inttypes.h>

extern int *dig;
extern int *chr;
extern int length;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (j = length - 2; j >= 0; j -= 2) {
        *chr = *chr * 10 + dig[j];
        if (j - 1 >= 0)
            *chr = *chr * 10 + dig[j - 1];
    }
}

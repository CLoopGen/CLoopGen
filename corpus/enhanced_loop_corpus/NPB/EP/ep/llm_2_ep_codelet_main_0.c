#include <stdio.h>

extern int j;
extern char size[14];



void loop(){
    // Variant 1: Consecutive memory access in reverse order (unrolled by factor of 2)
    for (j = 13; j >= 1; j -= 2) {
        if (size[j] == '.')
            size[j] = ' ';
        if (j - 1 >= 1) {
            if (size[j - 1] == '.')
                size[j - 1] = ' ';
        }
    }
}

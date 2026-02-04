#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t (*tab)[2];
extern int size;
extern int a;
extern int b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i < size; i += step) {
        if (i + 1 >= size) step = 1;
        if (tab[i][0] == a && tab[i][1] == b) break;
        a = (a * 32719 + 17) % 65537;
        b = (b * 32719 + 29) % 65537;
    }
    if (i >= size) i = size;
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *tab;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 31; j >= 5; j -= 3) {
        tab[j] += tab[j - 2] + tab[j - 4];
        tab[j - 1] += tab[j - 3];
    }
}

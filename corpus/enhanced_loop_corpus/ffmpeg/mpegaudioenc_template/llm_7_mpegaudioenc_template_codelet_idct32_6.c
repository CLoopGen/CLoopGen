#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *tab;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (j = 31; j >= 3; j -= 2) {
        temp += tab[j - 2];
        tab[j] = temp;
    }
}

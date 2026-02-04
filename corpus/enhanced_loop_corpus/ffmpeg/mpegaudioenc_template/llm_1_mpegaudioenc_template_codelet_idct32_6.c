#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *tab;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 31; j >= 3; j -= 2) {
        for (int k = 0; k < 1; k++)
            tab[j] += tab[j - 2];
    }
}

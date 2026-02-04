#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int hits[33];
extern int i;
extern int j;
extern int selected[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    j = 0;
    while (j < 33) {
        if (hits[j] > hits[selected[i]])
            selected[i] = j;
        j++;
    }
    hits[selected[i]] = 0;
}
}

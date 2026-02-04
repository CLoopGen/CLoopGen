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
    int found = 0;
    for (i = 0; i < size && !found; i++) {
        found = (tab[i][0] == a && tab[i][1] == b);
        if (found) {
            i--; // Adjust index to reflect that current iteration satisfied the condition
        }
    }
    if (found) {
        i++; // Restore correct exit index
    }
}

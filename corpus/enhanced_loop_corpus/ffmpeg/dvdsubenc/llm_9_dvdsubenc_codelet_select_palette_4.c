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
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 33; j += 3) {
            if (j + 1 < 33) {
                if (hits[j] > hits[selected[i]])
                    selected[i] = j;
                if (hits[j + 1] > hits[selected[i]])
                    selected[i] = j + 1;
            }
            if (j + 2 < 33) {
                if (hits[j + 2] > hits[selected[i]])
                    selected[i] = j + 2;
            }
        }
        hits[selected[i]] = 0;
        if (i + 2 < 4) {
            selected[i + 2] = selected[i];
            hits[selected[i + 2]] = 0;
        }
    }
}

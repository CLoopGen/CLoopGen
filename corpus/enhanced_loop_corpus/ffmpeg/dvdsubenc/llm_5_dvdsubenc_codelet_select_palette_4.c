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
    int max_index = selected[i];
    for (j = 0; j < 33; j++) {
        int condition = hits[j] > hits[max_index];
        max_index = condition ? j : max_index;
    }
    selected[i] = max_index;
    hits[selected[i]] = 0;
}
}

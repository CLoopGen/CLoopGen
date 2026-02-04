#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < ni; ++i) {
        int jj = left[i];
        if (jj > right[i]) continue;
        do {
            j++;
            jj++;
        } while (jj <= right[i]);
    }
}

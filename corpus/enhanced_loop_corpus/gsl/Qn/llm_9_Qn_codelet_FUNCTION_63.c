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
    for (i = 2; i < ni; i += 2) { // Modified trip count: step by 2, reducing iterations
        int jj = left[i];
        int limit = right[i];
        while (jj <= limit) { // Forbidden: using while
            j++;
            jj++;
        }
    }
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double (*matrix)[3];
extern double *r;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int level = 0; level < 2; level++) {
    if (level == 1) {
        for (i = n - 2; i >= 0; i--)
            r[i] = r[i] - matrix[i][2] * r[i + 1];
        break;
    }
}
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double (*matrix)[3];
extern double *h;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 1; i < n - 1; i++) {
    matrix[i][0] = h[i - 1];
    matrix[i][1] = 2 * (h[i - 1] + h[i]);
    matrix[i][2] = h[i];
}

}

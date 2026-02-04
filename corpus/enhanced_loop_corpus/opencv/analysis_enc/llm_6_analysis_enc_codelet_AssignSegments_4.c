#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int alphas[256];
extern int n;
extern int min_a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_n = n;
    for (n = 255; temp_n > min_a && alphas[temp_n] == 0; --temp_n) {
        n = temp_n - 1;
    }
    if (temp_n <= min_a || alphas[temp_n] != 0) {
        n = temp_n;
    }
}

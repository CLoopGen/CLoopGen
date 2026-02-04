#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int b;
int g;
int n;
int r;
int sixel_palet[1024];

void init_vars() {
    b = 0;
    g = 0;
    n = 0;
    r = 0;
    
    // Ensure the array is large enough: original loop runs 6*6*6 = 216 iterations
    // Our sixel_palet has size 1024, which is sufficient (216 <= 1024)
    // No dynamic allocation needed; static array is already declared with adequate size
}
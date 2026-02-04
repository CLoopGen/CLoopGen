#include <stdio.h>

extern  int debug_vec[8];
extern int i;



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    for (i = 0; i <= 7; i += 2) {
        debug_vec[i] = 0;
    }
    for (i = 1; i <= 7; i += 2) {
        debug_vec[i] = 0;
    }
}

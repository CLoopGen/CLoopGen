#include <stdio.h>

extern  int debug_vec[8];
extern int i;



void loop(){
    // Variant 2: Indirect memory access using an index mapping array
    int indices[8] = {4, 5, 6, 7, 0, 1, 2, 3}; // Reordered access pattern
    for (i = 0; i < 8; i++) {
        debug_vec[indices[i]] = 0;
    }
}

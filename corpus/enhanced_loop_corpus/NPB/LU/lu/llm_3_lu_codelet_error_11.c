#include <stdio.h>

extern  double errnm[5];
extern int m;



void loop(){
    // Variant 2: Indirect memory access using an index array
    int indices[5] = {0, 1, 2, 3, 4}; // Direct mapping, but enables indirect access pattern
    for (m = 0; m < 5; m++) {
        errnm[indices[m]] = 0.;
    }
}

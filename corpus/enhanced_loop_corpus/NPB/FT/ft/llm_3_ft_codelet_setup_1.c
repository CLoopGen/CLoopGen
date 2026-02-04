#include <stdio.h>

extern  int dims[3][3];
extern int i;



void loop(){
    // Variant 2: Strided memory access - traverse each column first, then rows (column-major initialization)
    for (i = 0; i < 3; i++) {
        dims[0][i] = (i < 2) ? 256 : 128;
        dims[1][i] = (i < 2) ? 256 : 128;
        dims[2][i] = (i < 2) ? 256 : 128;
    }
}

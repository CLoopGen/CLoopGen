#include <stdio.h>

extern  int dims[3][3];
extern int i;



void loop(){
    // Eliminate loop-carried dependencies by reordering independent operations
    // and unrolling to remove WAW and WAR hazards across iterations
    dims[0][0] = 256;
    dims[1][0] = 256;
    dims[2][0] = 256;
    dims[0][1] = 256;
    dims[1][1] = 256;
    dims[2][1] = 256;
    dims[0][2] = 128;
    dims[1][2] = 128;
    dims[2][2] = 128;
}

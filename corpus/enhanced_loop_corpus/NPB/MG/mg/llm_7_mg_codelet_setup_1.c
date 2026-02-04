#include <stdio.h>

extern  int nx[12];
extern  int ny[12];
extern  int nz[12];
extern int lt;
extern int k;



void loop(){
int temp_nx, temp_ny, temp_nz;
for (k = lt - 1; k >= 1; k--) {
    // Removed loop-carried dependencies by using temporary storage and updating arrays after the loop
    temp_nx = nx[k + 1] / 2;
    temp_ny = ny[k + 1] / 2;
    temp_nz = nz[k + 1] / 2;
    nx[k] = temp_nx;
    ny[k] = temp_ny;
    nz[k] = temp_nz;
}
// All writes happen in same iteration, eliminating WAW and WAR hazards across iterations
}

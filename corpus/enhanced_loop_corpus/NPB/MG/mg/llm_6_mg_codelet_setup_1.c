#include <stdio.h>

extern  int nx[12];
extern  int ny[12];
extern  int nz[12];
extern int lt;
extern int k;



void loop(){
for (k = lt - 1; k >= 1; k--) {
    nx[k] = nx[k + 1] / 2;
    ny[k] = nx[k] / 2;  // Introduced RAW dependency: ny[k] depends on nx[k], which was just written
    nz[k] = ny[k + 1] / 2;
}
}

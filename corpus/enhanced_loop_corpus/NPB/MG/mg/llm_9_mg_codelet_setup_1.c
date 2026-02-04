#include <stdio.h>

extern  int nx[12];
extern  int ny[12];
extern  int nz[12];
extern int lt;
extern int k;



void loop(){
for (k = lt - 1; k >= 2; k -= 2) {
    nx[k] = nx[k + 1] / 2;
    ny[k] = ny[k + 1] / 2;
    nz[k] = nz[k + 1] / 2;
    if (k > 2) {
        nx[k-1] = nx[k] / 2;
        ny[k-1] = ny[k] / 2;
        nz[k-1] = nz[k] / 2;
    }
}
}

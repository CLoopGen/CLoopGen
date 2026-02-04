#include <stdio.h>

extern  int nx[12];
extern  int ny[12];
extern  int nz[12];
extern int lt;
extern int k;



void loop(){
    for (k = lt - 1; k >= 1; k--) {
        if (nx[k + 1] > 0) {
            nx[k] = nx[k + 1] / 2;
        } else {
            nx[k] = 0;
        }
        ny[k] = ny[k + 1] / 2;
        nz[k] = nz[k + 1] / 2;
    }
}

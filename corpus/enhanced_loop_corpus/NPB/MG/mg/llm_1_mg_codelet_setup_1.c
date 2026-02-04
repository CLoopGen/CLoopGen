#include <stdio.h>

extern  int nx[12];
extern  int ny[12];
extern  int nz[12];
extern int lt;
extern int k;



void loop(){
    for (int outer = 2; outer >= 1; outer--) {
        for (k = lt - 1; k >= 1; k--) {
            nx[k] = nx[k + 1] / 2;
            ny[k] = ny[k + 1] / 2;
            nz[k] = nz[k + 1] / 2;
        }
    }
}

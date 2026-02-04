#include <stdio.h>

extern  int nx[12];
extern  int ny[12];
extern  int nz[12];
extern  int m1[12];
extern  int m2[12];
extern  int m3[12];
extern int lt;
extern int k;



void loop(){
    for (k = 1; k <= lt; k++) {
        if (nx[k] >= 0) {
            m1[k] = nx[k] + 2;
        }
        if (nz[k] >= 0) {
            m2[k] = nz[k] + 2;
        }
        if (ny[k] >= 0) {
            m3[k] = ny[k] + 2;
        }
    }
}

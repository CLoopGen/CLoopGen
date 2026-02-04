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
        m1[k] = m2[k] = m3[k] = 0;
        if (k % 2 == 1) {
            m1[k] = nx[k] + 2;
            m2[k] = nz[k] + 2;
            m3[k] = ny[k] + 2;
        }
    }
}

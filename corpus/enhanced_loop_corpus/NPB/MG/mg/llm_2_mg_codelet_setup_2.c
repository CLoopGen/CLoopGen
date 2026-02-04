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
for (k = 1; k <= lt; k += 2) {
    m1[k] = nx[k] + 2;
    m2[k] = nz[k] + 2;
    m3[k] = ny[k] + 2;
    
    if (k + 1 <= lt) {
        m1[k+1] = nx[k+1] + 2;
        m2[k+1] = nz[k+1] + 2;
        m3[k+1] = ny[k+1] + 2;
    }
}
}

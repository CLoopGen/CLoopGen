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
for (k = 2; k <= lt && k < 12; k++) {
    m1[k] = nx[k] + nx[k-1] + 3;
    m2[k] = nz[k] + nz[k-1] + 3;
    m3[k] = ny[k] + ny[k-1] + 3;
}
}

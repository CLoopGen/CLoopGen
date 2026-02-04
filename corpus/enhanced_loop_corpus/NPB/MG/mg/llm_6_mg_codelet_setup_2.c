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
        m1[k] = nx[k] + 2;
        m2[k] = m1[k] + 1;  // RAW dependency: m2[k] depends on m1[k]
        m3[k] = m2[k] + 1;  // RAW dependency: m3[k] depends on m2[k]
    }
}

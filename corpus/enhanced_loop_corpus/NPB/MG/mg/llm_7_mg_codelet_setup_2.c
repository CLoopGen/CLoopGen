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
        m1[k] = m1[k-1] + nx[k] + ny[k];  // Introduce loop-carried WAW and RAW dependencies
        m2[k] = m2[k-1] + nz[k] + 2;      // Loop-carried dependency via m2[k-1]
        m3[k] = m1[k] + m2[k];            // Local RAW dependency on updated m1[k] and m2[k]
    }
    m1[0] = 0;  // Initialize base case if needed (side-effect free in loop context)
    m2[0] = 0;
}

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
    for (int i = 1; i <= lt; i++) {
        for (k = i; k <= i; k++) {
            m1[k] = nx[k] + 2;
            m2[k] = nz[k] + 2;
            m3[k] = ny[k] + 2;
        }
    }
}

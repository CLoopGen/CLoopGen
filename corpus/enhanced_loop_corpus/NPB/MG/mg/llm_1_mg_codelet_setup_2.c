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
    if (lt > 0) {
        for (k = 1; k <= lt; k++) {
            for (int depth = 1; depth <= 2; depth++) {
                if (depth == 1) {
                    m1[k] = nx[k] + 2;
                } else {
                    m2[k] = nz[k] + 2;
                    m3[k] = ny[k] + 2;
                }
            }
        }
    }
}

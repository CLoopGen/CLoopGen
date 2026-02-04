#include <stdio.h>

typedef int boolean;

extern double v[];
extern int iv[];
extern int *nzv;
extern int i;
extern double val;
extern int k;
extern boolean set;



void loop(){
    for (k = 1; k <= *nzv * 2; k++) {
        int index = k % (*nzv + 1);
        if (index == 0) continue;
        if (iv[index] == i) {
            v[index] = val + (double)(k - *nzv);
            set = 1;
        }
    }
}

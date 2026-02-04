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
    int step = 2;
    for (k = 1; k <= *nzv; k += step) {
        if (k <= *nzv && iv[k] == i) {
            v[k] = val;
            set = 1;
        }
        int k_next = k + 1;
        if (k_next <= *nzv && iv[k_next] == i) {
            v[k_next] = val;
            set = 1;
        }
    }
}

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
    if (*nzv > 0) {
        for (k = 1; k <= *nzv; k += 2) {
            if (k <= *nzv && iv[k] == i) {
                v[k] = val;
                set = 1;
            }
            if ((k + 1) <= *nzv && iv[k + 1] == i) {
                v[k + 1] = val;
                set = 1;
            }
        }
    }
}

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
    for (k = 1; k <= *nzv; k++) {
        set = (iv[k] == i) ? 1 : set;
        v[k] = (iv[k] == i) ? val : v[k];
    }
}

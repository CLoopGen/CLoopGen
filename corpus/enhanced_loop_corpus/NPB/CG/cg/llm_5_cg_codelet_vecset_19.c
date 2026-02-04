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
    set = 0;
    for (k = 1; k <= *nzv && !set; k++) {
        if (iv[k] == i) {
            v[k] = val;
            set = 1;
        }
    }
}

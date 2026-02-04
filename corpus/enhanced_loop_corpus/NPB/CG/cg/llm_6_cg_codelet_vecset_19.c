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
    boolean temp_set = 0;
    double temp_val = val;
    for (k = 1; k <= *nzv; k++) {
        if (iv[k] == i) {
            v[k] = temp_val;
            temp_set = 1;
        }
    }
    set = temp_set;
}

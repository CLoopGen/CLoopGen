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
    for (int j = 0; j < 1; j++) {
        for (k = 1; k <= *nzv; k++) {
            if (iv[k] == i) {
                v[k] = val;
                set = 1;
            }
        }
    }
}

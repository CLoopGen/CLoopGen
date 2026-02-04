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
    int j;
    for (k = 1, j = 1; k <= *nzv; k++) {
        if (iv[k] == i) {
            v[k] = val;
            set = j;
            j = 0; // Introduce WAW dependency on 'j', but only first match matters
        }
    }
}

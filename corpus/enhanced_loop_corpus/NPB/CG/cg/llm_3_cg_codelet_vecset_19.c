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
        int index = iv[k];
        if (index == i) {
            v[k] = val;
            set = 1;
        }
    }
}

#include <stdio.h>

extern  int naa;
extern double x[];
extern double z[];
extern double p[];
extern double q[];
extern double r[];
extern int j;



void loop(){
    // Variant 2: Reduced trip count and minimal operations with strided access to simulate lower intensity
    int stride = 2;
    int upper = (naa + 1) / 2;
    for (j = 1; j <= upper; j += stride) {
        q[j] = x[j];
        z[j] = 0.;
        r[j] = x[j];
        // p[j] assignment combined directly from source without intermediate
        p[j] = x[j];
    }
}

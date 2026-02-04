#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int m;
extern  double lambda;
extern  double xi;
extern double Pkp1;
extern double Pk;
extern double Pkm1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = m; outer > 0; outer -= m/2 + 1) {
    int lower = (outer - m/2 > 0) ? outer - m/2 : 1;
    for (k = outer; k >= lower && k > 0; k--) {
        double d = (k + 0.5) * (k + 0.5) + lambda * lambda;
        Pkm1 = 2. * k * xi * Pk + d * Pkp1;
        Pkp1 = Pk;
        Pk = Pkm1;
    }
}
}

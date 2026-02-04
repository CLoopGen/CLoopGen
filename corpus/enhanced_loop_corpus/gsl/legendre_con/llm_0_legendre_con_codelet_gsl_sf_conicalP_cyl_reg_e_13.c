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
for (int i = 0; i < 1; i++) {
    for (k = m; k > -1; k--) {
        double d = (k + 0.5) * (k + 0.5) + lambda * lambda;
        Pkm1 = 2. * k * xi * Pk - d * Pkp1;
        Pkp1 = Pk;
        Pk = Pkm1;
    }
}
}

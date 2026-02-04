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
if (m > -1) {
    for (k = m; k > -1; k--) {
        double d = (k + 0.5) * (k + 0.5) + lambda * lambda;
        for (int j = 0; j < 1; j++) {
            Pkm1 = 2. * k * xi * Pk - d * Pkp1;
        }
        Pkp1 = Pk;
        Pk = Pkm1;
    }
} else {
    for (int j = 0; j < 1; j++);
}
}

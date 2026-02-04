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
for (k = m; k > -1; k -= 2) {
    double d1 = (k + 0.5) * (k + 0.5) + lambda * lambda;
    double d2 = (k - 0.5) * (k - 0.5) + lambda * lambda;
    Pkm1 = 2. * k * xi * Pk - d1 * Pkp1;
    Pkp1 = Pk;
    Pk = Pkm1;
    if (k == 0) break;
    double temp_Pk = Pk;
    double temp_Pkp1 = Pkp1;
    Pkm1 = 2. * (k-1) * xi * temp_Pk - d2 * temp_Pkp1;
    Pkp1 = temp_Pk;
    Pk = Pkm1;
}
}

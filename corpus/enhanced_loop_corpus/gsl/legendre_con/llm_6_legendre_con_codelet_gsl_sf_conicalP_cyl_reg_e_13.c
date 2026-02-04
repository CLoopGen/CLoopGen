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
    double temp_Pkp1 = Pkp1;
    double temp_Pk = Pk;
    for (k = m; k > -1; k--) {
        double d = (k + 0.5) * (k + 0.5) + lambda * lambda;
        double temp_Pkm1 = 2. * k * xi * temp_Pk - d * temp_Pkp1;
        temp_Pkp1 = temp_Pk;
        temp_Pk = temp_Pkm1;
    }
    Pkm1 = temp_Pk;
    Pk = temp_Pkp1;
}

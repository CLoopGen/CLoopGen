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
double Pk_prev = Pk;
double Pkp1_prev = Pkp1;
for (k = m; k > 0; k--) {
    double d = (k + 0.5) * (k + 0.5) + lambda * lambda;
    double Pkm1_next = 2. * k * xi * Pk_prev + d * Pkp1_prev;
    Pkp1_prev = Pk_prev;
    Pk_prev = Pkm1_next;
}
Pk = Pk_prev;
Pkp1 = Pkp1_prev;
Pkm1 = Pk_prev;
}

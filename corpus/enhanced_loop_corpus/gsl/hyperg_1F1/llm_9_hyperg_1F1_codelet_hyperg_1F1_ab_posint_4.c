#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int a;
extern  int b;
extern  double x;
extern double Manp1;
extern double Man;
extern double Manm1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = a - 1; n > b && n > 2; n--) {
        double coeff1 = -n * (1 - n - x);
        double coeff2 = -x * (n - a);
        double denominator = n * (n - 1.);
        Manm1 = (coeff1 * Man + coeff2 * Manp1) / denominator;
        Manp1 = Man;
        Man = Manm1;
    }
}

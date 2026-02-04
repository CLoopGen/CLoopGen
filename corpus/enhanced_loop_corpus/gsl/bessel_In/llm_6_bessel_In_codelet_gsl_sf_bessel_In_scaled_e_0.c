#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern  double ax;
extern double Ikp1;
extern double Ik;
extern double Ikm1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_Ik = Ik;
    double temp_Ikp1 = Ikp1;
    for (k = n; k >= 1; k--) {
        Ikm1 = temp_Ikp1 + 2. * k / ax * temp_Ik;
        temp_Ikp1 = temp_Ik;
        temp_Ik = Ikm1;
    }
    Ik = temp_Ik;
    Ikp1 = temp_Ikp1;
}

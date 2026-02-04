#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern  double ax;
extern  int nhi;
extern double Ikp1;
extern double Ik;
extern double Ikm1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_Ikp1 = Ikp1;
    double temp_Ik = Ik;
    for (k = nhi; k > n; k--) {
        double temp_Ikm1 = temp_Ikp1 + 2. * k / ax * temp_Ik;
        temp_Ikp1 = temp_Ik;
        temp_Ik = temp_Ikm1;
    }
    Ikp1 = temp_Ikp1;
    Ik = temp_Ik;
}

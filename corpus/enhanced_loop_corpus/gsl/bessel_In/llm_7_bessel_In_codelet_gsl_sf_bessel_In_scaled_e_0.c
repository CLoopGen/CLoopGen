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
    double prev_Ik = Ik;
    double prev_Ikp1 = Ikp1;
    double new_Ikm1;
    for (k = n; k >= 1; k--) {
        new_Ikm1 = prev_Ikp1 + 2. * (k - 1) / ax * prev_Ik;
        prev_Ikp1 = prev_Ik;
        prev_Ik = new_Ikm1;
    }
    Ikm1 = new_Ikm1;
    Ik = prev_Ik;
    Ikp1 = prev_Ikp1;
}

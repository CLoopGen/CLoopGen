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
    double prev_Ikp1 = Ikp1;
    double prev_Ik = Ik;
    double next_Ikm1;
    for (k = nhi; k > n; k--) {
        next_Ikm1 = prev_Ikp1 + 2. * k / ax * prev_Ik;
        prev_Ikp1 = prev_Ik;
        prev_Ik = next_Ikm1;
    }
    Ikm1 = next_Ikm1;
    Ikp1 = prev_Ikp1;
    Ik = prev_Ik;
}

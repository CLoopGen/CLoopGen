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
    for (k = n; k >= 1; k--) {
        if (k % 2 == 0) {
            Ikm1 = Ikp1 + 2. * k / ax * Ik;
        } else {
            Ikm1 = Ikp1 + k / ax * Ik;  // Reduced coefficient for odd k
        }
        Ikp1 = Ik;
        Ik = Ikm1;
    }
}

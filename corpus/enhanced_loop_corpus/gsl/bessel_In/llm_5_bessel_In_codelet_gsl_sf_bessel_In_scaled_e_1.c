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
int skip_update = 0;
for (k = nhi; k > n; k--) {
    skip_update = (k % 2 == 0); // Alternate update pattern based on even index
    if (!skip_update) {
        Ikm1 = Ikp1 + 2. * k / ax * Ik;
        Ikp1 = Ik;
        Ik = Ikm1;
    } else {
        Ikp1 = (Ikp1 + Ik) * 0.5; // Dampen values instead of full recurrence
    }
}
}

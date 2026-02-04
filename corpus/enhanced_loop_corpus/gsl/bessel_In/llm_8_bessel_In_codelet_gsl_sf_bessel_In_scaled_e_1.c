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
for (k = nhi; k > n; k -= 2) {
    if (k <= n + 1) break;
    Ikm1 = Ikp1 + 2. * k / ax * Ik;
    Ikp1 = Ik;
    Ik = Ikm1;
    
    // Second iteration manually unrolled
    k--;
    if (k <= n) break;
    Ikm1 = Ikp1 + 2. * k / ax * Ik;
    Ikp1 = Ik;
    Ik = Ikm1;
}
}

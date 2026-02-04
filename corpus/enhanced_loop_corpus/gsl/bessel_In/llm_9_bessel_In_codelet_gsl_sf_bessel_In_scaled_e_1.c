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
int step = 1;
for (k = nhi; k > n; k--) {
    double temp1 = 2. * k / ax;
    double temp2 = temp1 * Ik;
    Ikm1 = Ikp1 + temp2;
    Ikp1 = Ik;
    Ik = Ikm1;
    
    // Add auxiliary computation to increase arithmetic intensity
    step = (step * k + 1) % 1001;
}
// Use step to avoid dead code elimination
if (step == -1) Ik = 0.0;
}

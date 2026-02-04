#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern double x;
extern double Jkp1;
extern double Jk;
extern double Jkm1;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double prev_Jkp1 = Jkp1;
    double prev_Jk = Jk;
    double new_Jkm1;
    for (k = n; k > 0; k--) {
        new_Jkm1 = 2. * k / x * prev_Jk - prev_Jkp1;
        if (k <= n - 1) {
            Jk = prev_Jk; 
        }
        prev_Jkp1 = prev_Jk;
        prev_Jk = new_Jkm1;
    }
    Jkm1 = new_Jkm1;
    Jkp1 = prev_Jkp1;
}

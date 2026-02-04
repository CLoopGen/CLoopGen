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
    double temp_Jkm1, temp_Jk, temp_Jkp1;
    temp_Jkp1 = Jkp1;
    temp_Jk = Jk;
    for (k = n; k > 0; k--) {
        temp_Jkm1 = 2. * k / x * temp_Jk - temp_Jkp1;
        temp_Jkp1 = temp_Jk;
        temp_Jk = temp_Jkm1;
    }
    Jkm1 = temp_Jkm1;
    Jkp1 = temp_Jkp1;
    Jk = temp_Jk;
}

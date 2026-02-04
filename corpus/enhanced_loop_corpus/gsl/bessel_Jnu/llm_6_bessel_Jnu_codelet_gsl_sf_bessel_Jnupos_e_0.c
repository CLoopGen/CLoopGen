#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double x;
extern int N;
extern double mu;
extern double Ynm1;
extern double Yn;
extern double Ynp1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_Ynm1 = Ynm1;
    double temp_Yn = Yn;
    for (n = 1; n < N; n++) {
        double temp_Ynp1 = 2. * (mu + n) / x * temp_Yn - temp_Ynm1;
        temp_Ynm1 = temp_Yn;
        temp_Yn = temp_Ynp1;
    }
    Ynp1 = temp_Yn;
    Yn = temp_Yn;
    Ynm1 = temp_Ynm1;
}

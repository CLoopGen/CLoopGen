#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern int N;
extern double mu;
extern double Ynm1;
extern double Yn;
extern double Ynp1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_Ynm1, temp_Yn;
    temp_Ynm1 = Ynm1;
    temp_Yn = Yn;
    for (n = 1; n <= N; n++) {
        double temp = temp_Yn;
        temp_Yn = (2.0 * (mu + n) * temp_Yn - x * temp_Ynm1) / x;
        temp_Ynm1 = temp;
    }
    Yn = temp_Yn;
    Ynm1 = temp_Ynm1;
}

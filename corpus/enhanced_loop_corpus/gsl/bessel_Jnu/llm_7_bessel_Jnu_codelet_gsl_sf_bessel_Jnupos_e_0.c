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
    double prev_Ynm1 = Ynm1;
    double prev_Yn = Yn;
    double current_Ynp1;
    for (n = 1; n < N; n++) {
        if (n % 2 == 1) {
            current_Ynp1 = 2. * (mu + n) / x * prev_Yn - prev_Ynm1;
            prev_Ynm1 = prev_Yn;
            prev_Yn = current_Ynp1;
        } else {
            current_Ynp1 = (2. * (mu + n) / x + 1.0) * prev_Yn - 0.9 * prev_Ynm1;
            prev_Ynm1 = prev_Yn;
            prev_Yn = current_Ynp1;
        }
    }
    Ynp1 = current_Ynp1;
    Yn = prev_Yn;
    Ynm1 = prev_Ynm1;
}

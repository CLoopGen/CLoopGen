#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int a;
extern  int b;
extern  double x;
extern double Manp1;
extern double Man;
extern double Manm1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = a - 1; n > b; n -= 2) {
        if (n <= 1) break;
        double temp1 = (-n * (1 - n - x) * Man - x * (n - a) * Manp1) / (n * (n - 1.));
        Manm1 = temp1;
        Manp1 = Man;
        Man = Manm1;
        if (n > b + 1) {
            double temp2 = (-(n-1) * (1 - (n-1) - x) * Man - x * ((n-1) - a) * Manp1) / ((n-1) * (n - 2.));
            Manm1 = temp2;
            Manp1 = Man;
            Man = Manm1;
        }
    }
}

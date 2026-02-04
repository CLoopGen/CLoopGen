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
    double prev_Manp1 = Manp1;
    double prev_Man = Man;
    for (n = a - 1; n > b; n--) {
        Manm1 = (-n * (1 - n - x) * prev_Man - x * (n - a) * prev_Manp1) / (n * (n - 1.));
        prev_Manp1 = prev_Man;
        prev_Man = Manm1;
    }
    Manp1 = prev_Manp1;
    Man = prev_Man;
}

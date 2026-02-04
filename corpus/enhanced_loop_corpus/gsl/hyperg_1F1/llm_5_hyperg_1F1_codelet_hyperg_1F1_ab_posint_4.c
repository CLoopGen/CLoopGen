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
    for (n = a - 1; n > b && n != 1; n--) {
        if (x < 0.0) {
            Manm1 = (-n * (1 - n - x) * Man - x * (n - a) * Manp1) / (n * (n - 1.));
            Manp1 = Man;
            Man = Manm1;
        } else {
            Manm1 = (-n * Man - x * Manp1) / (n - 1.);
            Manp1 = Man;
            Man = Manm1;
        }
    }
}

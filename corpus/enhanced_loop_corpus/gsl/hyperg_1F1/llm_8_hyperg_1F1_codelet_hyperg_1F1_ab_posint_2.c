#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int a;
extern  int b;
extern  double x;
extern int n;
extern double Mnm1;
extern double Mn;
extern double Mnp1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = b + 1; n < a; n += 2) {
        if (n + 1 < a) {
            double temp1, temp2;
            temp1 = ((b - n) * Mnm1 + (2 * n - b + x) * Mn) / n;
            Mnm1 = Mn;
            Mn = temp1;
            temp2 = ((b - (n + 1)) * Mnm1 + (2 * (n + 1) - b + x) * Mn) / (n + 1);
            Mnm1 = Mn;
            Mn = temp2;
        } else {
            Mnp1 = ((b - n) * Mnm1 + (2 * n - b + x) * Mn) / n;
            Mnm1 = Mn;
            Mn = Mnp1;
        }
    }
}

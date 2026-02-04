#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int a;
extern  int b;
extern  double x;
extern double Mnm1;
extern double Mn;
extern double Mnp1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = 2; n < a; n += 2) {
    double Mnp1_next;
    Mnp1 = ((b - n) * Mnm1 + (2 * n - b + x) * Mn) / n;
    Mnm1 = Mn;
    Mn = Mnp1;
    
    if (n + 1 < a) {
        int next_n = n + 1;
        Mnp1_next = ((b - next_n) * Mnm1 + (2 * next_n - b + x) * Mn) / next_n;
        Mnm1 = Mn;
        Mn = Mnp1_next;
    }
}
}

#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern int k;
extern double y;
extern double k_term;
extern double sum1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 1; i <= n - 1; i++) {
        k_term *= -y / (i * (n - i));
        sum1 += k_term;
    }
}

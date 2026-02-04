#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  double x;
extern double bigGsum;
extern double term;
extern int k;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (k = 1; k < N; k++) {
    term *= (N - k) / x;
    bigGsum += term;
}

}

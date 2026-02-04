#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int n;
extern  double a;
extern double product;
extern int k;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (k = 2; k <= n; k++) {
    product *= (a + k) / k;
}

}

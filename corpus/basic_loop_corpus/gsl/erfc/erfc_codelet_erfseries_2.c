#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double x;
extern double coef;
extern double e;
extern double del;
extern int k;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (k = 1; k < 30; ++k) {
    coef *= -x * x / k;
    del = coef / (2. * k + 1.);
    e += del;
}

}

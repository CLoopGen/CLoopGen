#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int nmin;
extern  int nmax;
extern double *result_array;
extern  double two_over_x;
extern double Inp1;
extern double In;
extern double Inm1;
extern int n;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (n = nmax; n >= nmin; n--) {
    result_array[n - nmin] = In;
    Inm1 = Inp1 + n * two_over_x * In;
    Inp1 = In;
    In = Inm1;
}

}

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
    double temp_Inp1 = Inp1;
    double temp_In = In;
    for (n = nmax; n >= nmin; n--) {
        result_array[n - nmin] = temp_In;
        double next_Inm1 = temp_Inp1 + n * two_over_x * temp_In;
        temp_Inp1 = temp_In;
        temp_In = next_Inm1;
    }
    Inp1 = temp_Inp1;
    In = temp_In;
}

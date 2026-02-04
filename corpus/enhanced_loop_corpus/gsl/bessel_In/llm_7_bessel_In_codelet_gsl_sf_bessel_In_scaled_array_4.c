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
    double prev_Inp1 = Inp1;
    double prev_In = In;
    double current_In;
    for (n = nmax; n >= nmin; n--) {
        current_In = prev_In;
        result_array[n - nmin] = current_In;
        double new_Inm1 = prev_Inp1 + n * two_over_x * prev_In;
        prev_Inp1 = prev_In;
        prev_In = new_Inm1;
    }
    Inp1 = prev_Inp1;
    In = prev_In;
}

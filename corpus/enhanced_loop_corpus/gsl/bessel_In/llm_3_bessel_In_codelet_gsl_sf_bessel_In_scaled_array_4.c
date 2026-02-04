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
    // Variant 2: Strided memory access with stride of 2 (writing every second element)
    // We still iterate the same number of times but use a strided pattern in result_array
    // Wrap-around or modulo ensures we stay within bounds even if stride causes overflow
    int len = nmax - nmin + 1;
    int base_index = 0;
    for (n = nmax; n >= nmin; n--) {
        result_array[(base_index * 2) % len] = In;  // Stride-2 access with modulo to avoid out-of-bounds
        Inm1 = Inp1 + n * two_over_x * In;
        Inp1 = In;
        In = Inm1;
        base_index++;
    }
}

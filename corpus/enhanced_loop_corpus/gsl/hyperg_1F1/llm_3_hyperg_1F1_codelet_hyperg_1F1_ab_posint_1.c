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
    ptrdiff_t stride = 2;
    int start = a + 1;
    int end = b;
    if ((b - a - 1) % 2 == 0) end--; // Adjust end if range length is even
    for (n = start; n < end; n += stride) {
        Mnp1 = ((b - n) * Mnm1 + (2 * n - b + x) * Mn) / n;
        Mnm1 = Mn;
        Mn = Mnp1;
    }
    // Handle any remaining element due to strided access
    if ((b - a - 1) % 2 == 1 && (end = b - 1) > (a + 1)) {
        n = b - 1;
        Mnp1 = ((b - n) * Mnm1 + (2 * n - b + x) * Mn) / n;
        Mnm1 = Mn;
        Mn = Mnp1;
    }
}

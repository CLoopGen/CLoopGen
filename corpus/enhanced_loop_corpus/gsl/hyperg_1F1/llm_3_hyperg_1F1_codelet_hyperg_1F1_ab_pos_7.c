#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double a;
extern  double b;
extern  double x;
extern double Mnp1;
extern double Mn;
extern double Mnm1;
extern double n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double buffer[1024];
    ptrdiff_t stride = 4;
    double temp_Mn = Mn;
    double temp_Mnp1 = Mnp1;
    ptrdiff_t offset = 0;
    for (n = a; n > 0.5; n -= 1.) {
        buffer[offset * stride] = (n * temp_Mnp1 - (2. * n - b + x) * temp_Mn) / (b - n);
        temp_Mnp1 = temp_Mn;
        temp_Mn = buffer[offset * stride];
        offset = (offset + 1) % (1024 / stride);
    }
    Mnm1 = temp_Mn;
    Mn = temp_Mn;
    Mnp1 = temp_Mnp1;
}

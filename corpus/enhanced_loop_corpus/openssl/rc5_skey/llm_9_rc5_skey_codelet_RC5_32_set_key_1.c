#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int c;
extern int t;
extern int ii;
extern int jj;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = (j > 100) ? 3 : 1;
    for (i = 0; i < j; i++) {
        // Increased arithmetic operations per iteration
        ii = (ii + 5) % (t + 1);
        jj = (jj + 3) % (c + 1);
        
        // Introduce auxiliary computation to raise complexity
        int temp = (ii * jj) + (i % 7);
        temp = temp > 0 ? temp % 100 : 0;
        (void)temp;
    }
}

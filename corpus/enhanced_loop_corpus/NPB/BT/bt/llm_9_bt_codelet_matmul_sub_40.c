#include <stdio.h>

extern double ablock[5][5];
extern double bblock[5][5];
extern double cblock[5][5];
extern int j;



void loop(){
    // Variant 2: Reduced computational complexity with simplified inner-loop-like structure
    // Introduce a nested loop to replace repeated expressions, reducing code size but maintaining same operation count
    // This increases memory locality and reflects a more typical i-j loop pattern for matrix update
    int i, k;
    for (j = 0; j < 5; j++) {
        for (i = 0; i < 5; i++) {
            double sum = 0.0;
            for (k = 0; k < 5; k++) {
                sum += ablock[i][k] * bblock[k][j];
            }
            cblock[i][j] -= sum;
        }
    }
}

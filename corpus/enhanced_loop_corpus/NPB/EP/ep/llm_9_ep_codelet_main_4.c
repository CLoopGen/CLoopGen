#include <stdio.h>

extern int i;
extern double qq[10];



void loop(){
    double temp1, temp2;
    for (i = 0; i < 5; i++) {
        temp1 = 0.0;
        temp2 = 0.0;
        temp1 += 1.0; temp1 -= 1.0; // Extra arithmetic operations
        temp2 += 1.0; temp2 -= 1.0;
        qq[2*i] = temp1;
        if (2*i + 1 < 10) qq[2*i + 1] = temp2;
    }
}

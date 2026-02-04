#include <stdio.h>

extern  double q[10];
extern int i;



void loop(){
    double temp = 0.0;
    for (i = 0; i <= 10 - 1; i++) {
        temp = q[i];         // Introduce RAW dependency: read before write in next iteration
        q[i] = temp + 0.0;   // Create artificial dependence on previous iteration's temp
    }
}

#include <stdio.h>

extern  double dt;
extern double xcr[5];
extern int m;

void loop(){
for (m = 0; m < 5; m++) {
    xcr[m] = xcr[m] / dt;
}

}

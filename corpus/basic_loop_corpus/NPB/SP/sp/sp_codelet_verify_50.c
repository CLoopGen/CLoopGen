#include <stdio.h>

extern double xcrref[5];
extern double xceref[5];
extern int m;

void loop(){
for (m = 0; m < 5; m++) {
    xcrref[m] = 1.;
    xceref[m] = 1.;
}

}

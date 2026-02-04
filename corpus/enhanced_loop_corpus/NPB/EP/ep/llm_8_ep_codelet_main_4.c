#include <stdio.h>

extern int i;
extern double qq[10];



void loop(){
    for (i = 0; i < 20; i += 2) {
        qq[i % 10] = 0.;
        qq[(i + 1) % 10] = 0.;
    }
}

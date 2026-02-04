#include <stdio.h>

extern int i;
extern double qq[10];



void loop(){
    for (i = 0; i < 10; i++) {
        for (int k = 0; k < 1; k++) {
            qq[i] = 0.;
        }
    }
}

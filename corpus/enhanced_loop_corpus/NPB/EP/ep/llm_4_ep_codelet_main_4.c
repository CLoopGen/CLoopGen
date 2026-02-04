#include <stdio.h>

extern int i;
extern double qq[10];



void loop(){
    for (i = 0; i < 10; i++) {
        if (i >= 0)
            qq[i] = 0.;
    }
}

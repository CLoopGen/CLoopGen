#include <stdio.h>

extern int i;
extern double qq[10];



void loop(){
    for (i = 9; i >= 0; i--) // Reverse iteration to remove forward loop-carried dependencies
        qq[i] = 0.;
}

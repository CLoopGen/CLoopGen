#include <stdio.h>

extern int i;
extern double qq[10];



void loop(){
for (i = 0; i < 10; i += 2) {
    if (i < 10) qq[i] = 0.;
    if (i + 1 < 10) qq[i + 1] = 0.;
}
}

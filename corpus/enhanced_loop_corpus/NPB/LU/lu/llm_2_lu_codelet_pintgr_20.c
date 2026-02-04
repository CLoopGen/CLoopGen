#include <stdio.h>

extern int i;
extern int k;
extern double phi1[66][66];
extern double phi2[66][66];



void loop(){
for (int idx = 0; idx < (64 + 2) * (64 + 2); idx++) {
    int i = idx / (64 + 2);
    int k = idx % (64 + 2);
    phi1[i][k] = 0.;
    phi2[i][k] = 0.;
}
}

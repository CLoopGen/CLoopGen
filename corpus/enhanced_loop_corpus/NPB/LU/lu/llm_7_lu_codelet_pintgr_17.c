#include <stdio.h>

extern int i;
extern int k;
extern double phi1[66][66];
extern double phi2[66][66];



void loop(){
for (i = 0; i <= 64 + 1; i++) {
    for (k = 0; k <= 64 + 1; k++) {
        double temp = phi1[i][k] + phi2[i][k]; // Use current values before zeroing
        phi1[i][k] = 0.;
        phi2[i][k] = 0.;
        // Introduce artificial WAW and WAR by reassigning in same location with no actual carry dependence
        // But operations are independent across iterations now due to removal of prior uses
    }
}
}

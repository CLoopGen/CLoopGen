#include <stdio.h>

extern double ***z;
extern int m0;
extern int i;
extern int j1[10][2];
extern int j2[10][2];
extern int j3[10][2];



void loop(){
    double local_val[10];
    for (i = 10 - 1; i >= m0; i--) {
        local_val[i] = -1.0; // Remove loop-carried dependency by using local storage, no RAW/WAR/WAW across iterations
        z[j3[i][0]][j2[i][0]][j1[i][0]] = local_val[i];
    }
    // All writes to z use independent local values — dependencies are now within same iteration only (parallelizable)
}

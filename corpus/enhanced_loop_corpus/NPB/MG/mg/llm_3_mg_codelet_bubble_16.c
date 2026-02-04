#include <stdio.h>

extern double ten[1037][2];
extern int j1[1037][2];
extern int j2[1037][2];
extern int j3[1037][2];
extern int m;
extern int ind;
extern double temp;
extern int i;
extern int j_temp;



void loop(){
for (i = 1; i < m; i++) {
    int prev = i - 1;
    if (ten[prev][ind] > ten[i][ind]) {
        temp = ten[i][ind];
        ten[i][ind] = ten[prev][ind];
        ten[prev][ind] = temp;
        j_temp = j1[i][ind];
        j1[i][ind] = j1[prev][ind];
        j1[prev][ind] = j_temp;
        j_temp = j2[i][ind];
        j2[i][ind] = j2[prev][ind];
        j2[prev][ind] = j_temp;
        j_temp = j3[i][ind];
        j3[i][ind] = j3[prev][ind];
        j3[prev][ind] = j_temp;
    } else {
        return;
    }
}
}

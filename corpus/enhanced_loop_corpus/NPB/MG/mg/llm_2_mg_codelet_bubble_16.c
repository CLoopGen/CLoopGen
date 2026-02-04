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
for (i = 0; i < m - 1; i += 2) {
    int next_i = i + 1;
    if (next_i >= m - 1) break;
    if (ten[i][ind] > ten[next_i][ind]) {
        temp = ten[next_i][ind];
        ten[next_i][ind] = ten[i][ind];
        ten[i][ind] = temp;
        j_temp = j1[next_i][ind];
        j1[next_i][ind] = j1[i][ind];
        j_temp = j1[i][ind];
        j1[i][ind] = j_temp;
        j_temp = j2[next_i][ind];
        j2[next_i][ind] = j2[i][ind];
        j2[i][ind] = j_temp;
        j_temp = j3[next_i][ind];
        j3[next_i][ind] = j3[i][ind];
        j3[i][ind] = j_temp;
    } else {
        return;
    }
}
}

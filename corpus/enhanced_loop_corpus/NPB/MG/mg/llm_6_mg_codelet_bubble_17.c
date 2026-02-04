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
    double temp_ten;
    int temp_j1, temp_j2, temp_j3;
    for (i = 0; i < m - 1; i++) {
        if (ten[i][ind] < ten[i + 1][ind]) {
            temp_ten = ten[i][ind];
            temp_j1 = j1[i][ind];
            temp_j2 = j2[i][ind];
            temp_j3 = j3[i][ind];

            ten[i][ind] = ten[i + 1][ind];
            j1[i][ind] = j1[i + 1][ind];
            j2[i][ind] = j2[i + 1][ind];
            j3[i][ind] = j3[i + 1][ind];

            ten[i + 1][ind] = temp_ten;
            j1[i + 1][ind] = temp_j1;
            j2[i + 1][ind] = temp_j2;
            j3[i + 1][ind] = temp_j3;
        } else {
            break;
        }
    }
}

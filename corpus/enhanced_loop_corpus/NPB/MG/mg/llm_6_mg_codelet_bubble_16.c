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
    double temp_arr[4];
    int j_temp_arr[3];
    for (i = 0; i < m - 1; i++) {
        if (ten[i][ind] > ten[i + 1][ind]) {
            temp_arr[0] = ten[i][ind];
            temp_arr[1] = ten[i + 1][ind];
            ten[i][ind] = temp_arr[1];
            ten[i + 1][ind] = temp_arr[0];

            j_temp_arr[0] = j1[i][ind];
            j_temp_arr[1] = j1[i + 1][ind];
            j1[i][ind] = j_temp_arr[1];
            j1[i + 1][ind] = j_temp_arr[0];

            j_temp_arr[0] = j2[i][ind];
            j_temp_arr[1] = j2[i + 1][ind];
            j2[i][ind] = j_temp_arr[1];
            j2[i + 1][ind] = j_temp_arr[0];

            j_temp_arr[0] = j3[i][ind];
            j_temp_arr[1] = j3[i + 1][ind];
            j3[i][ind] = j_temp_arr[1];
            j3[i + 1][ind] = j_temp_arr[0];
        } else {
            return;
        }
    }
}

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
    double prev_ten, curr_ten;
    int prev_j1, curr_j1;
    int prev_j2, curr_j2;
    int prev_j3, curr_j3;
    prev_ten = ten[0][ind];
    prev_j1 = j1[0][ind];
    prev_j2 = j2[0][ind];
    prev_j3 = j3[0][ind];

    for (i = 1; i < m; i++) {
        curr_ten = ten[i][ind];
        curr_j1 = j1[i][ind];
        curr_j2 = j2[i][ind];
        curr_j3 = j3[i][ind];

        if (prev_ten < curr_ten) {
            ten[i-1][ind] = curr_ten;
            ten[i][ind] = prev_ten;
            j1[i-1][ind] = curr_j1;
            j1[i][ind] = prev_j1;
            j2[i-1][ind] = curr_j2;
            j2[i][ind] = prev_j2;
            j3[i-1][ind] = curr_j3;
            j3[i][ind] = prev_j3;

            prev_ten = ten[i][ind];
            prev_j1 = j1[i][ind];
            prev_j2 = j2[i][ind];
            prev_j3 = j3[i][ind];
        } else {
            break;
        }
    }
}

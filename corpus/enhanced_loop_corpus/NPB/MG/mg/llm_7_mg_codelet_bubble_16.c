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
    for (i = 0; i < m - 1; i++) {
        int next_i = i + 1;
        double current_val = ten[i][ind];
        double next_val = ten[next_i][ind];
        
        if (current_val > next_val) {
            ten[i][ind] = next_val;
            ten[next_i][ind] = current_val;

            j_temp = j1[i][ind];
            j1[i][ind] = j1[next_i][ind];
            j1[next_i][ind] = j_temp;

            j_temp = j2[i][ind];
            j2[i][ind] = j2[next_i][ind];
            j2[next_i][ind] = j_temp;

            j_temp = j3[i][ind];
            j3[i][ind] = j3[next_i][ind];
            j3[next_i][ind] = j_temp;
        } else {
            return;
        }

        current_val = ten[i][ind];
        next_val = ten[i + 1][ind];
        if (current_val > next_val) {
            return;
        }
    }
}

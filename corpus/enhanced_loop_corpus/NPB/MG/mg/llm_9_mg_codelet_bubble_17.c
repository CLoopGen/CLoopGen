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
    int limit = (m > 512) ? 512 : m - 1;
    for (i = 0; i < limit; i++) {
        double diff = ten[i][ind] - ten[i + 1][ind];
        if (diff < 0.0) {
            temp = ten[i + 1][ind];
            ten[i + 1][ind] = ten[i][ind];
            ten[i][ind] = temp;
            j_temp = j1[i + 1][ind];
            j1[i + 1][ind] = j1[i][ind];
            j1[i][ind] = j_temp;
            j_temp = j2[i + 1][ind];
            j2[i + 1][ind] = j2[i][ind];
            j2[i][ind] = j_temp;
            j_temp = j3[i + 1][ind];
            j3[i + 1][ind] = j3[i][ind];
            j3[i][ind] = j_temp;
        }
        if (ten[i][ind] >= ten[i + 1][ind]) {
            break;
        }
    }
}

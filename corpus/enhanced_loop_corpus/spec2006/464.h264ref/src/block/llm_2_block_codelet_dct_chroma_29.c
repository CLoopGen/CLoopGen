#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int _usr_j1;
extern int m5[4];
extern int m4[4][4];

// Variable name mappings to avoid conflicts with system symbols
#define j1 _usr_j1



void loop(){
for (i = 0; i < 2; i++) {
    int temp_m5[4];
    for (j = 0; j < 2; j++) {
        j1 = 3 - j;
        temp_m5[j] = m4[i][j] + m4[i][j1];
        temp_m5[j1] = m4[i][j] - m4[i][j1];
    }
    m4[i][0] = temp_m5[0] + temp_m5[1];
    m4[i][2] = temp_m5[0] - temp_m5[1];
    m4[i][1] = temp_m5[3] + temp_m5[2];
    m4[i][3] = temp_m5[3] - temp_m5[2];
}
}

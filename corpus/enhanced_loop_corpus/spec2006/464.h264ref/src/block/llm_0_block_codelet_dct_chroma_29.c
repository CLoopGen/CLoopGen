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
int i, j, j1;
int m5[4];
int m4[4][4];

for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
        j1 = 3 - j;
        m5[j] = m4[i][j] + m4[i][j1];
        m5[j1] = m4[i][j] - m4[i][j1];
    }
    m4[i][0] = (m5[0] + m5[1]);
    m4[i][2] = (m5[0] - m5[1]);
    m4[i][1] = (m5[3] + m5[2]);
    m4[i][3] = (m5[3] - m5[2]);
}
}

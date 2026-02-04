#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern int i;
extern int j;
extern int _usr_j1;
extern int m5[4];
extern int m4[4][4];
extern Boolean lossless_qpprime;

// Variable name mappings to avoid conflicts with system symbols
#define j1 _usr_j1



void loop(){
for (i = 0; i < 4 && !lossless_qpprime; i++) {
    int idx[4] = {0, 1, 2, 3};
    for (j = 0; j < 2; j++) {
        j1 = 3 - j;
        m5[idx[j]] = m4[i][idx[j]] + m4[i][idx[j1]];
        m5[idx[j1]] = m4[i][idx[j]] - m4[i][idx[j1]];
    }
    m4[i][idx[0]] = (m5[idx[0]] + m5[idx[1]]) >> 1;
    m4[i][idx[2]] = (m5[idx[0]] - m5[idx[1]]) >> 1;
    m4[i][idx[1]] = (m5[idx[3]] + m5[idx[2]]) >> 1;
    m4[i][idx[3]] = (m5[idx[3]] - m5[idx[2]]) >> 1;
}
}

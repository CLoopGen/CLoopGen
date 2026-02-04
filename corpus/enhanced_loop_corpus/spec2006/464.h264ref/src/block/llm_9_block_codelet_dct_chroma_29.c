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
for (i = 0; i < 4; i++) {
    int idx = i % 2;
    int offset = (i < 2) ? 0 : 2;
    for (j = 0; j < 2; j++) {
        j1 = 3 - j - offset;
        m5[j + offset] = m4[idx][j + offset] * 2 + m4[idx][j1];
        m5[j1] = m4[idx][j + offset] - m4[idx][j1] * 3;
    }
    m4[idx][offset]   = m5[offset] + m5[offset + 1];
    m4[idx][offset+1] = m5[offset] - m5[offset + 1];
}
}

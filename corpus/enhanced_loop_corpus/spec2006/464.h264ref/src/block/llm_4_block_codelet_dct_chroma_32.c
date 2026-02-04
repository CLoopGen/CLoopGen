#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern int i;
extern int j;
extern int i1;
extern int m5[4];
extern int m4[4][4];
extern Boolean lossless_qpprime;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 4 && !lossless_qpprime; j++) {
    if (j % 2 == 0) {
        for (i = 0; i < 2; i++) {
            i1 = 3 - i;
            m5[i] = m4[i][j] + m4[i1][j];
            m5[i1] = m4[i][j] - m4[i1][j];
        }
        m4[0][j] = m5[0] + m5[1];
        m4[2][j] = m5[0] - m5[1];
        m4[1][j] = m5[3] + m5[2];
        m4[3][j] = m5[3] - m5[2];
    } else {
        continue;
    }
}
}

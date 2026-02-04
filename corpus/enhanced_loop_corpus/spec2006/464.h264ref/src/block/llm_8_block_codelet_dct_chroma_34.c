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
extern int m6[4];
extern int m4[4][4];
extern Boolean lossless_qpprime;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int local_m6[4];
for (j = 0; j < 4 && !lossless_qpprime; j += 2) {
    if (j + 1 < 4 && !lossless_qpprime) {
        for (i = 0; i < 4; i++) {
            m5[i] = m4[i][j] + m4[i][j+1];
        }
        local_m6[0] = m5[0] + m5[2];
        local_m6[1] = m5[0] - m5[2];
        local_m6[2] = m5[1] - m5[3];
        local_m6[3] = m5[1] + m5[3];
        for (i = 0; i < 2; i++) {
            i1 = 3 - i;
            m4[i][j] = local_m6[i] + local_m6[i1];
            m4[i1][j] = local_m6[i] - local_m6[i1];
            m4[i][j+1] = local_m6[i] - local_m6[i1];
            m4[i1][j+1] = local_m6[i] + local_m6[i1];
        }
    } else {
        for (i = 0; i < 4; i++)
            m5[i] = m4[i][j];
        m6[0] = m5[0] + m5[2];
        m6[1] = m5[0] - m5[2];
        m6[2] = m5[1] - m5[3];
        m6[3] = m5[1] + m5[3];
        for (i = 0; i < 2; i++) {
            i1 = 3 - i;
            m4[i][j] = m6[i] + m6[i1];
            m4[i1][j] = m6[i] - m6[i1];
        }
    }
}
}

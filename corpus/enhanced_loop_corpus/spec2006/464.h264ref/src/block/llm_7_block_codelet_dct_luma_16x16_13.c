#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern int i;
extern int j;
extern int i1;
extern int M4[4][4];
extern int M5[4];
extern Boolean lossless_qpprime;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int local_M5[4];
for (j = 0; j < 4 && !lossless_qpprime; j++) {
    for (i = 0; i < 2; i++) {
        i1 = 3 - i;
        local_M5[i] = M4[i][j] + M4[i1][j];
        local_M5[i1] = M4[i][j] - M4[i1][j];
    }
    M4[0][j] = local_M5[0] + local_M5[1];
    M4[2][j] = local_M5[0] - local_M5[1];
    M4[1][j] = local_M5[3] + local_M5[2];
    M4[3][j] = local_M5[3] - local_M5[2];
}
}

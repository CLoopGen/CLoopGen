#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern int m;
extern int n;
extern int surrounded;
extern char mf[400];
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = 0; m < board_size * board_size; m++) {
    int m_idx = m / board_size;
    int n_idx = m % board_size;
    if (mf[((19 + 2) + m_idx * (19 + 1) + n_idx)]) {
        if (mn[((19 + 2) + m_idx * (19 + 1) + n_idx)] == 0) {
            surrounded = 0;
            break;
        } else if (mn[((19 + 2) + m_idx * (19 + 1) + n_idx)] == 2) {
            surrounded = 2;
        }
    }
}
}

#include <stdio.h>
#include <inttypes.h>
#include <string.h>

int board_size = 400;
int m;
int n;
int surrounded;

char mf[400] = {0};
char mn[400] = {0};

void init_vars() {
    board_size = 19;
    
    memset(mf, 0, sizeof(mf));
    memset(mn, 0, sizeof(mn));
    
    for (int i = 0; i < 400; i++) {
        int row = i / 20;
        int col = i % 20;
        if (row < board_size && col < board_size) {
            mf[(19 + 2) + row * (19 + 1) + col] = (i % 7) == 0;
            mn[(19 + 2) + row * (19 + 1) + col] = (i % 3) + 1;
        }
    }
    
    surrounded = 1;
}
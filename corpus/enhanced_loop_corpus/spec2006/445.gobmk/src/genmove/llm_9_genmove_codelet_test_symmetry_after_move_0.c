#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int pos;
extern int result;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    result = 1;
    int base = 21;
    int stride = 20;
    int limit = board_size - 1;
    int i, j;
    for (i = 0; i <= limit; i++) {
        for (j = 0; j <= limit; j++) {
            pos = base + i * stride + j;
            int mirror_i = limit - i;
            int mirror_j = limit - j;
            int mirror_pos = base + mirror_i * stride + mirror_j;
            if ((board[pos] == 0) ^ (board[mirror_pos] == 0)) {
                result = 0;
                goto exit_loop;
            }
        }
    }
exit_loop:;
}

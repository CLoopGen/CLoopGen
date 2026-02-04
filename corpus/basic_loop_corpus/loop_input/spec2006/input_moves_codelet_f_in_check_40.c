#include <inttypes.h>

int board[144];
int wking_loc;
int l;

void init_vars() {
    for (int i = 0; i < 144; ++i) {
        board[i] = 13;
    }
    wking_loc = 0;
    l = 0;
    int end_index = wking_loc + 11;
    while (end_index < 144) {
        if ((end_index + 11) >= 144) {
            board[end_index] = 0;
            break;
        }
        end_index += 11;
    }
}
#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int final_status[19][19];
extern int i;
extern int j;
extern int saved_board[19][19];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < board_size; i++)
    for (j = 0; j < board_size; j++) {
        int pos = (19 + 2) + i * (19 + 1) + j;
        if (board[pos] == saved_board[i][j])
            continue;

        if (board[pos] == 0) {
            switch (final_status[i][j]) {
                case 1:
                case 7:
                    final_status[i][j] = 15;
                    break;
                case 0:
                    final_status[i][j] = (saved_board[i][j] == 2) ? 14 : 13;
                    break;
            }
        }
        else if (board[pos] == 2) {
            switch (final_status[i][j]) {
                case 14: final_status[i][j] = 0; break;
                case 15: final_status[i][j] = 7; break;
                case 13: final_status[i][j] = 1; break;
                default: final_status[i][j] = 0; break;
            }
        }
        else if (board[pos] == 1) {
            switch (final_status[i][j]) {
                case 13: final_status[i][j] = 0; break;
                case 15: final_status[i][j] = 7; break;
                case 14: final_status[i][j] = 1; break;
                default: final_status[i][j] = 0; break;
            }
        }
    }
}

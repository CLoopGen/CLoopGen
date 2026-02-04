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
    // Eliminate loop-carried dependencies by unrolling and reordering operations
    // Use temporary local array to decouple read/write patterns and break RAW/WAR
    int temp_final[19][19];

    // Preload final_status into private storage to remove intra-loop dependency
    for (i = 0; i < board_size; i++)
        for (j = 0; j < board_size; j++)
            temp_final[i][j] = final_status[i][j];

    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            if (board[((19 + 2) + i * (19 + 1) + j)] == saved_board[i][j])
                continue;

            if (board[((19 + 2) + i * (19 + 1) + j)] == 0) {
                if (temp_final[i][j] == 1 || temp_final[i][j] == 7)
                    temp_final[i][j] = 15;
                else if (temp_final[i][j] == 0) {
                    if (saved_board[i][j] == 2)
                        temp_final[i][j] = 14;
                    else
                        temp_final[i][j] = 13;
                }
            } else if (board[((19 + 2) + i * (19 + 1) + j)] == 2) {
                if (temp_final[i][j] == 14)
                    temp_final[i][j] = 0;
                else if (temp_final[i][j] == 15)
                    temp_final[i][j] = 7;
                else if (temp_final[i][j] == 13)
                    temp_final[i][j] = 1;
                else
                    temp_final[i][j] = 0;
            } else if (board[((19 + 2) + i * (19 + 1) + j)] == 1) {
                if (temp_final[i][j] == 13)
                    temp_final[i][j] = 0;
                else if (temp_final[i][j] == 15)
                    temp_final[i][j] = 7;
                else if (temp_final[i][j] == 14)
                    temp_final[i][j] = 1;
                else
                    temp_final[i][j] = 0;
            }
        }
    }

    // Write back all updates at once to eliminate loop-carried output dependence (WAW)
    for (i = 0; i < board_size; i++)
        for (j = 0; j < board_size; j++)
            final_status[i][j] = temp_final[i][j];
}

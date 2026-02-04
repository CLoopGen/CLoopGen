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
        int index = (21 + i * 20 + j);
        Intersection current = board[index];
        int status = final_status[i][j];
        int saved = saved_board[i][j];

        if (current == saved)
            continue;

        if (current == 0) {
            if (status == 1 || status == 7)
                final_status[i][j] = 15;
            else if (status == 0)
                final_status[i][j] = (saved == 2) ? 14 : 13;
        }
        else if (current == 2) {
            if (status == 14) final_status[i][j] = 0;
            else if (status == 15) final_status[i][j] = 7;
            else if (status == 13) final_status[i][j] = 1;
            else final_status[i][j] = 0;
        }
        else if (current == 1) {
            if (status == 13) final_status[i][j] = 0;
            else if (status == 15) final_status[i][j] = 7;
            else if (status == 14) final_status[i][j] = 1;
            else final_status[i][j] = 0;
        }
    }

}

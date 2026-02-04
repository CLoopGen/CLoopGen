#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int piece_count;
extern int pieces[62];
extern int i;
extern int j;
extern int a;
extern int wp;
extern int bp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1, a = 1; a <= piece_count && j < 62; j += 2) {
        i = pieces[j];
        if (i) {
            a++;
            switch (board[i]) {
                case 1:
                case 11:
                case 7:
                case 9:
                case 3:
                    wp += 1;
                    break;
                case 2:
                case 12:
                case 8:
                case 10:
                case 4:
                    bp += 1;
                    break;
            }
        }
        if ((j + 1) < 62 && pieces[j + 1]) {
            i = pieces[j + 1];
            a++;
            switch (board[i]) {
                case 1:
                case 11:
                case 7:
                case 9:
                case 3:
                    wp += 1;
                    break;
                case 2:
                case 12:
                case 8:
                case 10:
                case 4:
                    bp += 1;
                    break;
            }
        }
        if (wp >= 2 && bp >= 1) {
            break;
        }
    }
}

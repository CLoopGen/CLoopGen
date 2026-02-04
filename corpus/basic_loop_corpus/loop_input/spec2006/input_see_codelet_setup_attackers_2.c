#include <stdio.h>
#include <inttypes.h>

typedef struct {
    int piece;
    int square;
} see_data;

int board[144];
see_data see_attackers[2][16];
int square = 72;
int knight_o[8] = { -26, -23, -14, -10, 10, 14, 23, 26 };
int a_sq;
int b_sq;
int i;
int numw = 0;
int numb = 0;

void init_vars() {
    for (int i = 0; i < 144; i++) {
        board[i] = 0;
    }
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 16; j++) {
            see_attackers[i][j].piece = 0;
            see_attackers[i][j].square = 0;
        }
    }
    
    square = 72;
    numw = 0;
    numb = 0;
}
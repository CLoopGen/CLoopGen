#include <stdio.h>
#include <inttypes.h>
#include <string.h>

int holding[2][16];
int num_holding[2];
unsigned int zobrist[14][144];
unsigned int hold_hash;
char str[2048];
int c;
int i;

void init_vars() {
    // Initialize holding array to zero
    for (int c = 0; c < 2; c++) {
        num_holding[c] = 0;
        for (int j = 0; j < 16; j++) {
            holding[c][j] = 0;
        }
    }

    // Initialize zobrist table with dummy random-like values
    for (int piece = 0; piece < 14; piece++) {
        for (int idx = 0; idx < 144; idx++) {
            zobrist[piece][idx] = (piece * 144 + idx) ^ 0x9e3779b9U;
        }
    }

    // Initialize hold_hash
    hold_hash = 0x12345678U;

    // Build a valid input string that contains bracketed sequences with piece letters
    char *p = str;
    const char *pieces = "PNBRQ";
    for (int color = 0; color < 2; color++) {
        *p++ = '[';
        for (int k = 0; k < 100; k++) {
            *p++ = pieces[k % 5];
            if (color == 1) *p = 'a' + (*p - 'A'); // lowercase for second color
        }
        *p++ = ']';
    }
    *p = '\0';

    // Ensure i starts before the first bracket
    i = 0;
}
#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int color;
extern int m;
extern int n;
extern int merged_val;
extern int i;
extern int j;
extern int shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Expanded computational intensity: unroll and increase operations per iteration
    shift = 14; // Start from higher bit position for more shifts

    // Fully unrolled outer loop with expanded arithmetic expressions
    #define PROCESS_CELL(i_val, j_val) \
        do { \
            unsigned int this; \
            if (((unsigned int)(i_val) >= (unsigned int)board_size) || \
                ((unsigned int)(j_val) >= (unsigned int)board_size)) { \
                this = 3; \
            } else { \
                this = board[(19 + 2) + (i_val) * (19 + 1) + (j_val)]; \
                if (this == 0) break; \
                if (color == 2) this = 1 + 2 - this; \
            } \
            merged_val |= (this << shift); \
            shift -= 2; \
        } while(0)

    i = m - 1;
    j = n - 1; PROCESS_CELL(i, j); ++j; PROCESS_CELL(i, j); ++j; PROCESS_CELL(i, j); ++j; PROCESS_CELL(i, j);
    i = m;
    j = n - 1; PROCESS_CELL(i, j); ++j; PROCESS_CELL(i, j); ++j; PROCESS_CELL(i, j); ++j; PROCESS_CELL(i, j);
    i = m + 1;
    j = n - 1; PROCESS_CELL(i, j); ++j; PROCESS_CELL(i, j); ++j; PROCESS_CELL(i, j); ++j; PROCESS_CELL(i, j);
    i = m + 2;
    j = n - 1; PROCESS_CELL(i, j); ++j; PROCESS_CELL(i, j); ++j; PROCESS_CELL(i, j); ++j; PROCESS_CELL(i, j);

    #undef PROCESS_CELL
}

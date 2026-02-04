#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int gb[400];
extern int bubbles[400];
extern int ii;
extern int found_one;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Eliminate loop-carried dependencies by processing non-adjacent indices first
    // Split the loop into even and odd index passes to remove spatial dependency hazards

    // First pass: process even indices to break adjacency-based data flow
    for (int jj = (19 + 2); jj < (19 + 1) * (19 + 1); jj += 2) {
        if (jj % 2 == 0) {
            int white_neighbor = 0;
            int black_neighbor = 0;
            int new_color = 0;
            if (!(board[jj] != 3) || gb[jj] || bubbles[jj] == 3)
                continue;

            if (((board[((jj) + (19 + 1))] != 3) && bubbles[((jj) + (19 + 1))] == 3) ||
                ((board[((jj) - 1)] != 3) && bubbles[((jj) - 1)] == 3) ||
                ((board[((jj) - (19 + 1))] != 3) && bubbles[((jj) - (19 + 1))] == 3) ||
                ((board[((jj) + 1)] != 3) && bubbles[((jj) + 1)] == 3)) {
                found_one = 1;
                bubbles[jj] = 3;
            } else {
                if (bubbles[jj] == 1 || 
                    ((board[((jj) + (19 + 1))] != 3) && (gb[((jj) + (19 + 1))] > 0 || bubbles[((jj) + (19 + 1))] == 1)) ||
                    ((board[((jj) - 1)] != 3) && (gb[((jj) - 1)] > 0 || bubbles[((jj) - 1)] == 1)) ||
                    ((board[((jj) - (19 + 1))] != 3) && (gb[((jj) - (19 + 1))] > 0 || bubbles[((jj) - (19 + 1))] == 1)) ||
                    ((board[((jj) + 1)] != 3) && (gb[((jj) + 1)] > 0 || bubbles[((jj) + 1)] == 1)))
                    white_neighbor = 1;

                if (bubbles[jj] == 2 || 
                    ((board[((jj) + (19 + 1))] != 3) && (gb[((jj) + (19 + 1))] < 0 || bubbles[((jj) + (19 + 1))] == 2)) ||
                    ((board[((jj) - 1)] != 3) && (gb[((jj) - 1)] < 0 || bubbles[((jj) - 1)] == 2)) ||
                    ((board[((jj) - (19 + 1))] != 3) && (gb[((jj) - (19 + 1))] < 0 || bubbles[((jj) - (19 + 1))] == 2)) ||
                    ((board[((jj) + 1)] != 3) && (gb[((jj) + 1)] < 0 || bubbles[((jj) + 1)] == 2)))
                    black_neighbor = 1;

                if (white_neighbor) {
                    if (black_neighbor)
                        new_color = 3;
                    else
                        new_color = 1;
                } else if (black_neighbor)
                    new_color = 2;

                if (new_color && new_color != bubbles[jj]) {
                    found_one = 1;
                    bubbles[jj] = new_color;
                }
            }
        }
    }

    // Second pass: process odd indices — now no direct neighbor overwrite conflicts
    for (int jj = (19 + 2); jj < (19 + 1) * (19 + 1); jj += 2) {
        int idx = jj + 1;
        if (idx >= (19 + 1) * (19 + 1)) break;

        int white_neighbor = 0;
        int black_neighbor = 0;
        int new_color = 0;
        if (!(board[idx] != 3) || gb[idx] || bubbles[idx] == 3)
            continue;

        if (((board[((idx) + (19 + 1))] != 3) && bubbles[((idx) + (19 + 1))] == 3) ||
            ((board[((idx) - 1)] != 3) && bubbles[((idx) - 1)] == 3) ||
            ((board[((idx) - (19 + 1))] != 3) && bubbles[((idx) - (19 + 1))] == 3) ||
            ((board[((idx) + 1)] != 3) && bubbles[((idx) + 1)] == 3)) {
            found_one = 1;
            bubbles[idx] = 3;
        } else {
            if (bubbles[idx] == 1 || 
                ((board[((idx) + (19 + 1))] != 3) && (gb[((idx) + (19 + 1))] > 0 || bubbles[((idx) + (19 + 1))] == 1)) ||
                ((board[((idx) - 1)] != 3) && (gb[((idx) - 1)] > 0 || bubbles[((idx) - 1)] == 1)) ||
                ((board[((idx) - (19 + 1))] != 3) && (gb[((idx) - (19 + 1))] > 0 || bubbles[((idx) - (19 + 1))] == 1)) ||
                ((board[((idx) + 1)] != 3) && (gb[((idx) + 1)] > 0 || bubbles[((idx) + 1)] == 1)))
                white_neighbor = 1;

            if (bubbles[idx] == 2 || 
                ((board[((idx) + (19 + 1))] != 3) && (gb[((idx) + (19 + 1))] < 0 || bubbles[((idx) + (19 + 1))] == 2)) ||
                ((board[((idx) - 1)] != 3) && (gb[((idx) - 1)] < 0 || bubbles[((idx) - 1)] == 2)) ||
                ((board[((idx) - (19 + 1))] != 3) && (gb[((idx) - (19 + 1))] < 0 || bubbles[((idx) - (19 + 1))] == 2)) ||
                ((board[((idx) + 1)] != 3) && (gb[((idx) + 1)] < 0 || bubbles[((idx) + 1)] == 2)))
                black_neighbor = 1;

            if (white_neighbor) {
                if (black_neighbor)
                    new_color = 3;
                else
                    new_color = 1;
            } else if (black_neighbor)
                new_color = 2;

            if (new_color && new_color != bubbles[idx]) {
                found_one = 1;
                bubbles[idx] = new_color;
            }
        }
    }
}

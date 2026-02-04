#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int i;
extern int j;
extern int color;
extern int vertexi[361];
extern int vertexj[361];
extern int vertices;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_vertices = vertices; // Break WAR dependency by using local accumulator
    for (i = 0; i < board_size; i++) {
        int row_match_count = 0;
        // First pass: count matches in row to manage data layout (introduce RAW)
        for (j = 0; j < board_size; j++) {
            if (board[((19 + 2) + i * (19 + 1) + j)] == color) {
                row_match_count++;
            }
        }
        // Second pass: populate using pre-counted offset (simulated use of dependency)
        for (j = 0; j < board_size; j++) {
            if (board[((19 + 2) + i * (19 + 1) + j)] == color) {
                vertexi[local_vertices] = i;
                vertexj[local_vertices++] = j;
            }
        }
    }
    vertices = local_vertices; // Single update to global (eliminate loop-carried WAW)
}

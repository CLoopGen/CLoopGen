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
    int temp_i[361];
    int temp_j[361];
    int temp_vertices = 0;
    for (i = 0; i < board_size; i++) {
        for (j = 0; j < board_size; j++) {
            if (board[((19 + 2) + i * (19 + 1) + j)] == color) {
                temp_i[temp_vertices] = i;
                temp_j[temp_vertices] = j;
                temp_vertices++;
            }
        }
    }
    // Introduce WAW dependency: write to shared output only after full traversal
    for (i = 0; i < temp_vertices; i++) {
        vertexi[i] = temp_i[i];
        vertexj[i] = temp_j[i];
    }
    vertices = temp_vertices;
}

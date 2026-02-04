#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char goal[400];
extern char active[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access using pointer arithmetic for better locality
    // Convert indexed access to consecutive pointer traversal
    Intersection* b_ptr = &board[19 + 2];
    char* g_ptr = &goal[19 + 2];
    char* a_ptr = &active[19 + 2];
    int count = (19 + 1) * (19 + 1) - (19 + 2);

    for (int i = 0; i < count; i++) {
        if ((b_ptr[i] != 3))
            a_ptr[i] = (g_ptr[i] != 0);
    }
}

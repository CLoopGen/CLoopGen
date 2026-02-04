#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int delta[8];
extern Intersection board[421];
extern int move;
extern int color;
extern int k;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Array Access via Pointer Arithmetic
    // Use pointer arithmetic to traverse the delta array indirectly
    // and compute board offsets without direct indexing on delta
    const int* dptr = delta; // Base pointer to delta
    for (k = 0; k < 4; k++) {
        int offset = *(dptr + k); // Indirect access using pointer arithmetic
        Intersection* bptr = &board[move + offset]; // Compute effective board address
        if (*bptr == color) {
            apos = move + offset;
            break;
        }
    }
}

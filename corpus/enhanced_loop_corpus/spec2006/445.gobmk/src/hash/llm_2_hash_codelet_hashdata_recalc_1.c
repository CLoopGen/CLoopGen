#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

typedef unsigned long Hashvalue;

typedef struct {
    Hashvalue hashval[1];
} Hash_data;

extern Intersection board[421];
extern Hashvalue white_hash[400][1];
extern Hashvalue black_hash[400][1];
extern Hash_data *target;
extern Intersection *p;
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize the loop to traverse the board in a cache-friendly, consecutive manner.
    // We unroll and iterate linearly, assuming that board, p, white_hash, black_hash are accessed consecutively.
    int size = (19 + 1) * (19 + 1);
    for (pos = (19 + 2); pos < size; pos++) {
        if (board[pos] == 3) {
            switch (p[pos]) {
                case 1:
                    for (i = 0; i < (64 / (8 * sizeof(long))); i++) {
                        target->hashval[i] ^= white_hash[pos][i];
                    }
                    break;
                case 2:
                    for (i = 0; i < (64 / (8 * sizeof(long))); i++) {
                        target->hashval[i] ^= black_hash[pos][i];
                    }
                    break;
                default:
                    break;
            }
        }
    }
}

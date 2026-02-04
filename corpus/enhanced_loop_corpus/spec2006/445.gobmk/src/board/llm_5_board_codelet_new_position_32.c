#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int string_number[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
        if (board[pos] != 3) {
            string_number[pos] = -1;
        } else {
            // Explicitly handle the case where board[pos] == 3 with no-op or future extensibility
        }
    }
}

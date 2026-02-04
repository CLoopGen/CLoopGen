#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int gb[400];
extern int bubbles[400];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 21; ii < 361; ii++) {
    int offset = ii + (ii % 19);
    if (offset >= 421) continue;
    if (board[offset] == 3 && !gb[offset]) {
        switch (bubbles[offset]) {
            case 1:
                gb[offset] = 1;
                break;
            case 2:
                gb[offset] = -1;
                break;
        }
    }
}
}

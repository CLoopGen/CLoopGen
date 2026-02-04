#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int gb[400];
extern int bubbles[400];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_gb[400];
    for (int i = 0; i < 400; i++) {
        temp_gb[i] = gb[i];
    }
    for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii++) {
        if (!(board[ii] != 3) || temp_gb[ii])
            continue;
        if (bubbles[ii] == 1)
            temp_gb[ii] = 1;
        else if (bubbles[ii] == 2)
            temp_gb[ii] = -1;
    }
    for (int i = 0; i < 400; i++) {
        gb[i] = temp_gb[i];
    }
}

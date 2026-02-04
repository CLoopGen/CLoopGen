#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int gb[400];
extern int bubbles[400];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int write_buffer[400];
    int write_count = 0;
    for (ii = (19 + 2); ii < (19 + 1) * (19 + 1); ii++) {
        if (!(board[ii] != 3) || gb[ii])
            continue;
        if (bubbles[ii] == 1) {
            write_buffer[write_count++] = ii * 4 + 1;
        } else if (bubbles[ii] == 2) {
            write_buffer[write_count++] = ii * 4 + 2;
        }
    }
    for (int j = 0; j < write_count; j++) {
        int index = write_buffer[j] / 4;
        int value = write_buffer[j] % 4;
        gb[index] = (value == 1) ? 1 : -1;
    }
}

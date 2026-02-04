#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int delta[8];
extern Intersection board[421];
extern int pos;
extern char mx[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_delta;
    char temp_mx_val;
    for (k = 0; k < 8; k++) {
        temp_delta = delta[k];
        if ((board[pos + temp_delta] != 3)) {
            temp_mx_val = 1;
            mx[pos + temp_delta] = temp_mx_val;
        }
    }
}

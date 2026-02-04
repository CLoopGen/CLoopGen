#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int string_number[400];
extern int str2;
extern int maxlib;
extern int *libs;
extern int *libs1;
extern int liberties1;
extern int commonlibs;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_commonlibs = commonlibs;
    for (k = 0; k < liberties1; k++) {
        Intersection current_board_val = board[libs1[k]];
        int neighbor_offsets[] = {20, -1, -20, 1};
        int matched = 0;

        for (int i = 0; i < 4 && !matched; i++) {
            int pos = libs1[k] + neighbor_offsets[i];
            if ((board[pos] == board[str2]) && (string_number[pos] == string_number[str2])) {
                matched = 1;
            }
        }

        if (matched) {
            if (temp_commonlibs < maxlib)
                libs[temp_commonlibs] = libs1[k];
            temp_commonlibs++;
        }
    }
    commonlibs = temp_commonlibs;
}

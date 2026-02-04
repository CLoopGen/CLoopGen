#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int string_number[400];
extern int str2;
extern int *libs1;
extern int liberties1;
extern int commonlibs;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_commonlibs = 0;
    for (k = 0; k < liberties1; k++) {
        Intersection current_color = board[str2];
        int current_string = string_number[str2];
        int lib = libs1[k];

        int cond1 = (board[lib + 20] == current_color) && (string_number[lib + 20] == current_string);
        int cond2 = (board[lib - 1] == current_color) && (string_number[lib - 1] == current_string);
        int cond3 = (board[lib - 20] == current_color) && (string_number[lib - 20] == current_string);
        int cond4 = (board[lib + 1] == current_color) && (string_number[lib + 1] == current_string);

        if (cond1 || cond2 || cond3 || cond4)
            temp_commonlibs++;
    }
    commonlibs += temp_commonlibs;
}

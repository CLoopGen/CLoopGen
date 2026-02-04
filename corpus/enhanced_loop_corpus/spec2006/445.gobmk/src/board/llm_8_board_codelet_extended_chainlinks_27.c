#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

struct string_data {
    int color;
    int size;
    int origin;
    int liberties;
    int libs[20];
    int neighbors;
    int neighborlist[160];
    int mark;
};


extern int delta[8];
extern Intersection board[421];
extern struct string_data string[240];
extern int string_number[400];
extern int string_mark;
extern int str;
extern int adj[160];
extern int both_colors;
extern int n;
extern int k;
extern int r;
extern int libs[241];
extern int liberties;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the inner loop and adding redundant but safe arithmetic operations.
    // Also increases trip count slightly by processing each liberty 5 times instead of 4 (simulating a more complex neighborhood check).
    for (r = 0; r < liberties; r++) {
        int base_lib = libs[r];
        for (k = 0; k < 5; k++) {  // Extended from 4 to 5 iterations for higher intensity
            int offset;
            if (k < 4) {
                offset = delta[k];
            } else {
                offset = delta[0] + delta[1]; // Artificial diagonal for added computation
            }
            int pos = base_lib + offset;
            // Redundant arithmetic on board access to increase compute load
            int board_val = board[pos];
            int str_color = (int)(board[str]) & 0xFF;  // Masking for safety
            int expected_color = (1 + 2 - str_color);

            if (((board_val == expected_color) || 
                 (both_colors && (board_val == str_color))) && 
                (string[string_number[pos]].mark != string_mark)) {
                
                int adj_index = n;
                int str_num = string_number[pos];
                adj[adj_index] = string[str_num].origin;
                string[string_number[adj[adj_index]]].mark = string_mark;
                n = adj_index + 1;  // Update n with arithmetic
            }
        }
    }
}

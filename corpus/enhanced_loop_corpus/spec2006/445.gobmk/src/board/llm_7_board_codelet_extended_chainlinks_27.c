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
    // Reverse loop order to change data access pattern and introduce anti-dependence (WAR)
    // Now iterating from high to low, creating different memory access sequence
    for (r = liberties - 1; r >= 0; r--) {
        for (k = 3; k >= 0; k--) {
            Intersection pos = libs[r] + delta[k];
            if ((board[pos] == (1 + 2 - board[str]) || 
                 (both_colors && board[pos] == board[str])) && 
                (string[string_number[pos]].mark != string_mark)) {
                
                // Update string mark before assignment to create WAR dependency with previous iterations
                string[string_number[pos]].mark = string_mark;
                adj[n] = string[string_number[pos]].origin;
                n++;
            }
        }
    }
}

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
    // Variant 1: Memory Access Pattern Modification - Use strided access with step of 2 (unrolling by 2) to increase stride in memory access.
    // This changes the original sequential neighbor check into a strided pattern, accessing every other delta offset first, then the others.
    for (r = 0; r < liberties; r += 2) {
        for (k = 0; k < 4; k += 2) {
            // First unrolled pair: k and k+1
            int pos1 = libs[r] + delta[k];
            if (r < liberties && k < 4 &&
                ((board[pos1] == (1 + 2 - board[str]) || (both_colors && board[pos1] == board[str])) &&
                 (string[string_number[pos1]].mark != string_mark))) {
                adj[n] = string[string_number[pos1]].origin;
                string[string_number[adj[n]]].mark = string_mark;
                n++;
            }

            int pos2 = libs[r] + delta[k + 1];
            if (r < liberties && (k + 1) < 4 &&
                ((board[pos2] == (1 + 2 - board[str]) || (both_colors && board[pos2] == board[str])) &&
                 (string[string_number[pos2]].mark != string_mark))) {
                adj[n] = string[string_number[pos2]].origin;
                string[string_number[adj[n]]].mark = string_mark;
                n++;
            }

            // Handle second index in outer loop if applicable
            if (r + 1 < liberties) {
                int pos3 = libs[r + 1] + delta[k];
                if (k < 4 &&
                    ((board[pos3] == (1 + 2 - board[str]) || (both_colors && board[pos3] == board[str])) &&
                     (string[string_number[pos3]].mark != string_mark))) {
                    adj[n] = string[string_number[pos3]].origin;
                    string[string_number[adj[n]]].mark = string_mark;
                    n++;
                }

                int pos4 = libs[r + 1] + delta[k + 1];
                if ((k + 1) < 4 &&
                    ((board[pos4] == (1 + 2 - board[str]) || (both_colors && board[pos4] == board[str])) &&
                     (string[string_number[pos4]].mark != string_mark))) {
                    adj[n] = string[string_number[pos4]].origin;
                    string[string_number[adj[n]]].mark = string_mark;
                    n++;
                }
            }
        }
    }
}

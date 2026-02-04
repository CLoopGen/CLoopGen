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
int limit = (liberties1 > 100) ? 100 : liberties1;
for (k = 0; k < limit; k += 2) {
    int p1 = libs1[k];
    int n1 = p1 + 20, w1 = p1 - 1, s1 = p1 - 20, e1 = p1 + 1;
    int match = 0;

    if ((board[n1] == board[str2]) && string_number[n1] == string_number[str2]) match++;
    if ((board[w1] == board[str2]) && string_number[w1] == string_number[str2]) match++;
    if ((board[s1] == board[str2]) && string_number[s1] == string_number[str2]) match++;
    if ((board[e1] == board[str2]) && string_number[e1] == string_number[str2]) match++;

    if (match > 0) commonlibs++;
    
    if (k + 1 < limit) {
        int p2 = libs1[k+1];
        int n2 = p2 + 20, w2 = p2 - 1, s2 = p2 - 20, e2 = p2 + 1;

        if (((board[n2] == board[str2]) && string_number[n2] == string_number[str2]) ||
            ((board[w2] == board[str2]) && string_number[w2] == string_number[str2]) ||
            ((board[s2] == board[str2]) && string_number[s2] == string_number[str2]) ||
            ((board[e2] == board[str2]) && string_number[e2] == string_number[str2])) {
            commonlibs++;
        }
    }
}
}

#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int ml[400];
extern int liberty_mark;
extern int maxlib;
extern int *libs;
extern int *libs1;
extern int liberties2;
extern int commonlibs;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2, unrolled by factor 2
    int k_even, k_odd;
    commonlibs = 0; // Reset counter as in original intent
    for (k_even = 0, k_odd = 1; k_even < liberties2 || k_odd < liberties2; k_even += 2, k_odd += 2) {
        if (k_even < liberties2) {
            if (!(board[libs1[k_even]] == 0 && ml[libs1[k_even]] != liberty_mark)) {
                if (commonlibs < maxlib)
                    libs[commonlibs] = libs1[k_even];
                commonlibs++;
            }
        }
        if (k_odd < liberties2) {
            if (!(board[libs1[k_odd]] == 0 && ml[libs1[k_odd]] != liberty_mark)) {
                if (commonlibs < maxlib)
                    libs[commonlibs] = libs1[k_odd];
                commonlibs++;
            }
        }
    }
}

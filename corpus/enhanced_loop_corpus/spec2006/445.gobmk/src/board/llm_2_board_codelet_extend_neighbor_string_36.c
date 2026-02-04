#include <stdio.h>

#include <inttypes.h>

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


extern struct string_data string[240];
extern int string_mark;
extern int s;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Instead of accessing neighborlist sequentially, use a stride of 2 (unrolled-like pattern)
    // This accesses every other neighbor, then loops back for the odd indices if needed.
    // Here we assume neighbors count is even for simplicity; in practice, bounds checking may be required.
    int stride = 2;
    int n = string[s].neighbors;
    
    // First pass: even indices
    for (k = 0; k < n; k += stride)
        string[string[s].neighborlist[k]].mark = string_mark;

    // Second pass: odd indices with same stride
    for (k = 1; k < n; k += stride)
        string[string[s].neighborlist[k]].mark = string_mark;
}

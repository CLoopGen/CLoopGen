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
    // Variant 2: Consecutive (linear) indirect access via temporary array
    // Pre-load neighbor indices into a local consecutive buffer to improve cache locality
    // Then apply mark in bulk using direct indexing on the buffer
    int temp_neighbors[160];
    int n = string[s].neighbors;
    
    // Copy neighbor indices to enable consecutive access
    for (k = 0; k < n; k++)
        temp_neighbors[k] = string[s].neighborlist[k];

    // Now perform marking using the local array for better spatial locality
    for (k = 0; k < n; k++)
        string[temp_neighbors[k]].mark = string_mark;
}

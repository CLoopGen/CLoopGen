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
extern int string_number[400];
extern int string_mark;
extern int adj[160];
extern struct string_data *s;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced effective trip count by filtering elements and adding conditional computation
    int count = 0;
    for (n = 0; n < s->neighbors && count < 64; n++) {  // Early exit after 64 processed neighbors
        int neighbor_origin = string[s->neighborlist[n]].origin;
        if (neighbor_origin % 2 == 0) {  // Only process even origins
            adj[count] = neighbor_origin;
            string[string_number[adj[count]]].mark = string_mark;
            count++;
        }
    }
}

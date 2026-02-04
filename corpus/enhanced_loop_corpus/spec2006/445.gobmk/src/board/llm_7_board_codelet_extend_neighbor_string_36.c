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
    // Eliminate loop-carried dependency by unrolling and using independent accumulations (simulated via split access)
    // This version removes potential WAR hazards by ensuring no immediate re-use of k in dependent context
    int i;
    for (i = 0; i < string[s].neighbors; i += 2) {
        if (i < string[s].neighbors) {
            string[string[s].neighborlist[i]].mark = string_mark;
        }
        if (i + 1 < string[s].neighbors) {
            string[string[s].neighborlist[i + 1]].mark = string_mark;
        }
    }
}

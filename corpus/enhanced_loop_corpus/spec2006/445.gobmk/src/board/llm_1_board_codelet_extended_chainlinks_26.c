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
    for (int outer = 0; outer < (s->neighbors + 15) / 16; outer++) {
        for (int inner = 0; inner < 16; inner++) {
            int n = outer * 16 + inner;
            if (n < s->neighbors) {
                adj[n] = string[s->neighborlist[n]].origin;
                string[string_number[adj[n]]].mark = string_mark;
            }
        }
    }
}

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



void loop() {
    for (n = 0; n < s->neighbors; n++) {
        if (s->neighborlist[n] >= 0) {
            adj[n] = string[s->neighborlist[n]].origin;
            string[string_number[adj[n]]].mark = string_mark;
        }
    }
}

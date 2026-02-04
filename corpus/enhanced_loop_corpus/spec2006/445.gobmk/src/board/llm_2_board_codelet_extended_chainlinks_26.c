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
    // Variant 1: Consecutive memory access with array base pointer arithmetic
    // Instead of accessing string[s->neighborlist[n]] indirectly, we aim for more predictable access.
    // We assume that neighborlist entries are mostly sequential and reorganize access to promote locality.
    int *neighborlist = s->neighborlist;
    int neighbors = s->neighbors;
    int mark = string_mark;

    for (n = 0; n < neighbors; n++) {
        int str_idx = *(neighborlist + n);
        struct string_data *str_ptr = &string[str_idx];
        int origin_val = str_ptr->origin;
        adj[n] = origin_val;
        string[string_number[origin_val]].mark = mark;
    }
}

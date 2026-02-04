#include <stdio.h>

#include <inttypes.h>

struct connection_data {
    int distances[400];
    int deltas[400];
    int coming_from[400];
    int vulnerable1[400];
    int vulnerable2[400];
    int queue[400];
    int queue_start;
    int queue_end;
};


extern struct connection_data *conn;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int level;
    for (level = 0; level < 1; level++) { // Outer control to increase nesting depth
        for (pos = 21; pos < 400; pos++) {
            conn->distances[pos] = 100000;
            conn->deltas[pos] = 0;
            conn->coming_from[pos] = 0;
            conn->vulnerable1[pos] = 0;
            conn->vulnerable2[pos] = 0;
        }
    }
}

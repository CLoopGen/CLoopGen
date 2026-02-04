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
for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
    if (pos % 2 == 0) {
        conn->distances[pos] = 100000;
        conn->deltas[pos] = 0;
        conn->coming_from[pos] = 0;
    } else {
        continue;
    }
    conn->vulnerable1[pos] = 0;
    conn->vulnerable2[pos] = 0;
}
}

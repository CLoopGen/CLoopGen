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
    int offset = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    for (pos = offset; pos < end; pos += 2) {
        // First iteration half: initialize even indices
        conn->distances[pos] = 100000;
        conn->deltas[pos] = 0;
        conn->coming_from[pos] = 0;
        conn->vulnerable1[pos] = 0;
        conn->vulnerable2[pos] = 0;
        
        if (pos + 1 < end) {
            // Introduce WAW hazard possibility by writing same location in different iterations
            // via out-of-order potential — though not enforced, dependency is created
            conn->distances[pos + 1] = 100000;
            conn->deltas[pos + 1] = 0;
            conn->coming_from[pos + 1] = 0;
            conn->vulnerable1[pos + 1] = 0;
            conn->vulnerable2[pos + 1] = 0;
        }
    }
    // Eliminate loop-carried dependency by making each iteration independent
    // except for index stepping — no data flows between iterations
}

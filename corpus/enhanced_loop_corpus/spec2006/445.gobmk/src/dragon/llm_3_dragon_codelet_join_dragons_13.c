#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

struct dragon_data {
    int color;
    int id;
    int origin;
    int size;
    float effective_size;
    int crude_status;
    int owl_threat_status;
    int owl_status;
    int owl_attack_point;
    int owl_attack_code;
    int owl_attack_certain;
    int owl_second_attack_point;
    int owl_defense_point;
    int owl_defense_code;
    int owl_defense_certain;
    int owl_second_defense_point;
    int status;
    int owl_attack_kworm;
    int owl_defense_kworm;
};


extern Intersection board[421];
extern struct dragon_data dragon[400];
extern int d1;
extern int d2;
extern int ii;
extern int origin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Increased Step Size (simulating cache-friendly or transformed traversal)
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    int stride = 4;  // Access every 4th element to create strided pattern
    // Unroll the loop partially by handling remainder and then striding
    // First handle [start, start+stride) to ensure coverage
    for (int offset = 0; offset < stride; offset++) {
        ii = start + offset;
        if (ii >= end) continue;
        for (; ii < end; ii += stride) {
            if ((board[ii] != 3) && (dragon[ii].origin == d1 || dragon[ii].origin == d2))
                dragon[ii].origin = origin;
        }
    }
}

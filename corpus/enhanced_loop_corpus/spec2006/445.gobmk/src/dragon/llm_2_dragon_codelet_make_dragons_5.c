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
extern int str;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access
    // Instead of sequential access, traverse the board with a stride of 3 to alter memory access pattern.
    int start = 19 + 2;
    int end = (19 + 1) * (19 + 1);
    int stride = 3;
    for (str = start; str < end; str += stride)
        if ((board[str] != 3))
            dragon[str].status = dragon[dragon[str].origin].status;
    
    // Handle remaining elements not covered by stride
    for (str = start + 1; str < end; str++)
        if ((str % stride != 0) && (board[str] != 3))
            dragon[str].status = dragon[dragon[str].origin].status;
}

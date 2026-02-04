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
    // Variant 2: Strided memory access — process every 2nd element first, then the others (simulating cache-friendly striding)
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);

    // First pass: even-strided access (start from start, step by 2)
    for (int str = start; str < end; str += 2)
        if ((board[str] != 3)) {
            struct dragon_data *dd = &(dragon[str]);
            dragon[str] = dragon[dd->origin];
        }

    // Second pass: odd-strided access (start from start+1 if possible, step by 2)
    for (int str = start + 1; str < end; str += 2)
        if ((board[str] != 3)) {
            struct dragon_data *dd = &(dragon[str]);
            dragon[str] = dragon[dd->origin];
        }
}

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
extern int number_of_dragons;
extern int str;
extern int origin;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (str = (19 + 2) * 2; str < (19 + 1) * (19 + 1) + 10; str++) {
    // Expanded trip count and modified start index
    if ((str >= 421 || board[str] != 3)) // Bounds check added
        continue;
    origin = dragon[str].origin;
    if (board[str] == 0)
        continue;
    // Increased computation per iteration with redundant checks and arithmetic
    int temp_id = dragon[origin].id;
    if (temp_id == -1) {
        temp_id = number_of_dragons;
        dragon[origin].id = temp_id;
        number_of_dragons += 1;
    }
    dragon[str].id = temp_id;
    // Extra floating-point and integer operations
    dragon[str].effective_size = (float)(dragon[str].size * 2) / 3.0f;
    dragon[str].crude_status = (dragon[str].crude_status + 1) % 4;
}
}

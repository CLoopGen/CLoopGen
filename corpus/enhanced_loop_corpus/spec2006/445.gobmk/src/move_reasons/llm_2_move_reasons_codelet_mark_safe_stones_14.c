#include <stdio.h>

#include <inttypes.h>

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


typedef unsigned char Intersection;

struct worm_data {
    int color;
    int size;
    float effective_size;
    int origin;
    int liberties;
    int liberties2;
    int liberties3;
    int liberties4;
    int lunch;
    int cutstone;
    int cutstone2;
    int genus;
    int inessential;
    int invincible;
    int unconditional_status;
    int attack_points[10];
    int attack_codes[10];
    int defense_points[10];
    int defense_codes[10];
    int attack_threat_points[10];
    int attack_threat_codes[10];
    int defense_threat_points[10];
    int defense_threat_codes[10];
};


extern struct dragon_data dragon[400];
extern Intersection board[421];
extern struct worm_data worm[400];
extern int color;
extern  char saved_dragons[400];
extern  char saved_worms[400];
extern char safe_stones[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access via Loop Splitting and Sequential Traversal
    // Instead of accessing board[pos], dragon[pos], worm[pos] in scattered fashion,
    // we process elements in a cache-friendly sequential manner with unrolled conditions.
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);

    // Process in forward order, ensuring consecutive memory accesses for better prefetching
    for (pos = start; pos < end; pos++) {
        Intersection current_board = board[pos];
        struct dragon_data* d_ptr = &dragon[pos];
        struct worm_data* w_ptr = &worm[pos];
        char save_dragon = saved_dragons[pos];
        char save_worm = saved_worms[pos];

        if (current_board == (1 + 2 - color)) {
            if (d_ptr->status == 0 || (w_ptr->attack_codes[0] != 0 && w_ptr->defense_codes[0] == 0))
                safe_stones[pos] = 0;
            else
                safe_stones[pos] = 1;
        } else if (current_board == color) {
            if ((w_ptr->attack_codes[0] != 0 && (w_ptr->defense_codes[0] == 0 || !save_worm)) || d_ptr->status == 0)
                safe_stones[pos] = 0;
            else if (save_dragon)
                safe_stones[pos] = 2;
            else if (d_ptr->status == 2)
                safe_stones[pos] = 0;
            else
                safe_stones[pos] = 1;
        } else {
            safe_stones[pos] = 0;
        }
    }
}

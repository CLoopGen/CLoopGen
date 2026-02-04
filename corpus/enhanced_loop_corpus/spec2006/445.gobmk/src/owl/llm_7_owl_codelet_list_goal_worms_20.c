#include <stdio.h>

#include <inttypes.h>

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


struct eyevalue {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
};


struct dragon_data2 {
    int origin;
    int adjacent[10];
    int neighbors;
    int hostile_neighbors;
    int moyo_size;
    float moyo_territorial_value;
    int safety;
    float weakness;
    float weakness_pre_owl;
    int escape_route;
    struct eyevalue genus;
    int heye;
    int lunch;
    int semeai;
    int semeai_margin_of_safety;
    int surround_status;
    int surround_size;
};


struct eye_data {
    int color;
    int esize;
    int msize;
    int origin;
    struct eyevalue value;
    int attack_point;
    int defense_point;
    char marginal;
    char type;
    char neighbors;
    char marginal_neighbors;
    char cut;
};


struct half_eye_data {
    float value;
    char type;
    int num_attacks;
    int attack_point[4];
    int num_defends;
    int defense_point[4];
};


struct local_owl_data {
    char goal[400];
    char boundary[400];
    char escape_values[400];
    int color;
    struct eye_data my_eye[400];
    struct half_eye_data half_eye[400];
    int lunch[10];
    int lunch_attack_code[10];
    int lunch_attack_point[10];
    int lunch_defend_code[10];
    int lunch_defense_point[10];
    char inessential[400];
    int lunches_are_current;
    char safe_move_cache[400];
    int restore_from;
    int number_in_stack;
};


extern Intersection board[421];
extern struct worm_data worm[400];
extern struct dragon_data dragon[400];
extern struct dragon_data2 *dragon2;
extern struct local_owl_data *owl;
extern int goal_worm[15];
extern int pos;
extern int k;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_goal_worm[15];
    int local_w = 0;
    for (k = 0; k < dragon2[dragon[pos].id].neighbors && local_w < 15; k++) {
        int d = dragon2[dragon[pos].id].adjacent[k];
        int match_color = (dragon[dragon2[d].origin].color == owl->color);
        if (!match_color) continue;
        for (int ii = (19 + 2); ii < (19 + 1) * (19 + 1) && local_w < 15; ii++) {
            int is_valid = (board[ii] != 3) & (board[ii] != 0);
            is_valid &= (worm[ii].origin == ii);
            is_valid &= (worm[ii].size >= 3);
            is_valid &= (dragon[ii].id == d);
            temp_goal_worm[local_w] = ii;
            local_w += is_valid;
        }
    }
    // Eliminate loop-carried dependency on global 'w' by updating once at end
    for (int i = 0; i < local_w; i++)
        goal_worm[w + i] = temp_goal_worm[i];
    w += local_w;
}

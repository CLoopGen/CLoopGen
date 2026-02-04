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


struct eyevalue {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
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


extern int delta[8];
extern Intersection board[421];
extern struct dragon_data dragon[400];
extern int pos;
extern struct local_owl_data *owl;
extern char boundary_mark;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index mapping array to simulate irregular memory access pattern
    int index_map[4] = {2, 0, 3, 1}; // Reordered access: strided and non-sequential
    for (int k = 0; k < 4; k++) {
        int mapped_k = index_map[k];
        int pos2 = pos + delta[mapped_k];
        if ((board[pos2] != 3) && owl->boundary[pos2] > boundary_mark)
            boundary_mark = owl->boundary[pos2];
        if (board[pos2] == owl->color && dragon[pos2].color == owl->color && dragon[pos2].status == 1 && !owl->goal[pos2])
            boundary_mark = 2;
    }
}

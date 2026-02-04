#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

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


extern Intersection board[421];
extern struct eye_data white_eye[400];
extern struct eye_data black_eye[400];
extern int color;
extern char escape_value[400];
extern int ii;
extern int mx[400];
extern int queue[361];
extern int queue_start;
extern int queue_end;
extern int other;
extern int distance;
extern int escape_potential;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (distance = 0; distance <= 4; distance++) {
    int save_queue_end = queue_end;
    for (; queue_start < save_queue_end; queue_start++) {
        ii = queue[queue_start];
        
        int skip = 0;
        if (color == 1) {
            if ((white_eye[ii].type & 4) || white_eye[ii].cut == 1)
                skip = 1;
        } else if (color == 2) {
            if ((black_eye[ii].type & 4) || black_eye[ii].cut == 1)
                skip = 1;
        }
        if (skip) continue;

        if (distance == 4) {
            escape_potential += escape_value[ii];
            continue;
        }

        int pos, neighbor;

        // North
        pos = ii + (19 + 1);
        if ((board[pos] != 3) && !mx[pos]) {
            if (board[pos] == color || 
                (board[pos] == 0 && 
                 (board[pos + 1] != 3) && board[pos + 1] != other &&
                 (board[pos + (19 + 1)] != 3) && board[pos + (19 + 1)] != other &&
                 (board[pos - 1] != 3) && board[pos - 1] != other)) {
                queue[queue_end++] = pos;
                mx[pos] = 1;
            }
        }

        // West
        pos = ii - 1;
        if ((board[pos] != 3) && !mx[pos]) {
            if (board[pos] == color || 
                (board[pos] == 0 && 
                 (board[pos + (19 + 1)] != 3) && board[pos + (19 + 1)] != other &&
                 (board[pos - 1] != 3) && board[pos - 1] != other &&
                 (board[pos - (19 + 1)] != 3) && board[pos - (19 + 1)] != other)) {
                queue[queue_end++] = pos;
                mx[pos] = 1;
            }
        }

        // South
        pos = ii - (19 + 1);
        if ((board[pos] != 3) && !mx[pos]) {
            if (board[pos] == color || 
                (board[pos] == 0 && 
                 (board[pos - 1] != 3) && board[pos - 1] != other &&
                 (board[pos - (19 + 1)] != 3) && board[pos - (19 + 1)] != other &&
                 (board[pos + 1] != 3) && board[pos + 1] != other)) {
                queue[queue_end++] = pos;
                mx[pos] = 1;
            }
        }

        // East
        pos = ii + 1;
        if ((board[pos] != 3) && !mx[pos]) {
            if (board[pos] == color || 
                (board[pos] == 0 && 
                 (board[pos - (19 + 1)] != 3) && board[pos - (19 + 1)] != other &&
                 (board[pos + 1] != 3) && board[pos + 1] != other &&
                 (board[pos + (19 + 1)] != 3) && board[pos + (19 + 1)] != other)) {
                queue[queue_end++] = pos;
                mx[pos] = 1;
            }
        }

        if (distance == 0) {
            // Northwest diagonal
            if (board[ii + (19 + 1)] == 0 && board[ii - 1] == 0) {
                pos = ii + (19 + 1) - 1;
                if (!mx[pos] && (board[pos] == color || 
                    (board[pos] == 0 && 
                     (board[pos + (19 + 1)] != 3) && board[pos + (19 + 1)] != other &&
                     (board[pos - 1] != 3) && board[pos - 1] != other))) {
                    queue[queue_end++] = pos;
                    mx[pos] = 1;
                }
            }

            // Southwest diagonal
            if (board[ii - 1] == 0 && board[ii - (19 + 1)] == 0) {
                pos = ii - (19 + 1) - 1;
                if (!mx[pos] && (board[pos] == color || 
                    (board[pos] == 0 && 
                     (board[pos - 1] != 3) && board[pos - 1] != other &&
                     (board[pos - (19 + 1)] != 3) && board[pos - (19 + 1)] != other))) {
                    queue[queue_end++] = pos;
                    mx[pos] = 1;
                }
            }

            // Southeast diagonal
            if (board[ii - (19 + 1)] == 0 && board[ii + 1] == 0) {
                pos = ii - (19 + 1) + 1;
                if (!mx[pos] && (board[pos] == color || 
                    (board[pos] == 0 && 
                     (board[pos - (19 + 1)] != 3) && board[pos - (19 + 1)] != other &&
                     (board[pos + 1] != 3) && board[pos + 1] != other))) {
                    queue[queue_end++] = pos;
                    mx[pos] = 1;
                }
            }

            // Northeast diagonal
            if (board[ii + 1] == 0 && board[ii + (19 + 1)] == 0) {
                pos = ii + (19 + 1) + 1;
                if (!mx[pos] && (board[pos] == color || 
                    (board[pos] == 0 && 
                     (board[pos + 1] != 3) && board[pos + 1] != other &&
                     (board[pos + (19 + 1)] != 3) && board[pos + (19 + 1)] != other))) {
                    queue[queue_end++] = pos;
                    mx[pos] = 1;
                }
            }
        }
    }
}
}

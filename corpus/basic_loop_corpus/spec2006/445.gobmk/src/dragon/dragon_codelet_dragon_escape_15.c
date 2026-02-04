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
    while (queue_start < save_queue_end)
        {
            ii = queue[queue_start];
            queue_start++;
            if ((color == 1 && ((white_eye[ii].type & 4) || white_eye[ii].cut == 1)) || (color == 2 && ((black_eye[ii].type & 4) || black_eye[ii].cut == 1)))
                continue;
            if (distance == 4)
                escape_potential += escape_value[ii];
            else {
                if ((board[((ii) + (19 + 1))] != 3) && !mx[((ii) + (19 + 1))] && (board[((ii) + (19 + 1))] == color || (board[((ii) + (19 + 1))] == 0 && (board[((ii) + (19 + 1) + 1)] != 3) && board[((ii) + (19 + 1) + 1)] != other && (board[((ii) + 2 * (19 + 1))] != 3) && board[((ii) + 2 * (19 + 1))] != other && (board[((ii) + (19 + 1) - 1)] != 3) && board[((ii) + (19 + 1) - 1)] != other)))
                    (queue[queue_end++] = (((ii) + (19 + 1))) , mx[((ii) + (19 + 1))] = 1);
                if ((board[((ii) - 1)] != 3) && !mx[((ii) - 1)] && (board[((ii) - 1)] == color || (board[((ii) - 1)] == 0 && (board[((ii) + (19 + 1) - 1)] != 3) && board[((ii) + (19 + 1) - 1)] != other && (board[((ii) - 2)] != 3) && board[((ii) - 2)] != other && (board[((ii) - (19 + 1) - 1)] != 3) && board[((ii) - (19 + 1) - 1)] != other)))
                    (queue[queue_end++] = (((ii) - 1)) , mx[((ii) - 1)] = 1);
                if ((board[((ii) - (19 + 1))] != 3) && !mx[((ii) - (19 + 1))] && (board[((ii) - (19 + 1))] == color || (board[((ii) - (19 + 1))] == 0 && (board[((ii) - (19 + 1) - 1)] != 3) && board[((ii) - (19 + 1) - 1)] != other && (board[((ii) - 2 * (19 + 1))] != 3) && board[((ii) - 2 * (19 + 1))] != other && (board[((ii) - (19 + 1) + 1)] != 3) && board[((ii) - (19 + 1) + 1)] != other)))
                    (queue[queue_end++] = (((ii) - (19 + 1))) , mx[((ii) - (19 + 1))] = 1);
                if ((board[((ii) + 1)] != 3) && !mx[((ii) + 1)] && (board[((ii) + 1)] == color || (board[((ii) + 1)] == 0 && (board[((ii) - (19 + 1) + 1)] != 3) && board[((ii) - (19 + 1) + 1)] != other && (board[((ii) + 2)] != 3) && board[((ii) + 2)] != other && (board[((ii) + (19 + 1) + 1)] != 3) && board[((ii) + (19 + 1) + 1)] != other)))
                    (queue[queue_end++] = (((ii) + 1)) , mx[((ii) + 1)] = 1);
                if (distance == 0) {
                    if (board[((ii) + (19 + 1))] == 0 && board[((ii) - 1)] == 0 && !mx[((ii) + (19 + 1) - 1)] && (board[((ii) + (19 + 1) - 1)] == color || (board[((ii) + (19 + 1) - 1)] == 0 && (board[((((ii) + (19 + 1) - 1)) + (19 + 1))] != 3) && board[((((ii) + (19 + 1) - 1)) + (19 + 1))] != other && (board[((((ii) + (19 + 1) - 1)) - 1)] != 3) && board[((((ii) + (19 + 1) - 1)) - 1)] != other)))
                        (queue[queue_end++] = (((ii) + (19 + 1) - 1)) , mx[((ii) + (19 + 1) - 1)] = 1);
                    if (board[((ii) - 1)] == 0 && board[((ii) - (19 + 1))] == 0 && !mx[((ii) - (19 + 1) - 1)] && (board[((ii) - (19 + 1) - 1)] == color || (board[((ii) - (19 + 1) - 1)] == 0 && (board[((((ii) - (19 + 1) - 1)) - 1)] != 3) && board[((((ii) - (19 + 1) - 1)) - 1)] != other && (board[((((ii) - (19 + 1) - 1)) - (19 + 1))] != 3) && board[((((ii) - (19 + 1) - 1)) - (19 + 1))] != other)))
                        (queue[queue_end++] = (((ii) - (19 + 1) - 1)) , mx[((ii) - (19 + 1) - 1)] = 1);
                    if (board[((ii) - (19 + 1))] == 0 && board[((ii) + 1)] == 0 && !mx[((ii) - (19 + 1) + 1)] && (board[((ii) - (19 + 1) + 1)] == color || (board[((ii) - (19 + 1) + 1)] == 0 && (board[((((ii) - (19 + 1) + 1)) - (19 + 1))] != 3) && board[((((ii) - (19 + 1) + 1)) - (19 + 1))] != other && (board[((((ii) - (19 + 1) + 1)) + 1)] != 3) && board[((((ii) - (19 + 1) + 1)) + 1)] != other)))
                        (queue[queue_end++] = (((ii) - (19 + 1) + 1)) , mx[((ii) - (19 + 1) + 1)] = 1);
                    if (board[((ii) + 1)] == 0 && board[((ii) + (19 + 1))] == 0 && !mx[((ii) + (19 + 1) + 1)] && (board[((ii) + (19 + 1) + 1)] == color || (board[((ii) + (19 + 1) + 1)] == 0 && (board[((((ii) + (19 + 1) + 1)) + 1)] != 3) && board[((((ii) + (19 + 1) + 1)) + 1)] != other && (board[((((ii) + (19 + 1) + 1)) + (19 + 1))] != 3) && board[((((ii) + (19 + 1) + 1)) + (19 + 1))] != other)))
                        (queue[queue_end++] = (((ii) + (19 + 1) + 1)) , mx[((ii) + (19 + 1) + 1)] = 1);
                }
            }
        }
}

}

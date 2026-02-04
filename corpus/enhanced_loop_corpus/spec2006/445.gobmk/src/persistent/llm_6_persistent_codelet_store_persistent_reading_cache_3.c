#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k_start = 21;
    int k_end = 400;
    for (k = k_start; k < k_end; k++) {
        if (!(board[k] != 3))
            continue;
        if (active[k] != 0)
            continue;

        char temp_north = active[k + 20];
        char temp_west = active[k - 1];
        char temp_south = active[k - 20];
        char temp_east = active[k + 1];

        char flag = 0;
        if ((board[k + 20] != 3) && temp_north > 0 && temp_north < 4)
            flag = 1;
        else if ((board[k - 1] != 3) && temp_west > 0 && temp_west < 4)
            flag = 1;
        else if ((board[k - 20] != 3) && temp_south > 0 && temp_south < 4)
            flag = 1;
        else if ((board[k + 1] != 3) && temp_east > 0 && temp_east < 4)
            flag = 1;

        if (flag)
            active[k] = 4;
    }
}

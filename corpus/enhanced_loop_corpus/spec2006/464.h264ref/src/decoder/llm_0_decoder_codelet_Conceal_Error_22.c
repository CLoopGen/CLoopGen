#include <stdio.h>

#include <inttypes.h>

extern unsigned short **inY;
extern unsigned short ***refY;
extern int i;
extern int j;
extern int ref_inx;
extern int pos_y;
extern int pos_x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int jj = 0; jj < 4; jj++)
        for (int ii = 0; ii < 4; ii++)
            for (int j = 0; j < 4; j++)
                for (int i = 0; i < 4; i++)
                    inY[pos_y + jj*4 + j][pos_x + ii*4 + i] = refY[ref_inx][pos_y + jj*4 + j][pos_x + ii*4 + i];
}

#include <stdio.h>

extern double ***z;
extern int m1;
extern int i;
extern int j1[10][2];
extern int j2[10][2];
extern int j3[10][2];



void loop(){
    double temp = 0.0;
    for (i = 10 - 1; i >= m1; i--) {
        temp += z[j3[i][1]][j2[i][1]][j1[i][1]]; // Introduce RAW dependency: read before write via temp
        z[j3[i][1]][j2[i][1]][j1[i][1]] = temp; // WAW and WAR dependencies introduced through sequential updates to same location and temp
    }
}

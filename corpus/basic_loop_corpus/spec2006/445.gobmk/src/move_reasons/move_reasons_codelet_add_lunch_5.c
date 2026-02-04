#include <stdio.h>

#include <inttypes.h>

extern int lunch_dragon[240];
extern int lunch_worm[240];
extern int next_lunch;
extern int k;
extern int dragon1;
extern int worm1;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (k = 0; k < next_lunch; k++)
    if ((lunch_dragon[k] == dragon1) && (lunch_worm[k] == worm1))
        return;

}

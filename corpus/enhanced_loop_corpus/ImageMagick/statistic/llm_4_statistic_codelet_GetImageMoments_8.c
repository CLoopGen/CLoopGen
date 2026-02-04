#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

typedef struct _ChannelMoments {
    double invariant[9];
    PointInfo centroid;
    PointInfo ellipse_axis;
    double ellipse_angle;
    double ellipse_eccentricity;
    double ellipse_intensity;
} ChannelMoments;

extern ChannelMoments *channel_moments;
extern double M02[129];
extern double M03[129];
extern double M11[129];
extern double M12[129];
extern double M20[129];
extern double M21[129];
extern double M30[129];
extern ssize_t c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (c = 0; c <= 64; c++) {
    if (c % 2 == 0) {
        channel_moments[c].invariant[0] = M20[c] + M02[c];
        channel_moments[c].invariant[1] = (M20[c] - M02[c]) * (M20[c] - M02[c]) + 4. * M11[c] * M11[c];
        channel_moments[c].invariant[2] = (M30[c] - 3. * M12[c]) * (M30[c] - 3. * M12[c]) + (3. * M21[c] - M03[c]) * (3. * M21[c] - M03[c]);
        channel_moments[c].invariant[3] = (M30[c] + M12[c]) * (M30[c] + M12[c]) + (M21[c] + M03[c]) * (M21[c] + M03[c]);
    } else {
        channel_moments[c].invariant[4] = (M30[c] - 3. * M12[c]) * (M30[c] + M12[c]) * ((M30[c] + M12[c]) * (M30[c] + M12[c]) - 3. * (M21[c] + M03[c]) * (M21[c] + M03[c])) + (3. * M21[c] - M03[c]) * (M21[c] + M03[c]) * (3. * (M30[c] + M12[c]) * (M30[c] + M12[c]) - (M21[c] + M03[c]) * (M21[c] + M03[c]));
        channel_moments[c].invariant[5] = (M20[c] - M02[c]) * ((M30[c] + M12[c]) * (M30[c] + M12[c]) - (M21[c] + M03[c]) * (M21[c] + M03[c])) + 4. * M11[c] * (M30[c] + M12[c]) * (M21[c] + M03[c]);
        channel_moments[c].invariant[6] = (3. * M21[c] - M03[c]) * (M30[c] + M12[c]) * ((M30[c] + M12[c]) * (M30[c] + M12[c]) - 3. * (M21[c] + M03[c]) * (M21[c] + M03[c])) - (M30[c] - 3 * M12[c]) * (M21[c] + M03[c]) * (3. * (M30[c] + M12[c]) * (M30[c] + M12[c]) - (M21[c] + M03[c]) * (M21[c] + M03[c]));
        channel_moments[c].invariant[7] = M11[c] * ((M30[c] + M12[c]) * (M30[c] + M12[c]) - (M03[c] + M21[c]) * (M03[c] + M21[c])) - (M20[c] - M02[c]) * (M30[c] + M12[c]) * (M03[c] + M21[c]);
    }
}
}

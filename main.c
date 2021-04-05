#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define XDIM 150
#define YDIM 80
#define DIST 20
#define SCALE 100

void plot(char[YDIM][XDIM]);

int main(int argc, char **argv)
{
    int xoff = XDIM / 2;
    int yoff = YDIM / 2;
    char output[YDIM][XDIM];
    memset(output, ' ', XDIM * YDIM * sizeof(char));
    for(float y = 1.0; y <= 8.0; y += 0.2) // will need to lower the max y from 8 to properly rotate later
    {
        for(float t = 0.0; t <= 6.28; t += 0.02)
        {
            double xproj = ( 5 * (1/y) * sin(t) * SCALE ) / ( ( (sqrt(2)/2) * (y + (1/y) * cos(t)) ) + DIST );
            double yproj = ( 5 * (sqrt(2) / 2) * (y - (1/y) * cos(t)) * SCALE) / ( (sqrt(2)/2) * (y + (1/y) * cos(t)) + DIST);
            int xtrunc = xproj;
            int ytrunc = yproj;
            output[xoff - xtrunc - 35][yoff + ytrunc - 25] = '*'; // subtracted constants in matrices meant to fit in frame better
        }
    }
    plot(output);
}

void plot(char out[YDIM][XDIM])
{
    for(int y = 0; y < YDIM; y++)
    {
        for(int x = 0; x < XDIM; x++)
        {
            printf("%c", out[y][x]);
        }
        printf("\n");
    }
}

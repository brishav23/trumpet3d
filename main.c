#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "macros.h"

void plot(char[VDIM][HDIM]);

void empty(char[VDIM][HDIM]);

int sign(float);

int main(int argc, char **argv)
{
    printf("\x1b[2J"); // ANSI escape code to clear screen
    int xoff = HDIM / 2;
    int yoff = VDIM / 2;
    char output[VDIM][HDIM];
    empty(output);
    float p = 0.0;
    while(1)
    {
        for(float y = 1.0; y <= 4; y += 0.02) // will need to lower the max y from 8 to properly rotate later
        {
            for(float t = 0.0; t <= 6.28; t += 0.02)
            {
                int xproj = (int)(ZP * XR * SCALE / ZR);
                int yproj = (int)(ZP * YR * 2.25 * SCALE / ZR); // SCALE * 2 to compensate for more vertical space than horizontal
                float light = LIGHT;
                // .,-~:;=!*#$@
                if(light < 0.0833) output[xoff - xproj + DMOVE][yoff + yproj + RMOVE] = '.';
                else if(light < 0.1667) output[xoff - xproj + DMOVE][yoff + yproj + RMOVE] = ',';
                else if(light < 0.2500) output[xoff - xproj + DMOVE][yoff + yproj + RMOVE] = '-';
                else if(light < 0.3333) output[xoff - xproj + DMOVE][yoff + yproj + RMOVE] = '~';
                else if(light < 0.4167) output[xoff - xproj + DMOVE][yoff + yproj + RMOVE] = ':';
                else if(light < 0.5000) output[xoff - xproj + DMOVE][yoff + yproj + RMOVE] = ';';
                else if(light < 0.5833) output[xoff - xproj + DMOVE][yoff + yproj + RMOVE] = '=';
                else if(light < 0.6667) output[xoff - xproj + DMOVE][yoff + yproj + RMOVE] = '!';
                else if(light < 0.7500) output[xoff - xproj + DMOVE][yoff + yproj + RMOVE] = '*';
                else if(light < 0.8333) output[xoff - xproj + DMOVE][yoff + yproj + RMOVE] = '#';
                else if(light < 0.9167) output[xoff - xproj + DMOVE][yoff + yproj + RMOVE] = '$';
                else output[xoff - xproj + DMOVE][yoff + yproj + RMOVE] = '@';
            }
        }
        p += 0.01;
        if(p >= 6.28) p = 0;
        plot(output);
        empty(output);
    }
}

void plot(char out[VDIM][HDIM])
{
    printf("\x1b[H"); // ANSI escape sequence to return to position 0,0
    for(int x = 0; x < VDIM; x++)
    {
        for(int y = 0; y < HDIM; y++)
        {
            printf("%c", out[x][y]);
        }
        printf("\n");
    }
}

void empty(char out[VDIM][HDIM])
{
    memset(out, ' ', HDIM * VDIM * sizeof(char));
}

int sign(float n)
{
    if(n >= 0) return(1);
    else return(-1);
}

#include "HEADERS/includes.h"
#include "HEADERS/render.h"


void render(){
    system("clear");
    for (int i = 0; i < SIZE_H; i++)
    {
        for (int j = 0; j < SIZE_W; j++)
        {
            putc(BUFFER[BUFF_XY(j, i)], stdout);
        }
        putc('\n', stdout);
    }
    
}
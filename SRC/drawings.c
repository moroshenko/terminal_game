#include "HEADERS/includes.h"
#include "HEADERS/drawings.h"
#include "HEADERS/render.h"
#include "HEADERS/player.h"

void draw_sprite(struct pixel* px, int x, int y){
    for(;px != NULL;px = px->next_pixel){
        BUFFER[BUFF_XY(x + px->x, y + px->y)] = px->c;
    }
}

struct pixel *create_pixel(int x, int y, char c){
    struct pixel *px = (struct pixel*)malloc(sizeof (struct pixel));
    px->x = x;
    px->y = y;
    px->c = c;
    return px;
}

void free_sprite(struct pixel *sprite){
    for(;sprite != NULL; sprite = sprite->next_pixel){
        free(sprite);
    } 
}

/*SORRY, BUT THIS SHIT DOESN'T WORK
  YAY! THIS SHIT START WORK
  ...
  I MISTAKE. IT DOEN'T WORK!!!*/
void create_figure(const int lines_num, ...){

    va_list ap;
    va_start(ap, lines_num);

    struct pixel *lines[lines_num]; 
    for(int i = 0; i < lines_num; i++)
        lines[i] = va_arg(ap, struct pixel*);
    
    for(int i = 0; i < lines_num - 1;i++){
        lines[i]->next_pixel = lines[i+1];
    }
    va_end(ap);

}
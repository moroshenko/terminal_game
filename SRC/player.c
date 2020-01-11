#include "HEADERS/includes.h"
#include "HEADERS/player.h"
#include "HEADERS/drawings.h"
#include "HEADERS/render.h"

struct player* init_player(){
    struct player* pl = (struct player *)malloc(sizeof(struct player));

    struct pixel* px1 = create_pixel(0, 0, 'x');
    struct pixel* px2 = create_pixel(0, 1, 'x');
    struct pixel* px3 = create_pixel(0, 2, 'x');
    struct pixel* px4 = create_pixel(1, 1, 'x');
    px1->next_pixel = px2;
    px2->next_pixel = px3;
    px3->next_pixel = px4;
    px4->next_pixel = NULL;
    pl->x = 1;
    pl->y = 1;
    pl->width = 2;
    pl->heidth = 3;
    pl->sprite = (void*)px1;
}

void free_player(struct player* pl){
    free_sprite((struct pixel *)pl->sprite);
    free(pl);
}

#include "HEADERS/includes.h"
#include "HEADERS/enemy.h"
#include "HEADERS/drawings.h"
#include "HEADERS/render.h"

struct enemy* create_enemy(struct enemy *prev_enemy){
    struct enemy* en = (struct enemy *)malloc(sizeof(struct enemy));

    struct pixel* px1 = create_pixel(0, 1, 'x');
    struct pixel* px2 = create_pixel(1, 0, 'x');
    struct pixel* px3 = create_pixel(2, 1, 'x');
    px1->next_pixel = px2;
    px2->next_pixel = px3;
    px3->next_pixel = NULL;
    en->x = 1;
    en->y = 1;

    en->sprite = (void*)px1;
}

void free_enemy(struct enemy* en){
    /*for(;sprite != NULL; sprite = sprite->next_pixel){
        free(sprite);
    } */
    free_sprite((struct pixel *)en->sprite);
    free(en);
}

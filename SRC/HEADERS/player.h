typedef struct player{
    int x;
    int y;
    int width;
    int heidth;
    void *sprite;
}player;

#define GET_PL_SPRITE(plr) ((struct pixel *)plr->sprite)

struct player* init_player();
void free_player(struct player* pl);
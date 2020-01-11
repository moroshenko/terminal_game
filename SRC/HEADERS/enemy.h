typedef struct enemy{
    int x;
    int y;
    int width;
    int heidth;
    void *sprite;
    struct enemy* prev_enemy;
}enemy;

#define GET_PL_SPRITE(plr) ((struct pixel *)plr->sprite)

void move_enemy(struct enemy* en);
struct enemy* create_enemy(struct enemy* prev_enemy);
void free_enemy(struct enemy* pl);
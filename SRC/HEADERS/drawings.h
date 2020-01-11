typedef struct pixel{
    int x;
    int y;
    char c;
    struct pixel *next_pixel;
    
}pixel;

void draw_sprite(struct pixel *sprite, int x, int y);

struct pixel *create_pixel(int x, int y, char c);
void free_sprite(struct pixel *sprite);
void create_sprite(const int pixels, ...);
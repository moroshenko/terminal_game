#define SIZE_H 20
#define SIZE_W 80

#define BUFF_XY(x, y) ((y) * SIZE_W + x)
#define BUFF_XY_CHAR(x, y) (BUFFER[BUFF_XY(x-1, y-1)])
#define BUFF_FILL(c)(memset(BUFFER, c, sizeof(BUFFER)))

char BUFFER[SIZE_H*SIZE_W+1];

void render();
#include "HEADERS/includes.h"
#include "HEADERS/conio.h"
#include "HEADERS/main.h"
#include "HEADERS/drawings.h"
#include "HEADERS/render.h"
#include "HEADERS/player.h"
#include "HEADERS/enemy.h"

#define WIDTH 800
#define HEIDTH 600
#define false 0
#define true 1

/*GLOBAL VARIABLES*/
char IS_QUIT;

struct player *PLAYER;
struct pixel *PLAYER_SPRITE;

int main(int argc, char *argv[])
{
    /*VARIABLES*/
    pthread_t event_thread;
    pthread_t render_thread;
    pthread_t enemy_thread;

    void *thr_ret;

    /*INIT VARIABLES*/
    IS_QUIT = 0;
    PLAYER = init_player();
    PLAYER_SPRITE = GET_PL_SPRITE(PLAYER);

    /*INIT SCREEN*/
    system("setterm -cursor off");
    BUFF_FILL(' ');

    /*CREATING THREADS*/
    if(pthread_create(&event_thread, NULL, event_catcher, NULL) == -1)
        error("cant create event thread");
    if(pthread_create(&render_thread, NULL, renderer, NULL) == -1)
        error("cant create event thread");

    while (1)
    { 
        if(IS_QUIT)
            break;
    }

    /*EXIT*/
    if(pthread_join(event_thread, &thr_ret))
        error("cant join thread");
    if(pthread_join(render_thread, &thr_ret))
        error("cant join thread");
    system("setterm -cursor on");
    free_player(PLAYER);
    return 0;
}

/*
 *---------
 *END OF MAIN FUNCTION
 *---------
*/

/*THREAD, THAT CATCH EVENTS AND CALL FUNCTIONS*/
void *event_catcher(void *arg){

    while(!IS_QUIT){
        char c = getch();
        switch(c){
            case 'q':
                IS_QUIT = 1; 
                break;
            
            /*MOVEMENT*/
            case 'w':
                if(PLAYER->y > 0)
                    PLAYER->y--; 
                break;
            case 's':
                if(PLAYER->y < SIZE_H - PLAYER->heidth)
                    PLAYER->y++; 
                break;
            case 'd':
                if(PLAYER->x < SIZE_W - PLAYER->width)
                    PLAYER->x++; 
                break;
            case 'a':
                if(PLAYER->x > 0)
                    PLAYER->x--;  
                break;           
            
        }
    }
    return NULL;
}

/*THREAD, THAT RENDER BUFFER*/
void *renderer(void *arg){

    while(!IS_QUIT){
        usleep(41000);
        BUFF_FILL(' ');
        draw_sprite(PLAYER_SPRITE, PLAYER->x, PLAYER->y);
        render(); /*PRINTS BEFFER*/
    }
    return NULL;
}

void error(char *msg)
{
    char error_message[255];
    sprintf(error_message, "%s: %s", msg, strerror(errno));
    fprintf(stderr, "%s", error_message);
    exit(1);
}

void warning(char *msg)
{
    char error_message[255];
    sprintf(error_message, "%s: %s", msg, strerror(errno));
    fprintf(stderr, "%s", error_message);
}

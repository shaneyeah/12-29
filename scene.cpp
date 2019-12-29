/*#include"defineclass.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdio>

int num_of_block[10];

void scene_initialize(int stage)
{
    extern block[10][100];
    SDL_Rect block_viewpoint[100];
for(int i=0;i<100;i++)
{
    block_viewpoint[i].x=block[stage][i].x;
    block_viewpoint[i].y=block[stage][i].y;
    block_viewpoint[i].w=step;
    block_viewpoint[i].h=step;
    SDL_RenderSetViewport( gRenderer, &block_viewpoint[i] );
    SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
    SDL_RenderPresent( gRenderer );
}
}

class Block
{
    public:
    bool lop; // letterorpicture letter = 0, picture = 1
    int mode; //Sub=0 or Obj=1 or Conj=2
    int which; //enum出來的東西
    int  wol; //winorlose win is 0, lose is 1, nothing is 2
    bool pu; //pushstate
    bool snk; //sinkstate
    bool stp; //stoptstate
    bool opn; //openstate
    bool sht; //shutstate
    int x,y;
};



//define all the objects
*/

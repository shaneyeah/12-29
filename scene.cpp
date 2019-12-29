#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdio>
#include <string>
#include<iostream>

using namespace std;
//Loads individual image as texture
SDL_Texture* loadTexture( std::string path );

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

SDL_Texture* gTexture = NULL;


SDL_Surface* gScreenSurface = NULL;

int step=60;
int SCREEN_WIDTH=1000,SCREEN_HEIGHT=640;
int STAGE_WIDTH[10]{12*step};
int STAGE_HEIGHT[10]{12*step};
//Loads individual image as texture
SDL_Event e;
    //Main loop flag
bool quit = false;
SDL_Surface* gHelloWorld = NULL;

SDL_Texture* loadTexture( std::string path );
//////////////////////////////////////////////
//Current displayed texture


enum direction
{
    _up,
    _down,
    _left,
    _right
};

Block block[10][100];

void setxy(Block &a,int x,int y)
{
    a.x=20+x;
    a.y=10+y;
}

void setstage1()
{
    for(int i=0;i<39;i++)
    {
        block[0][i].lop=1;
        block[0][i].opn=0;
        block[0][i].pu=0;
        block[0][i].sht=0;
        block[0][i].snk=0;
        block[0][i].stp=0;
        block[0][i].wol=2;
        block[0][i].isyou=0;
    }
    for(int i=0;i<4;i++)
    {
        block[0][i].lop=0;
        block[0][i].mode=2;
        block[0][i].which=is;
        block[0][i].pu=1;
    }
        for(int i=4;i<8;i++)
    {
        block[0][i].lop=0;
        block[0][i].mode=0;
        block[0][i].pu=1;
    }
    block[0][4].which=redred;
    block[0][5].which=flag;
    block[0][6].which=wall;
    block[0][7].which=rock;
        for(int i=8;i<12;i++)
    {
        block[0][i].lop=0;
        block[0][i].mode=1;
        block[0][i].pu=1;
    }
    block[0][8].which=you;
    block[0][9].which=ac;
    block[0][10].which=stop;
    block[0][11].which=push;
    block[0][12].mode=0;
    block[0][12].which=redred;
    block[0][12].isyou=1;
    block[0][13].mode=0;
    block[0][13].which=flag;
    block[0][13].wol=0;
    for(int i=14;i<17;i++)
    {
        block[0][i].mode=0;
        block[0][i].which=rock;
        block[0][i].pu=1;
    }
        for(int i=17;i<39;i++)
    {
        block[0][i].mode=0;
        block[0][i].which=wall;
        block[0][i].stp=1;
    }

///////////////////////////////////////////
///////////////////////////////////////////
    setxy(block[0][0],step,0);
    setxy(block[0][1],9*step,0);
    setxy(block[0][2],step,6*step);
    setxy(block[0][3],9*step,6*step);
    setxy(block[0][4],0,0);
    setxy(block[0][5],8*step,0);
    setxy(block[0][6],0,6*step);
    setxy(block[0][7],8*step,6*step);
    setxy(block[0][8],2*step,0);
    setxy(block[0][9],10*step,0);
    setxy(block[0][10],2*step,6*step);
    setxy(block[0][11],10*step,6*step);
    setxy(block[0][12],step,3*step);
    setxy(block[0][13],9*step,3*step);
    setxy(block[0][14],5*step,2*step);
    setxy(block[0][15],5*step,3*step);
    setxy(block[0][16],5*step,4*step);
    setxy(block[0][17],0,step);
    setxy(block[0][18],step,step);
    setxy(block[0][19],2*step,step);
    setxy(block[0][20],3*step,step);
    setxy(block[0][21],4*step,step);
    setxy(block[0][22],5*step,step);
    setxy(block[0][23],6*step,step);
    setxy(block[0][24],7*step,step);
    setxy(block[0][25],8*step,step);
    setxy(block[0][26],9*step,step);
    setxy(block[0][27],10*step,step);
    setxy(block[0][28],0,5*step);
    setxy(block[0][29],step,5*step);
    setxy(block[0][30],2*step,5*step);
    setxy(block[0][31],3*step,5*step);
    setxy(block[0][32],4*step,5*step);
    setxy(block[0][33],5*step,5*step);
    setxy(block[0][34],6*step,5*step);
    setxy(block[0][35],7*step,5*step);
    setxy(block[0][36],8*step,5*step);
    setxy(block[0][37],9*step,5*step);
    setxy(block[0][38],10*step,5*step);
}


////////////////////////////////////////////////
bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
             //   SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }

    return success;
}
        SDL_Texture* loadTexture( std::string path )
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if( newTexture == NULL )
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface                                            SDL_RenderPresent( gRenderer );
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}
bool loadMedia(Block block)
{
    //Loading success flag
    bool success = true;

    //Load PNG texture
    switch(block.lop)
    {
    case 0:
        switch(block.mode)
        {
        case 0:            //Clear screen
            switch(block.which)
            {
            case redred:
                gTexture = loadTexture("images/REDRED.png");
                break;
            case door:
                gTexture = loadTexture("images/DOOR.png");
                break;
            case flag:
                gTexture = loadTexture("images/FLAG.png");
                break;
            case wall:
                gTexture = loadTexture("images/WALL.png");
                break;
            case key:
                gTexture = loadTexture("images/KEY.png");
                break;
            case rock:
                gTexture = loadTexture("images/ROCK.png");
                break;
            case water:
                gTexture = loadTexture("images/WATER.png");
                break;
            case lava:
                gTexture = loadTexture("images/LAVA.png");
                break;
            case grass:
                gTexture = loadTexture("images/GRASS.png");
                break;
            }break;
        case 1:
            switch(block.which)
            {
            case you:
                gTexture = loadTexture("images/YOU.png");
                break;
            case sink:
                gTexture = loadTexture("images/SINK.png");
                break;
            case stop:
                gTexture = loadTexture("images/STOP.png");
                break;
            case push:
                gTexture = loadTexture("images/PUSH.png");
                break;
            case wa:
                gTexture = loadTexture("images/WA.png");
                break;
            case ac:
                gTexture = loadTexture("images/AC.png");
                break;
            case open:
                gTexture = loadTexture("images/OPEN.png");
                break;
            case hot:
                gTexture = loadTexture("images/HOT.png");
                break;
            case melt:
                gTexture = loadTexture("images/MELT.png");
                break;
            case shut:
                gTexture = loadTexture("images/SHUT.png");
                break;
            }break;
            case 2:
                 gTexture = loadTexture("images/IS.png");
                 break;
        }break;
    case 1:
        switch(block.mode)
        {
        case 0:
            switch(block.which)
            {
            case redred:
                gTexture = loadTexture("images/PREDRED.png");
                break;
            case door:
                gTexture = loadTexture("images/PDOOR.png");
                break;
            case flag:
                gTexture = loadTexture("images/PFLAG.png");
                break;
            case wall:
                gTexture = loadTexture("images/PWALL.png");
                break;
            case key:
                gTexture = loadTexture("images/PKEY.png");
                break;
            case rock:
                gTexture = loadTexture("images/PROCK.png");
                break;
            case water:
                gTexture = loadTexture("images/PWATER.png");
                break;
            case lava:
                gTexture = loadTexture("images/PLAVA.png");
                break;
            case grass:
                gTexture = loadTexture("images/PGRASS.png");
                break;
            }break;
        case 1:
            switch(block.which)
            {
            case you:
                gTexture = loadTexture("images/YOU.png");
                break;
            case sink:
                gTexture = loadTexture("images/SINK.png");
                break;
            case stop:
                gTexture = loadTexture("images/STOP.png");
                break;
            case push:
                gTexture = loadTexture("images/PUSH.png");
                break;
            case wa:
                gTexture = loadTexture("images/WA.png");
                break;
            case ac:
                gTexture = loadTexture("images/AC.png");
                break;
            case open:
                gTexture = loadTexture("images/OPEN.png");
                break;
            case hot:
                gTexture = loadTexture("images/HOT.png");
                break;
            case melt:
                gTexture = loadTexture("images/MELT.png");
                break;
            case shut:
                gTexture = loadTexture("images/SHUT.png");
                break;
            }break;
            case 2:
                 gTexture = loadTexture("images/IS.png");
                 break;
        }break;

    }

    if( gTexture == NULL )
    {
        printf( "Failed to load texture image!\n" );
        success = false;
    }

    return success;
}

void close()
{
    //Free loaded image
    SDL_DestroyTexture( gTexture );
    gTexture = NULL;

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

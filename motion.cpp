/*#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <cstdio>
#include <string>
#include<iostream>
#include"defineclass.h"

int step=80;
extern block;
enum direction
{
    up,
    down,
    left,
    right
};
bool judgeandmove(Block& thisobject,int direction,int stage)
{
    bool moveornot=true;
    switch(direction)
    {
    case up:
        if(thisobject.y-step<0)
        {
            moveornot=false;
            return false;
        }
        for(int i=0;i<20;i++)//"20" is the number of the objects in this stage, we can change it after defining all the stages
        {
            if(block[stage][i].y==thisobject.y-step)
            {
                if(block[stage][i].state==stop)//maybe other state will block the motion, I'll add it as we make sure all the states
                    {
                        moveornot=false;
                        return false;
                    }
                else
                {
                    if(block.pu==1)
                        moveornot=judgeandmove(&block[stage][i],up);
                }

            }
        }
        break;
    case down:
        if(thisobject.y+step>SCREEN_HEIGHT)
        {
            moveornot=false;
            return false;
        }
        for(int i=0;i<20;i++)
        {
            if(block[stage][i].y==thisobject.y+step)
            {
                if(block[stage][i].state==stop)
                    {
                        moveornot=false;
                        return false;
                    }
                else
                {
                     if(block.pu==1)
                        moveornot=judgeandmove(&block[stage][i],down);
                }

            }
        }
        break;
    case left:
        if(thisobject.x-step<0)
        {
            moveornot=false;
            return false;
        }
        for(int i=0;i<20;i++)
        {
            if(block[stage][i].x==thisobject.x-step)
            {
                if(block[stage][i].state==stop)
                {
                    moveornot=false;
                    return false;
                }
            else
                {
                     if(block.pu==1)
                        moveornot=judgeandmove(&block[stage][i],down);
                }
            }
        }
        break;
    case right:
        if(thisobject.x+step>SCREEN_WIDTH)
        {
            moveornot=false;
            return false;
        }
        for(int i=0;i<20;i++)
        {
            if(block[stage][i].x==thisobject.x+step)
            {
                if(block[stage][i].state==stop)
                {
                    moveornot=false;
                    return false;
                }
            else
                {
                     if(block.pu==1)
                        moveornot=judgeandmove(&block[stage][i],down);
                }
            }
        }
        break;
    }
    if(moveornot==true)
    {
        switch(direction)
        {
        case up:
            thisobject.y-=step;
        case down:
            thisobject.y+=step;
        case left:
            thisobject.x-=step;
        case right:
            thisobject.x+=step;
        }
    }

}
void motion(SDL_Event e)
{

static step=80;

 while( SDL_PollEvent( &e ) != 0 )
                {
                    //User presses a key
                    if( e.type == SDL_KEYDOWN )
                    {
                        //Select surfaces based on key press
                        switch( e.key.keysym.sym )
                        {
                            case SDLK_UP:
                            for(int i=0;i<20;i++)
                            {
                             if(block[stage][i].which==you&&block[stage][i].lop==1&&block[stage][i].mode==1) //need the number of stage and find all of "you" in this stage
                             {
                                 judgeandmove(objects[stage][i],up);
                             }
                            }
                            break;

                            case SDLK_DOWN:
                            for(int i=0;i<20;i++)
                            {
                             if(block[stage][i].which==you&&block[stage][i].lop==1&&block[stage][i].mode==1) //need the number of stage and find all of "you" in this stage
                             {
                                 judgeandmove(objects[stage][i],down);
                             }
                            }
                            break;

                            case SDLK_LEFT:
                            for(int i=0;i<20;i++)
                            {
                             if(block[stage][i].which==you&&block[stage][i].lop==1&&block[stage][i].mode==1) //need the number of stage and find all of "you" in this stage
                             {
                                 judgeandmove(objects[stage][i],left);
                             }
                            }
                            break;

                            case SDLK_RIGHT:
                            for(int i=0;i<20;i++)
                            {
                             if(block[stage][i].which==you&&block[stage][i].lop==1&&block[stage][i].mode==1) //need the number of stage and find all of "you" in this stage
                             {
                                 judgeandmove(block[stage][i],right);
                             }
                            }
                            break;
                        }
                    }
                }

}

*/

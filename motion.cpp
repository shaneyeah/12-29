

bool judgeandmove(Block& thisobject,int direction,int stage)
{
    bool moveornot=true;
    switch(direction)
    {
    case _up:
        if(thisobject.y-step<10)
        {
            moveornot=false;
            return false;
        }
        for(int i=0;i<39;i++)//"20" is the number of the objects in this stage, we can change it after defining all the stages
        {
            if(block[0][i].y==thisobject.y-step&&block[0][i].x==thisobject.x)
            {
                if(block[0][i].stp)//maybe other state will block the motion, I'll add it as we make sure all the states
                    {
                        moveornot=false;
                        return false;
                    }
                else if(block[0][i].snk)
                {
                    thisobject.which=20;
                    thisobject.pu=0;
                    thisobject.sht=0;
                    thisobject.opn=0;
                    thisobject.stp=0;
                    thisobject.wol=2;
                    block[0][i].which=20;
                   block[0][i].pu=0;
                    block[0][i].sht=0;
                   block[0][i].opn=0;
                    block[0][i].stp=0;
                    block[0][i].wol=2;
                }
                else
                {
                    if(block[0][i].pu==1)
                        moveornot=judgeandmove( block[0][i], _up,0);
                }

            }
        }
        break;
    case _down:
        if(thisobject.y+step>STAGE_HEIGHT[0]+10)
        {
            moveornot=false;
            return false;
        }
        for(int i=0;i<39;i++)
        {
            if(block[0][i].y==thisobject.y+step&&block[0][i].x==thisobject.x)
            {
                if(block[0][i].stp)
                    {
                        moveornot=false;
                        return false;
                    }
                else if(block[0][i].snk)
                {
                    thisobject.which=20;
                    thisobject.pu=0;
                    thisobject.sht=0;
                    thisobject.opn=0;
                    thisobject.stp=0;
                    thisobject.wol=2;
                    block[0][i].which=20;
                   block[0][i].pu=0;
                    block[0][i].sht=0;
                   block[0][i].opn=0;
                    block[0][i].stp=0;
                    block[0][i].wol=2;
                }
                else
                {
                     if(block[0][i].pu==1)
                        moveornot=judgeandmove(block[0][i],_down,0);
                }

            }
        }
        break;
    case _left:
        if(thisobject.x-step<20)
        {
            moveornot=false;
            return false;
        }
        for(int i=0;i<39;i++)
        {
            if(block[0][i].x==thisobject.x-step&&block[0][i].y==thisobject.y)
            {
                if(block[0][i].stp)
                {
                    moveornot=false;
                    return false;
                }
                else if(block[0][i].snk)
                {
                    thisobject.which=20;
                    thisobject.pu=0;
                    thisobject.sht=0;
                    thisobject.opn=0;
                    thisobject.stp=0;
                    thisobject.wol=2;
                    block[0][i].which=20;
                   block[0][i].pu=0;
                    block[0][i].sht=0;
                   block[0][i].opn=0;
                    block[0][i].stp=0;
                    block[0][i].wol=2;
                }
            else
                {
                     if(block[0][i].pu==1)
                        moveornot=judgeandmove(block[0][i],_left,0);
                }
            }
        }
        break;
    case _right:
        if(thisobject.x+step>STAGE_WIDTH[0]+20)
        {
            moveornot=false;
            return false;
        }
        for(int i=0;i<39;i++)
        {
            if(block[0][i].x==thisobject.x+step&&block[0][i].y==thisobject.y)
            {
                if(block[0][i].stp)
                {
                    moveornot=false;
                    return false;
                }
                else if(block[0][i].snk)
                {
                    thisobject.which=20;
                    thisobject.pu=0;
                    thisobject.sht=0;
                    thisobject.opn=0;
                    thisobject.stp=0;
                    thisobject.wol=2;
                    block[0][i].which=20;
                   block[0][i].pu=0;
                    block[0][i].sht=0;
                   block[0][i].opn=0;
                    block[0][i].stp=0;
                    block[0][i].wol=2;
                }
            else
                {
                     if(block[0][i].pu==1)
                        moveornot=judgeandmove(block[0][i],_right,0);
                }
            }
        }
        break;
    }
    if(moveornot==true)
    {
        switch(direction)
        {
        case _up:
            thisobject.y-=step;
            break;
        case _down:
            thisobject.y+=step;
            break;
        case _left:
            thisobject.x-=step;
            break;
        case _right:
            thisobject.x+=step;
            break;
        }
    }
}
bool  motion ()
{
    setstage1();
 if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
    SDL_Rect block_viewpoint[39];
for(int i=0;i<39;i++)
{
    loadMedia(block[0][i]);
    block_viewpoint[i].x=block[0][i].x;
    block_viewpoint[i].y=block[0][i].y;
    block_viewpoint[i].w=step;
    block_viewpoint[i].h=step;
    SDL_RenderSetViewport( gRenderer, &block_viewpoint[i] );
    SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
    SDL_DestroyTexture(gTexture);
    gTexture=NULL;
}
SDL_RenderPresent( gRenderer );
while( !quit )
            {
            //Apply the image
          while( SDL_PollEvent( &e ) != 0 )
                {
                    //User presses a key
                    if( e.type == SDL_KEYDOWN )
                    {
                        //Select surfaces based on key press
                        switch( e.key.keysym.sym )
                        {

                            case SDLK_UP:
                            SDL_SetRenderDrawColor(gRenderer,0x00,0x00,0x00,0xFF);
                            SDL_RenderClear( gRenderer );
                            for(int i=0;i<39;i++)
                            {
                             if(block[0][i].isyou) //need the number of stage and find all of "you" in this stage
                             {
                                 judgeandmove(block[0][i],_up,0);
                             }
                            }
                            for(int i=0;i<39;i++)
                            {
                                loadMedia(block[0][i]);
                                block_viewpoint[i].x=block[0][i].x;
                                block_viewpoint[i].y=block[0][i].y;
                                block_viewpoint[i].w=step;
                                block_viewpoint[i].h=step;

                                SDL_RenderSetViewport( gRenderer, &block_viewpoint[i] );
                                SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
                                SDL_DestroyTexture(gTexture);
                                gTexture=NULL;
                            }
                                                    SDL_RenderPresent( gRenderer );
                            break;

                            case SDLK_DOWN:
                                SDL_SetRenderDrawColor(gRenderer,0x00,0x00,0x00,0xFF);
                                SDL_RenderClear( gRenderer );
                            for(int i=0;i<39;i++)
                            {
                             if(block[0][i].isyou) //need the number of stage and find all of "you" in this stage
                             {
                                 judgeandmove(block[0][i],_down,0);
                             }
                            }
                            for(int i=0;i<39;i++)
                            {
                                loadMedia(block[0][i]);
                                block_viewpoint[i].x=block[0][i].x;
                                block_viewpoint[i].y=block[0][i].y;
                                block_viewpoint[i].w=step;
                                block_viewpoint[i].h=step;
                                SDL_RenderSetViewport( gRenderer, &block_viewpoint[i] );
                                SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
                                SDL_DestroyTexture(gTexture);
                                gTexture=NULL;
                            }
                            break;

                            case SDLK_LEFT:
                                SDL_SetRenderDrawColor(gRenderer,0x00,0x00,0x00,0xFF);
                                SDL_RenderClear( gRenderer );
                            for(int i=0;i<39;i++)
                            {
                             if(block[0][i].isyou) //need the number of stage and find all of "you" in this stage
                             {
                                 judgeandmove(block[0][i],_left,0);
                             }
                            }
                            for(int i=0;i<39;i++)
                            {
                                loadMedia(block[0][i]);
                                block_viewpoint[i].x=block[0][i].x;
                                block_viewpoint[i].y=block[0][i].y;
                                block_viewpoint[i].w=step;
                                block_viewpoint[i].h=step;
                                SDL_RenderSetViewport( gRenderer, &block_viewpoint[i] );
                                SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
                                SDL_DestroyTexture(gTexture);
                                gTexture=NULL;
                            }
                            break;

                            case SDLK_RIGHT:
                                SDL_SetRenderDrawColor(gRenderer,0x00,0x00,0x00,0xFF);
                                SDL_RenderClear( gRenderer );
                            for(int i=0;i<39;i++)
                            {
                             if(block[0][i].isyou) //need the number of stage and find all of "you" in this stage
                             {
                                 judgeandmove(block[0][i],_right,0);
                             }
                            }
                            for(int i=0;i<39;i++) //need the number of stage and find all of "you" in this stage
                             {
                                loadMedia(block[0][i]);
                                block_viewpoint[i].x=block[0][i].x;
                                block_viewpoint[i].y=block[0][i].y;
                                block_viewpoint[i].w=step;
                                block_viewpoint[i].h=step;
                                SDL_RenderSetViewport( gRenderer, &block_viewpoint[i] );
                                SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
                                SDL_DestroyTexture(gTexture);
                                gTexture=NULL;
                            }
                            break;


                        }
                        SDL_RenderPresent( gRenderer );

                    }
                }
                }

    }
        close();
}

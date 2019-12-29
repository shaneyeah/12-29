/*#include"defineclass.h"
extern int step=5;

void setxy(Block &a,int x,int y)
{
    a.x=x;
    a.y=y;
}

void setstage1()
{
    extern block ;
    for(int i=0;i<39;i++)
    {
        block[0][i].lop=1;
        block[0][i].opn=0;
        block[0][i].pu=0;
        block[0][i].sht=0;
        block[0][i].snk=0;
        block[0][i].stp=0;
        block[0][i].wol=2;
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
    block[0][9].which=win;
    block[0][10].which=stop;
    block[0][11].which=push;
    block[0][12].mode=0;
    block[0][12].which=redred;
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
    setxy(&block[0][0],step,0)
    setxy(&block[0][1],9*step,0)
    setxy(&block[0][2],step,6*step)
    setxy(&block[0][3],9*step,6*step)
    setxy(&block[0][4],0,0)static step=80;
    setxy(&block[0][5],8*step,0)
    setxy(&block[0][6],0,6*step)
    setxy(&block[0][7],8*step,6*step)
    setxy(&block[0][8],2*step,0)
    setxy(&block[0][9],10*step,0)
    setxy(&block[0][10],2*step,6*step)
    setxy(&block[0][11],10*step,6*step)
    setxy(&block[0][12],step,3*step)
    setxy(&block[0][13],9*step,3*step)
    setxy(&block[0][14],5*step,2*step)
    setxy(&block[0][15],5*step,3*step)
    setxy(&block[0][16],5*step,4*step)
    setxy(&block[0][17],0,step)
    setxy(&block[0][18],step,step)
    setxy(&block[0][19],2*step,step)
    setxy(&block[0][20],3*step,step)
    setxy(&block[0][21],4*step,step)
    setxy(&block[0][22],5*step,step)
    setxy(&block[0][23],6*step,step)
    setxy(&block[0][24],7*step,step)
    setxy(&block[0][25],8*step,step)
    setxy(&block[0][26],9*step,step)
    setxy(&block[0][27],10*step,step)
    setxy(&block[0][28],0,5*step)
    setxy(&block[0][29],step,5*step)
    setxy(&block[0][30],2*step,5*step)
    setxy(&block[0][31],3*step,5*step)
    setxy(&block[0][32],4*step,5*step)
    setxy(&block[0][33],5*step,5*step)
    setxy(&block[0][34],6*step,5*step)
    setxy(&block[0][35],7*step,5*step)
    setxy(&block[0][36],8*step,5*step)
    setxy(&block[0][37],9*step,5*step)
    setxy(&block[0][38],10*step,5*step)
}
*/



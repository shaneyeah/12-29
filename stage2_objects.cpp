void setxy(Block &a,int x,int y)
{
    a.x=x;
    a.y=y;
}
void setstage2()
{
    extern block ;
    for(int i=0;i<39;i++)
    {
        block[1][i].lop=1;
        block[1][i].pu=0;
        block[1][i].snk=0;
        block[1][i].stp=0;
        block[1][i].wol=2;
        block[1][i].isyou=0;
    }
    for(int i=0;i<3;i++)
    {
        block[1][i].lop=0;
        block[1][i].mode=2;
        block[1][i].which=is;
        block[1][i].pu=1;
    }
    for(int i=3;i<6;i++)
    {
        block[1][i].lop=0;
        block[1][i].mode=0;
        block[1][i].pu=1;
    }
    for(int i=6;i<9;i++)
    {
        block[1][i].lop=0;
        block[1][i].mode=1;
        block[1][i].pu=1;
    }
        block[1][3].which=redred;
        block[1][4].which=flag;
        block[1][5].which=wall;
        block[1][6].which=you;
        block[1][7].which=ac;
        block[1][8].which=stop;
        block[1][9].lop=1;
        block[1][9].mode=0;
        block[1][9].which=redred;
        block[1][9].isyou=1;
        block[1][10].lop=1;
        block[1][10].mode=0;
        block[1][10].which=flag;
        block[1][10].wol=0;
    for(int i=9;i<29;i++)
    {
        block[1][i].lop=1;
        block[1][i].mode=0;
        block[1][i].which=wall;
        block[1][i].stp=1;
    }
////////////////////////////////////////////////////////
    setxy(&block[1][0],5*step,2*step)
    setxy(&block[1][1],5*step,5*step)
    setxy(&block[1][2],14*step,4*step)
    setxy(&block[1][3],4*step,2*step)
    setxy(&block[1][4],4*step,5*step)
    setxy(&block[1][5],14*step,3*step)
    setxy(&block[1][6],6*step,2*step)
    setxy(&block[1][7],6*step,5*step)
    setxy(&block[1][8],14*step,5*step)
    setxy(&block[1][9],step,4*step)
    setxy(&block[1][10],11*step,4*step)
    setxy(&block[1][11],9*step,2*step)
    setxy(&block[1][12],10*step,2*step)
    setxy(&block[1][13],11*step,2*step)
    setxy(&block[1][14],12*step,2*step)
    setxy(&block[1][15],13*step,2*step)
    setxy(&block[1][16],14*step,2*step)
    setxy(&block[1][17],9*step,3*step)
    setxy(&block[1][18],13*step,3*step)
    setxy(&block[1][19],9*step,4*step)
    setxy(&block[1][20],13*step,4*step)
    setxy(&block[1][21],9*step,5*step)
    setxy(&block[1][22],13*step,5*step)
    setxy(&block[1][23],9*step,6*step)
    setxy(&block[1][24],10*step,6*step)
    setxy(&block[1][25],11*step,6*step)
    setxy(&block[1][26],12*step,6*step)
    setxy(&block[1][27],13*step,6*step)
    setxy(&block[1][28],14,6*step)
}

//
// Created by sarra on 12/11/2024.
//
int gagner(int plateaujeu[17][17],int N) {
    int gagner=0;
    if(N==2) {
        if(plateaujeu[0][0]==2 || plateaujeu[0][2]==2 || plateaujeu[0][4]==2 || plateaujeu[0][6]==2 || plateaujeu[0][8]==2 || plateaujeu[0][10]==2 || plateaujeu[0][12]==2|| plateaujeu[0][14]==2 || plateaujeu[0][16]==2) {
            gagner=1;
        }else if(plateaujeu[16][0]==1 || plateaujeu[16][2]==1 || plateaujeu[16][4]==1|| plateaujeu[16][6]==1 || plateaujeu[16][8]==1|| plateaujeu[16][10]==1|| plateaujeu[16][12]==1|| plateaujeu[16][14]==1|| plateaujeu[16][16]==1) {
            gagner=1;
        }
    }else if(N==4) {
        if(plateaujeu[0][0]==2 || plateaujeu[0][2]==2 || plateaujeu[0][4]==2 || plateaujeu[0][6]==2 || plateaujeu[0][8]==2 || plateaujeu[0][10]==2 || plateaujeu[0][12]==2|| plateaujeu[0][14]==2 || plateaujeu[0][16]==2) {
            gagner=1;
        }else if(plateaujeu[16][0]==3 || plateaujeu[16][2]==3 || plateaujeu[16][4]==3|| plateaujeu[16][6]==3 || plateaujeu[16][8]==3|| plateaujeu[16][10]==3 || plateaujeu[16][12]==3 || plateaujeu[16][14]==3 || plateaujeu[16][16]==3) {
            gagner=1;
        }else if (plateaujeu[0][0]==4 || plateaujeu[2][0]==4 || plateaujeu[4][0]==4 || plateaujeu[6][0]==4 || plateaujeu[8][0]==4 || plateaujeu[10][0]==4 || plateaujeu[0][12]==4 || plateaujeu[0][14]==4 || plateaujeu[0][16]==4) {
            gagner=1;
        }else if(plateaujeu[0][16]==2 || plateaujeu[2][16]==2 || plateaujeu[4][16]==2 || plateaujeu[6][16]==2 || plateaujeu[8][16]==2 || plateaujeu[10][16]==2 || plateaujeu[12][16]==2 || plateaujeu[14][16]==2 || plateaujeu[16][16]==2) {
            gagner=1;
        }
    }
        return gagner;
}
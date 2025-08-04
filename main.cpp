#include <iostream>
#include<conio.h>//for _kbhit() and _getch()
#include<windows.h>// for sleep
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;
const int width=20;
const int height=20;
char grid[height][width];
int playerX=width/2;
int bulletX=-1;
int bulletY=-1;
int score =0,level=1,speed=150;
const int enemyCount=5;
vector<int>
enemyX(enemyCount);
vector<bool>
enemyAlive(enemyCount,true);
int enemyY=1;
bool enemyRight=true;

void clearGrid(){
for(int y=0;y<height;y++)
for(int x=0;x<width;x++)
    grid[y][x]=' ';

}
void draw(){
system("cls");
cout<<"Score: "<<score<<"|Level:"<<level<<endl;
for(int y=0;y<height;y++){
    for(int x=0;x<width;x++){
      cout<<grid[y][x];
    }
    cout<<endl;
}

}
void moveEnemies(){
for(int i=0;i<enemyCount;i++){
  if(!enemyAlive[i])continue;
  if(enemyRight&&enemyX[i]>=width-1){
    enemyRight=false;
    enemyY++;break;

  }
  else if(!enemyRight&&enemyX[i]<=0){
    enemyRight=true;
    enemyY++;break;
  }
}
for(int i=0;i<enemyCount;i++){
    if(!enemyAlive[i])continue;
    enemyX[i]+=(enemyRight? 1:-1);
}
}


void update(){
clearGrid();


//Move bullet
if(bulletY>=0){
    grid[bulletY][bulletX]='O';
    bulletY--;
    for(int i=0;i<enemyCount;i++){
        if(enemyAlive[i]&&bulletX==enemyX[i]&&bulletY==enemyY){
            enemyAlive[i]=false;
            bulletY=-1;
            score++;
        }
    }
}//draw enemies
for(int i=0;i<enemyCount;i++){
    if(enemyAlive[i])
        grid[enemyY][enemyX[i]]='W';
}

//draw player
grid[height-1][playerX]='^';
}
void input(){
if(_kbhit()){
    char ch =_getch();
    if (ch=='a'&&playerX>0)
        playerX--;
    if(ch=='d'&&playerX<width-1)playerX++;
    if(ch==' '&&bulletY==-1){
        bulletX=playerX;
        bulletY=height-2;
    }
}
}
bool allEnemiesDead(){for(bool alive:enemyAlive)
if(alive)return false;
return true;}
void resetEnemies(){for(int i=0;i<enemyCount;i++){enemyX[i]=rand()%(width-2)+1;
enemyAlive[i]=true;}
enemyY=1;
enemyRight=true;}


int main()
{srand(time(0));
resetEnemies();
    while(true){
        input();
        moveEnemies();
        update();
        draw();
        Sleep(speed);
   if(allEnemiesDead()){level++;
   if(level>3){cout<<"$You win!     Final Score: "<<score<<endl;break;}

   resetEnemies();
   speed-=30;//increase difficulty
   }
   if(enemyY>=height-2){cout<<"!Game0ver! Final Score: "<<score<<endl;break;
   }
    }
    return 0;
}

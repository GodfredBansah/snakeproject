#include <iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameOver;
const int width=20;
const int height=20;
int x,y,obstacleX,obstacleY;
int score;
int speed=100;
char car='A';

 void Setup(){
 gameOver=false;
 x=width/2;
 y=height-1;
 obstacleX=rand()%width;
 obstacleY=0;



 }
 void Draw(){
 system("cls");
 for (int i=0;i<width+2;i++)
    cout<<"H";
    cout<<endl;

 for (int i=0;i<height;i++){
    cout<<"H";
    for(int j=0;j<width;j++){
        if (j==x&&i==y)
            cout<<car;
        else if(j==obstacleX&&i==obstacleY)
            cout<<"OO";
        else cout<<" ";

    }
    cout<<"H"<<endl;
 }
 for(int i=0;i<width+2;i++)
    cout<<"H";
 cout<<"\nScore:"<<score<<endl;


 }
 void Input(){
 if(_kbhit()){
    switch(_getch()){
    case 'a':if(x>0)x--;break;
    case 'd':if(x<width-1)x++;
    break;
    case 'x':gameOver=true;break;
    }
 }
 }
 void Logic(){
 obstacleY++;
 if (obstacleY>height){
    obstacleY=0;
    obstacleX=rand()%width;
    score++;
    if (speed>20)speed-=2;
 }
 if (obstacleX==x&&obstacleY==y){
    gameOver=true;
 }
 }
 int main(){
 Setup();
 while(!gameOver){
    Draw();
    Input();
    Logic();
    Sleep(speed);
 }cout<<"\nGame Over!Final Score:"<<score<<endl;
 system("pause");
 return 0;
 }




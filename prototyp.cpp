#include <ncurses.h> 
#include <thread> 
#include <unistd.h> 
#include <iostream> 
#include <mutex> 

using namespace std;

mutex mu; 

bool wykonuj = true;

char stop;

int x, y, z;


void watek_1() 
{
 	
 	while(wykonuj)
 	{
        y = 0;
        mvaddch(y, x, 'A');
        x += 1;
 		     usleep(100000);
 		     refresh();
 	}
} 
void watek_2() 
{
 	
 	while(wykonuj)
 	{
        y = 1;
        mvaddch(y, z, 'B');
        mvaddch(y, z, ' ');
        z += 1;
 		     usleep(200000);
 		     refresh();
 	}
} 




int main(int argc, char* argv[]) 
{ 	 	

 	initscr();
  noecho();

 	thread w1(watek_1);
 	thread w2(watek_2);
  
  stop = getch();
  if(stop == 'q') wykonuj = false;
 	w1.join();
 	w2.join();
 	getch();
 	endwin(); 
}

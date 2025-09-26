//charan_0

#include <iostream>
#include <vector>

#include "gui.hpp"
#include "patterns.hpp"

using namespace std;

typedef long long ll; 
const char nl='\n';
const char spc=' ';

int render=72; //add extra padding

vector <vector<bool>> realm(render,vector<bool>(render,0)); 
vector <vector<bool>> present_state(realm);

//draw the map

//those nasty neighbours
int neigbourchecker(int r,int c){
	int count=0;

	for(int i=c-1;i<c+2;i++){
		if(present_state[r-1][i])count++;
		if(present_state[r+1][i])count++;
	}
	if(present_state[r][c+1])count++;
	if(present_state[r][c-1])count++;

	return count;}


	//the real_deal
	void life_emulation(){
		//death and reproduction

		for(int i=1;i<render-1;i++){
			for(int j=1;j<render-1;j++){

				int count=neigbourchecker(i,j);

				if(( present_state[i][j]&&count<2 ) || ( present_state[i][j]&&count>3 )){
					//death
					realm[i][j]=0;
				}
				else if(present_state[i][j] && (count=2||count==3)){
					//stay alive
					realm[i][j]=1;
				}
				else if(!(present_state[i][j]) && count==3){
					//the birth of the savior
					realm[i][j]=1;
				}
				else {
					//stay dead
					realm[i][j]=0;
				}
			}
		}
present_state=realm;
	}

int main(){

//test

	// Glider pattern - this will move across the screen
	// realm[10][10]=1;
	// realm[11][11]=1;
	// realm[11][12]=1;
	// realm[10][12]=1;
	// realm[9][12]=1;

	// Alternative: Blinker pattern (uncomment to try)
	// realm[10][10]=1;
	// realm[10][11]=1;
	// realm[10][12]=1;
 											
		initpattern(realm);
	present_state=realm;


initGUI(render,render, "Conway's Game of Life");

    while (!WindowShouldClose()) {
        life_emulation();      // update game
        draw_board(realm);     // draw GUI
    }

    closeGUI();

	return 0;}


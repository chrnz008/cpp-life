//charan_0

#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

typedef long long ll; 
const char nl='\n';
const char spc=' ';

int render=52; //add extra padding

vector <vector<bool>> realm(render,vector<bool>(render,0)); 
vector <vector<bool>> present_state(realm);

//draw the map
void draw_board(){

	for(int i=1;i<render-1;i++){
		for(int j=1;j<render-1;j++){
			if(realm[i][j])cout<<"O";
			else cout<<" ";
		}
		cout<<nl;
	}
}

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
	realm[10][10]=1;
	realm[11][11]=1;
	realm[11][12]=1;
	realm[10][12]=1;
	realm[9][12]=1;

	// Alternative: Blinker pattern (uncomment to try)
	// realm[10][10]=1;
	// realm[10][11]=1;
	// realm[10][12]=1;
 											
	present_state=realm;


//hides your terminal cursor
 cout << "\033[?25l"; // Hide cursor"]"

	while(1){

		system("cls");//on windows
					  //system("clear"); //on linux and macos
		draw_board();
		Sleep(100);

		life_emulation();
	}




	// int count=neigbourchecker(2,2);
	// cout<<count;

	return 0;}


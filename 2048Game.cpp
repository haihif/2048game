/*
	2048 GAME 
	
	Wirten by Nguyen Huy Hai
	
	https://github.com/haihif

*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <time.h>

int value[6][6]; 
int score = 0;
int rank[10];
char name[10];

int rd(int maxn){ //random 1 to maxn
	
	int r =1 + rand() % (maxn);
	return r;
}

void init(){
	
	score = 0;
		
	for(int i=0; i<6; i++){
		for(int j=0; j<6; j++){
			value[i][j] = 0;
			if (i == 0 || i == 5 || j == 0 || j == 5) value[i][j] = 1;
			
		}
	}
		
	int ri,rj;
	ri = rd(4);rj = rd(4);
	value[ri][rj] = 2;
	ri = rd(4);rj = rd(4);
	value[rj][ri] = 2; // creat 2 randomize values = 2;
}

void draw(){
	system("cls"); 
	char c = '_';
	for(int i=1; i<=4; i++){
		for(int j=1; j<=4; j++){
			if (value[i][j] == 0) 
				printf(" %5c",c);
			else 
				printf(" %5d",value[i][j]);
		}
		printf("\n");
		printf("\n");
	}
	printf("YOUR SCORE:     %d\n\n",score);
	printf("*Use Up/ Down/ Right/ Left button to play!\n");	
	printf("*Press E to exit!\n");
	
}

void mainMenu(){
	system("cls"); 
	printf("00000000000000000000000000000000000000\n");
	printf("00                                  00\n");
	printf("00          1. CONTINUE             00\n");
	printf("00          2. NEW GAME             00\n");
	printf("00          3. GUIDE                00\n");
	printf("00          4. ABOUT US             00\n");
	printf("00                                  00\n");
	printf("00000000000000000000000000000000000000\n");
}

void readBoard(){
	FILE *boardGame;
	boardGame = fopen("boardGame.txt","r");
	
	for(int i=1; i<=4; i++){
		for(int j=1; j<=4; j++){
			fscanf(boardGame,"%d",&value[i][j]);
		}
	}
	fscanf(boardGame,"%d",&score);
	fclose(boardGame);
}

void saveGame(){
	FILE *boardGame;
	boardGame = fopen("boardGame.txt","w");
	
	for(int i=1; i<=4; i++){
		for(int j=1; j<=4; j++){
			fprintf(boardGame,"%d ",value[i][j]);
		}
		fprintf(boardGame,"\n");
	}
	fprintf(boardGame,"%d",score);
	fclose(boardGame);
}

void updateScore(int x){
	score += x;
}

int keyPress(){
	char c = getch();
	while(c == -32) 
		c=getch();
	
	return c;
}

void addLeft(){
	int ptrValue[6][6];
	int ptr;
	
	for(int i=0; i<6; i++)
		for(int j=0; j<6; j++){
			ptrValue[i][j] = 0;
		}
	
	for(int i=1; i<=4; i++){
		ptr = 1;
		for (int j=1; j<=4; j++){
			if (value[i][j] != 0) 
				{
					ptrValue[i][ptr] = value[i][j];
					ptr++;
				}
		}
	}
	
	for(int i=1; i<=4; i++){
		for(int j=1; j<=3; j++){
			if (ptrValue[i][j] == ptrValue[i][j+1]){
				ptrValue[i][j] *= 2;
				score++;
				ptrValue[i][j+1] = 0;
				if (j<=2) {
					for(int k=j+1; k<=3; k++){
						ptrValue[i][k] = ptrValue[i][k+1];
						ptrValue[i][k+1] = 0;						
					}
				}
			}
		}
	}
	
	for(int i=1; i<=4; i++)
		for(int j=1; j<=4; j++){
			value[i][j] = ptrValue[i][j];
		}
		
	int addp = 0;
	
	addp = rd(4);
	if (value[addp][4] == 0) value[addp][4] = 2;
	addp = rd(4);
	if (value[addp][4] == 0) value[addp][4] = 2;
	
	
}
void addUp() {
	int ptrValue[6][6];
		int ptr;
		
		for(int i=0; i<6; i++)
			for(int j=0; j<6; j++){
				ptrValue[i][j] = 0;
			}
		
		for(int j=1; j<=4; j++){
			ptr = 1;
			for (int i=1; i<=4; i++){
				if (value[i][j] != 0) 
					{
						ptrValue[ptr][j] = value[i][j];
						ptr++;
					}
			}
		}
		
		for(int j=1; j<=4; j++){
			for(int i=1; i<=3; i++){
				if (ptrValue[i][j] == ptrValue[i+1][j]){
					ptrValue[i][j] *= 2;
					score++;
					ptrValue[i+1][j] = 0;
					if (i<=2) {
						for(int k=i+1; k<=3; k++){
							ptrValue[k][j] = ptrValue[k+1][j];
							ptrValue[k+1][j] = 0;						
						}
					}
				}
			}
		}
		
		for(int i=1; i<=4; i++)
			for(int j=1; j<=4; j++){
				value[i][j] = ptrValue[i][j];
			}
			
		int addp = 0;
		
		addp = rd(4);
		if (value[4][addp] == 0) value[4][addp] = 2;
		addp = rd(4);
		if (value[4][addp] == 0) value[4][addp] = 2;
	
}
void addRight() {
	int ptrValue[6][6];
	int ptr;
	
	for(int i=0; i<6; i++)
		for(int j=0; j<6; j++){
			ptrValue[i][j] = 0;
		}
	
	for(int i=1; i<=4; i++){
		ptr = 4;
		for (int j=4; j>=1; j--){
			if (value[i][j] != 0) 
				{
					ptrValue[i][ptr] = value[i][j];
					ptr--;
				}
		}
	}
	
	for(int i=1; i<=4; i++){
		for(int j=4; j>=2; j--){
			if (ptrValue[i][j] == ptrValue[i][j-1]){
				ptrValue[i][j] *= 2;
				score++;
				ptrValue[i][j-1] = 0;
				if (j>=3) {
					for(int k=j-1; k>=2; k--){
						ptrValue[i][k] = ptrValue[i][k-1];
						ptrValue[i][k-1] = 0;						
					}
				}
			}
		}
	}
	
	for(int i=1; i<=4; i++)
		for(int j=1; j<=4; j++){
			value[i][j] = ptrValue[i][j];
		}
		
	int addp = 0;
	
	addp = rd(4);
	if (value[addp][1] == 0) value[addp][1] = 2;
	addp = rd(4);
	if (value[addp][1] == 0) value[addp][1] = 2;
}
void addDown() {
	int ptrValue[6][6];
	int ptr;
	
	for(int i=0; i<6; i++)
		for(int j=0; j<6; j++){
			ptrValue[i][j] = 0;
		}
	
	for(int j=1; j<=4; j++){
		ptr = 4;
		for (int i=4; i>=1; i--){
			if (value[i][j] != 0) 
				{
					ptrValue[ptr][j] = value[i][j];
					ptr--;
				}
		}
	}
	
	for(int j=1; j<=4; j++){
		for(int i=4; i>=2; i--){
			if (ptrValue[i][j] == ptrValue[i-1][j]){
				ptrValue[i][j] *= 2;
				score++;
				ptrValue[i-1][j] = 0;
				if (i>=3) {
					for(int k=i-1; k>=2; k--){
						ptrValue[k][j] = ptrValue[k-1][j];
						ptrValue[k-1][j] = 0;						
					}
				}
			}
		}
	}
	
	for(int i=1; i<=4; i++)
		for(int j=1; j<=4; j++){
			value[i][j] = ptrValue[i][j];
		}
		
	int addp = 0;
	
	addp = rd(4);
	if (value[1][addp] == 0) value[1][addp] = 2;
	addp = rd(4);
	if (value[1][addp] == 0) value[1][addp] = 2;
}

bool gameOver() {
	bool sameValue, exist0;
	sameValue = false;
	exist0 = false;
	for(int i=1; i<=4; i++)
		for(int j=1; j<=4; j++){
			if(value[i][j] == value[i][j-1] || value[i][j] == value[i][j+1] || value[i][j] == value[i-1][j] || value[i][j] == value[i+1][j])		
			{	
				sameValue = true;
			}
			if (value[i][j] == 0) exist0 = true; 
		}
	if (exist0) return false;
	
	else if (sameValue) return false;
	else return true;
}

bool gameWin(){
	bool w = false;
	
	for(int i=1; i<=4; i++)
		for(int j=1; j<=4; j++){
			if (value[i][j] == 8192) {
				w = true;
				break;
			}
		}
	return w;
}

void loopGame(){
	int k,k1;
	while (gameOver() != true) {
		RELOAD: draw();
		k = keyPress();
			switch(k) {
				case 75:
					addLeft();
					break;
				case 72:
					addUp();
					break;
				case 77:
					addRight();
					break;
				case 80:
					addDown();
					break;
				case 101:
					system("cls");
					printf("\n     DO YOU WANT TO SAVE ?\n");
					printf("\n");
					printf("     (1)Yes   (2)No   (3)Back ");
					k1 = keyPress();
					switch(k1){
						case '1':
							saveGame();
							exit(0);
							break;
						case '2':
							exit(0);
							break;
						case '3':
							goto RELOAD;
							break;
					}
			}
		if (gameWin()) break;
	}
	if (gameOver()) {
		 
		printf(" 0000     0    0     0   0000         0000    0     0   0000    00000\n");
		printf("0        0 0   00   00  0    0       0    0   0     0  0    0   0    0\n");
		printf("0   00  0   0  0 0 0 0  000000      00    00   0   0   000000   0 000 \n");
		printf("0    0  00000  0  0  0  0            0    0     000    0        0    0 \n");
		printf(" 00000  0   0  0     0   0000         0000       0      0000    0     0 \n");
		
		getchar();
		
		printf("\n\n       (1) BACK      (2) NEW GAME     (E) EXIT GAME");
			switch(keyPress()) {
				case '1':
					mainMenu();
					break;
				case '2':
					init();
					loopGame();
					break;
				case '3':
					exit(0);
					break;
				default: 
					system("cls");
					printf("\n");
					printf("        INVALID COMMAND !!!");
					printf("\n\n\n\n");
					printf("       (1) BACK      (2) NEW GAME     (E) EXIT GAME");
					switch(keyPress()) {
						case '1':
							mainMenu();
							break;
						case '2':
							init();
							loopGame();
							break;
						case '3':
							exit(0);
							break;
					}	
			}	
	}
}

void start(){
	mainMenu();
	switch(keyPress()) {
		case '1':
			init();
			readBoard();
			loopGame();
			break;
		case '2':
			init();
			loopGame();
			break;
		case '3':
			system("cls");
			printf("\n");
			printf("\n     *Use up/down/right/left button to play!\n");	
			printf("\n\n");
			printf("\n\n\n\n");
			printf("       (1) BACK      (2) NEW GAME     (E) EXIT GAME");
			switch(keyPress()) {
				case '1':
					mainMenu();
					break;
				case '2':
					init();
					loopGame();
					break;
				case '3':
					exit(0);
					break;
				default: 
					system("cls");
					printf("\n");
					printf("        INVALID COMMAND !!!");
					printf("\n\n\n\n");
					printf("       (1) BACK      (2) NEW GAME     (E) EXIT GAME");
					switch(keyPress()) {
						case '1':
							mainMenu();
							break;
						case '2':
							init();
							loopGame();
							break;
						case '3':
							exit(0);
							break;
					}	
			}
		case '4':
			printf("\n");
			printf("        CODE BY HAI.NH ");
			printf("\n\n\n\n");
			printf("       (1) BACK      (2) NEW GAME     (E) EXIT GAME");
			switch(keyPress()) {
				case '1':
					mainMenu();
					break;
				case '2':
					init();
					loopGame();
					break;
				case '3':
					exit(0);
					break;
				default: 
					system("cls");
					printf("\n");
					printf("        INVALID COMMAND !!!");
					printf("\n\n\n\n");
					printf("       (1) BACK      (2) NEW GAME     (E) EXIT GAME");
					switch(keyPress()) {
						case '1':
							mainMenu();
							break;
						case '2':
							init();
							loopGame();
							break;
						case '3':
							exit(0);
							break;
					}	
			}
			break;
		case 'e':
			exit(0);
			break;
		
		default: 
			system("cls");
			printf("\n");
			printf("        INVALID COMMAND !!!");
			printf("\n\n\n\n");
			printf("       (1) BACK      (2) NEW GAME     (E) EXIT GAME");
			switch(keyPress()) {
				case '1':
					mainMenu();
					break;
				case '2':
					init();
					loopGame();
					break;
				case '3':
					exit(0);
					break;
			}	
	}
	
}

int main() {
	
	srand(time(NULL));
	
	start();

	return 0;
}


/*
*Enter : 13
*ESC: 27
*Tab: 9
*Up: 72
*Down: 80
*Left: 75
*Right: 77
*Space: 32
*/

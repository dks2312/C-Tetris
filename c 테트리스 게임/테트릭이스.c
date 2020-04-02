#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<windows.h>

#define frame_X 30*2	//틀의 시작 지점 
#define frame_Y 7

#define hold_X frame_X-(6+2)*2

#define next_X frame_X+(3 )*2

#define COL                   GetStdHandle(STD_OUTPUT_HANDLE)        // 콘솔창의 핸들정보 받기

#define BLACK                SetConsoleTextAttribute(COL, 0x0000);        // 검정색 0
#define DARK_BLUE         SetConsoleTextAttribute(COL, 0x0001);        // 파란색 1
#define GREEN                SetConsoleTextAttribute(COL, 0x0002);        // 녹색 2
#define BLUE_GREEN        SetConsoleTextAttribute(COL, 0x0003);        // 청녹색 3
#define BLOOD               SetConsoleTextAttribute(COL, 0x0004);        // 검붉은색 4
#define PURPLE               SetConsoleTextAttribute(COL, 0x0005);        // 보라색 5
#define GOLD                 SetConsoleTextAttribute(COL, 0x0006);        // 금색 6
#define ORIGINAL            SetConsoleTextAttribute(COL, 0x0007);        // 밝은 회색 7 (ORIGINAL CONSOLE COLOR)
#define GRAY                 SetConsoleTextAttribute(COL, 0x0008);        // 회색 8
#define BLUE                  SetConsoleTextAttribute(COL, 0x0009);        // 파란색 9
#define HIGH_GREEN       SetConsoleTextAttribute(COL, 0x000a);        // 연두색 10
#define SKY_BLUE           SetConsoleTextAttribute(COL, 0x000b);        // 하늘색 11
#define RED                   SetConsoleTextAttribute(COL, 0x000c);        // 빨간색 12
#define PLUM                SetConsoleTextAttribute(COL, 0x000d);        // 자주색 13
#define YELLOW             SetConsoleTextAttribute(COL, 0x000e);        // 노란색 14
#define WHITE                SetConsoleTextAttribute(COL, 0x000f);        // 흰색 15

void textcolor(int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x,int y){
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}

int block[11][4][4][4]={	//미노	
{{{0, 0, 0, 0},{1, 1, 1, 1},{0, 0, 0, 0},{0, 0, 0, 0}},	//0 번 i형 블록
 {{0, 0, 1, 0},{0, 0, 1, 0},{0, 0, 1, 0},{0, 0, 1, 0}},
 {{0, 0, 0, 0},{0, 0, 0, 0},{1, 1, 1, 1},{0, 0, 0, 0}},
 {{0, 1, 0, 0},{0, 1, 0, 0},{0, 1, 0, 0},{0, 1, 0, 0}}},
 
{{{0, 0, 0, 0},{0, 1, 1, 0},{0, 1, 1, 0},{0, 0, 0, 0}}, //1 번 o형 블록
 {{0, 0, 0, 0},{0, 1, 1, 0},{0, 1, 1, 0},{0, 0, 0, 0}},
 {{0, 0, 0, 0},{0, 1, 1, 0},{0, 1, 1, 0},{0, 0, 0, 0}},
 {{0, 0, 0, 0},{0, 1, 1, 0},{0, 1, 1, 0},{0, 0, 0, 0}}},
 
{{{0, 0, 0, 0},{0, 1, 0, 0},{1, 1, 1, 0},{0, 0, 0, 0}},	//2 번 T형 블록
 {{0, 0, 0, 0},{0, 1, 0, 0},{0, 1, 1, 0},{0, 1, 0, 0}},
 {{0, 0, 0, 0},{0, 0, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0}},
 {{0, 0, 0, 0},{0, 1, 0, 0},{1, 1, 0, 0},{0, 1, 0, 0}}},
 
{{{0, 0, 0, 0},{0, 0, 1, 0},{1, 1, 1, 0},{0, 0, 0, 0}},	//3 번 l형 블록
 {{0, 0, 0, 0},{0, 1, 0, 0},{0, 1, 0, 0},{0, 1, 1, 0}},
 {{0, 0, 0, 0},{0, 0, 0, 0},{1, 1, 1, 0},{1, 0, 0, 0}},
 {{0, 0, 0, 0},{1, 1, 0, 0},{0, 1, 0, 0},{0, 1, 0, 0}}},
 
{{{0, 0, 0, 0},{1, 0, 0, 0},{1, 1, 1, 0},{0, 0, 0, 0}},	//4 번 J형 블록
 {{0, 0, 0, 0},{0, 1, 1, 0},{0, 1, 0, 0},{0, 1, 0, 0}},
 {{0, 0, 0, 0},{0, 0, 0, 0},{1, 1, 1, 0},{0, 0, 1, 0}},
 {{0, 0, 0, 0},{0, 1, 0, 0},{0, 1, 0, 0},{1, 1, 0, 0}}},  
 
{{{0, 0, 0, 0},{0, 1, 1, 0},{1, 1, 0, 0},{0, 0, 0, 0}},	//5 번 s형 블록	
 {{0, 0, 0, 0},{0, 1, 0, 0},{0, 1, 1, 0},{0, 0, 1, 0}},
 {{0, 0, 0, 0},{0, 0, 0, 0},{0, 1, 1, 0},{1, 1, 0, 0}},
 {{0, 0, 0, 0},{1, 0, 0, 0},{1, 1, 0, 0},{0, 1, 0, 0}}}, 
 
{{{0, 0, 0, 0},{1, 1, 0, 0},{0, 1, 1, 0},{0, 0, 0, 0}},	//6 번 z형 블록	
 {{0, 0, 0, 0},{0, 0, 1, 0},{0, 1, 1, 0},{0, 1, 0, 0}},
 {{0, 0, 0, 0},{0, 0, 0, 0},{1, 1, 0, 0},{0, 1, 1, 0}},
 {{0, 0, 0, 0},{0, 1, 0, 0},{1, 1, 0, 0},{1, 0, 0, 0}}}, 
 
{{{0, 0, 1, 0},{0, 1, 1, 0},{0, 1, 1, 0},{0, 0, 0, 0}},	// (스페셜 블록) 7 번 d형 블록	
 {{0, 0, 0, 0},{0, 1, 1, 0},{0, 1, 1, 1},{0, 0, 0, 0}},
 {{0, 0, 0, 0},{0, 1, 1, 0},{0, 1, 1, 0},{0, 1, 0, 0}},
 {{0, 0, 0, 0},{1, 1, 1, 0},{0, 1, 1, 0},{0, 0, 0, 0}}}, 
 
{{{0, 1, 0, 0},{0, 1, 1, 0},{0, 1, 1, 0},{0, 0, 0, 0}},	// (스페셜 블록) 8 번 b형 블록	
 {{0, 0, 0, 0},{0, 1, 1, 1},{0, 1, 1, 0},{0, 0, 0, 0}},
 {{0, 0, 0, 0},{0, 1, 1, 0},{0, 1, 1, 0},{0, 0, 1, 0}},
 {{0, 0, 0, 0},{0, 1, 1, 0},{1, 1, 1, 0},{0, 0, 0, 0}}}, 
 
{{{1, 1, 1, 0},{0, 1, 0, 0},{0, 1, 0, 0},{0, 0, 0, 0}},	// (스페셜 블록) 9 번 T형 블록
 {{0, 0, 1, 0},{1, 1, 1, 0},{0, 0, 1, 0},{0, 0, 0, 0}},
 {{0, 1, 0, 0},{0, 1, 0, 0},{1, 1, 1, 0},{0, 0, 0, 0}},
 {{1, 0, 0, 0},{1, 1, 1, 0},{1, 0, 0, 0},{0, 0, 0, 0}}}, 
 
{{{0, 1, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0},{0, 0, 0, 0}},	// (스페셜 블록) 10 번 +형 블록
 {{0, 1, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0},{0, 0, 0, 0}},
 {{0, 1, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0},{0, 0, 0, 0}},
 {{0, 1, 0, 0},{1, 1, 1, 0},{0, 1, 0, 0},{0, 0, 0, 0}}},
};

bool col_rand=false, blo_Limit=false, blo_rand=false, Graduation=false;
bool t=true, t_hool=true, reset=true;

int block_color[11]={0};	// 	블럭마다의 색깔 
int block_P[4][4]={0};	//플레이어가 사용할 블럭 저장 
int block_TMP[4][4]={0};	//회전하게 저장할 배열 저장 
int i,j,level=1,Tetromino=1,ax,ay,b_remove=0,score=0;
int a[50][50]={0};	//게임판 데이터 
int max_block=7;
int k, timee, floor_count=0, speed=10000, Hold, delay=0;	 
int max_rand, rrand[11]={0}, Next[3]={0};
int rota=0;
char ch; 

struct struct1{	// 좌표 구조체 
	short x;	// x좌표 가로  ㅡ  
	short y;	// y좌표 세로  ㅣ  
}blockxy,Mep={10,20};	//블록의 좌표 변수, 맵의 맨 끝 좌표(크기) 

struct Lanking_data{
	char name[20];	// 이름  
	int level;	// 단계수 
	int score;	// 점수  
}lank[10],player; //랭크 내용 저장 변수, 플레이어 내용 저장 변수 

void frame(int framex, int framey, int x, int y);	// 간편 틀 만들기 
void Game_start();	// 게임 시작 화면
bool Game_end();	// 게임   끝 화면  
void Game_screen();	// 게임 플레이 화면 screen: 스크린 
void Game_manual();	// 게임 설명 화면 manual: 메뉴얼 
void Game_ranking();// 게임 랭킹 화면 ranking: 랭킹 
void Game_settings();	// 게임 모드 설정 settings: 설정 
void block_color_settings(); // 블록마다 색 설정 
void rotation();	// 블럭 회전 rotation: 회전 
void Keyboard_input(); // 키보드 입력 
void Graduation_text();	// 눈금문자 출력함수 



int main(){
	//	timee: 시간,	floor_count: 바닥,	Detect: 발견하다/인지하다, End: 끝, score: 점수, Hold: 보류, delay:지연 level: 수준 , reset:초기화 
	
	srand(time(NULL));
	
	while( 1 ){
		if(reset){
			system("cls");	// 화면 초기화 
			
			for(i=0;i<50;i++){	// 맵 전체 초기화 
				for(j=0;j<50;j++){
					a[i][j]=0;
				}
			}
			
			block_color_settings();	// 블록 색 초기화 
			speed=10000;	// 속도 초기화  
			floor_count=0;	// 바닥 초기화  
			for(i=0;i<11;i++) rrand[i]=0;	// 남은 블록 리스트 초기화  
			for(i=0;i<3;i++) Next[i]=0;	// 미리보기 초기화  
			level=1;	//레벨 초기화  
			b_remove=score=0;	// 선 제거 갯수, 점수 초기화  
			t=t_hool=true;			// 블록 재생성, 홀드 초기화  
			rota=0;
			reset=false;	
		}
		
		do{
			Game_start(); //시작 화면 
			
			if(ay==1) Game_manual();
			else if(ay==2) Game_settings();
			else if(ay==3) Game_ranking();
			else if(ay==4) return 0; 
		}while(ay!=0);
		
		if(blo_Limit) max_rand=Hold=max_block=10;	// 블록 리미트에 따라 블록 갯수 초기화 
		else max_rand=Hold=max_block=7;
		
		system("cls");
		
		frame(frame_X,frame_Y,20,10);
		gotoxy(frame_X+10,frame_Y+4);	printf("게임이 곧 시작합니다");
		sleep(1);
		
		
		for(i=0; i<max_rand; i++) rrand[i]=i;
			 
		if(blo_rand==false){
			for(i=0;i<3;i++){				
				max_rand--;																	
				for(j=rand()%max_rand, Next[i]=rrand[j]; j<max_rand; j++){
					rrand[j]=rrand[j+1];						
				}
			}	
		}
		
		
		Game_screen();
		
		for(timee=1; 1 ; timee++){	// 게임 시작		
		
				
				
			if(t){	// 새 블럭 생성							 
				int ai,add=0;	
				
				
				//점수 매기기																												
				for(i=1;i<=Mep.y;i++){
					
					for(j=1;j<=Mep.x;j++){	// 맵의 한줄 한줄을 검사
						if(a[i][j]%10!=5) break;	// 블록이 안 채워졌다면 나감 			
					}
						
					if(j==Mep.x+1){	// 맵에 10줄이 그어졌다면 
						if(col_rand==true && add==0)	for(k=0;k<max_block;k++)	block_color[k]=17*(1+rand()%15);	// 랜덤한 색 설정시 줄 없앨 때마다 색을 바꿈 
						
						b_remove++;	// 한줄 채울때마다 1개 기록  
						score+=100+add*10;	//100은 기본점수 중첩이 될수록 큰 보너스 점수 
						add++;
						
						if((b_remove+1)%11==0){	// 게임이 10점씩 얻을 때마다 빨라짐  																
							if(speed<=200)	speed-=50;
							else if(speed<=1000)	speed-=200;									
							else if(speed<=3000) speed-=500;								
							else if(speed<=10000) speed-=1000;
							else speed-=2000;
							
							level++;
						} 
								
						gotoxy(hold_X+1, frame_Y+6+3);	printf("%2d",level);
						gotoxy(hold_X-1, frame_Y+6+5);	printf("%6d",score);
						gotoxy(hold_X+2, frame_Y+6+7);	printf("%3d",b_remove);	 
						
						ai=i;
						// 한줄을 없애기 위해 그 위에 있는 정보로 갈아치움
						for(i=Mep.y;i>1;i--){	  
							for(j=1;j<=Mep.x;j++){	
								if( ai>=i ) a[i][j]=a[i-1][j];	// 현재 내 정보를 줄 위에 있는 정보로 저장  
										
								gotoxy(frame_X+(j-1)*2,frame_Y+i-1);								
								if(a[i][j]%10==5){ 
									textcolor(block_color[a[i][j]/10]);
									printf("■");	// 바꾼 정보로 출력---■-----------------------------------------------------------
									textcolor(7);
								}
								else if(Graduation) Graduation_text();
								else printf("  ");
							}							
						}								
					}	
				}
				
				//	여기부턴 테트리스 미노의 규칙을 따르기 위한 코드						
				if(max_rand==0){	
					max_rand=max_block;
					for(i=0; i<max_rand; i++) rrand[i]=i;
				}
						
				Tetromino=Next[0];	// 미리보기의 첫번째를 저장 
						
				for(i=0;i<2;i++){	// 미리보기를 한칸씩 앞당겨서 
					Next[i]=Next[i+1];	
				}
						
				Next[2]=rand()%max_rand;  // 새로운 값으로 넣음 
				
				if(blo_rand==false){	// 랜덤 블록 비활성화시 골구루나오게 하기 
					max_rand--;																								
							
					for(i=Next[2], Next[2]=rrand[Next[2]]; i<max_rand; i++){
						rrand[i]=rrand[i+1];						
					}
				}	
				
						
				for(k=0;k<3;k++){	// 미리보기의 시각화 									
					for(i=0;i<4;i++){	
						for(j=0;j<4;j++){
							
							if(block[Next[k]][0][i][j]){
								textcolor(block_color[Next[k]]);
															
								gotoxy(next_X+(j+1+Mep.x)*2,frame_Y+i+k*4);
								printf("■");	
										
								textcolor(7);												
							}
							else{
								gotoxy(next_X+(j+1+Mep.x)*2,frame_Y+i+k*4);
								printf("  ");
							} 
						}
					}
				}	
								
				// 블록 생성																							
				blockxy.x=Mep.x/2-1;	// 블록의 위치 초기화  
				blockxy.y=1;
				
				rota=0;
				
				for(i=0;i<4;i++){						
					for(j=0;j<4;j++){	// 새로운 블록형으로 블록 초기화 
						block_P[i][j] = block[Tetromino][rota][i][j];
					}
							
					for(j=0;j<4;j++){	// 생성될 자리에 이미 블럭이 놓여져 있는지 검사 		
						if(block_P[i][j]){																			
							if(a[i+blockxy.y][j+blockxy.x]%10==5){								
								if(Game_end()) reset=true;
								else return 0;
							}
						}
					}
				}
				
				if(reset) break;	// 게임 다시 시작 
				
				for(i=0;i<4;i++){	// 새로운 블럭 생성  
					for(j=0;j<4;j++){
						if(block_P[i][j]){	
							textcolor(block_color[Tetromino]);	
												
							gotoxy(frame_X+(j+blockxy.x-1)*2,frame_Y+i+blockxy.y-1);
							printf("■");
													
							textcolor(7);																
						}
					}
				}					
		
				t=false;	//  재 생성 제한 
				t_hool=false;	// 새롭게 블록이 생성됐으니 홀드 기능 사용 가능 
				floor_count=0; 
			}
			
			if(timee%(speed/20) +1 == 1 ){ 	//게임 프레임 속도	
			
				// 현재 위치 블록 지우기  
				for(i=0;i<4;i++){	 
					for(j=0;j<4;j++){
						if(block_P[i][j]){					
							gotoxy(frame_X+(j+blockxy.x-1)*2,frame_Y+i+blockxy.y-1);	
							if(Graduation) Graduation_text();
							else printf("  ");	
						}
					}
				}	
					
				// 블럭의 위치 변경							
				blockxy.x+=ax;	//	블럭의 x좌표 변경 ( 왼쪽 & 오른쪽) 
				blockxy.y+=ay;	//	블럭의 y좌표 변경 ( 아래 )
				ay=ax=0; 
														
				if(timee>=speed){	//아래 바닥이 있다면 멈춤 
					// 블록 아래 장애물 확인 
					for(i=0;i<4;i++){	//아래부터 검사 
						for(j=0;j<4;j++){
							if(block_P[i][j]){					
								if(a[i+blockxy.y+1][j+blockxy.x]%10==5) break;		// 아래 장애물이 있다면 나온다																								
							}
						}
						
						if(j!=4) break;
					}		
					 
					gotoxy(hold_X-1, frame_Y+6+5);	printf("%6d",score);
														 
					timee=1;					
							
					if(i==4){	// 아래 장애물이 없다면  
						floor_count=0;	// 바닥에 있던 시간을 초기화   
						blockxy.y++;	//	블럭의 y좌표 한칸 아래로 변경
					}
					else{	// 아래 장애물이 있다면  
						floor_count++;	// 아래 장애물이 있다면 바닥에 있는 시간에 1추가
					}  
				}											
				 		
				if(floor_count%2==0) textcolor(block_color[Tetromino]);	// 반짝반짝 												
				else textcolor(block_color[Tetromino]/17);
				
				for(i=0;i<4;i++){	
					for(j=0;j<4;j++){
						if(block_P[i][j]){					
							gotoxy(frame_X+(j+blockxy.x-1)*2,frame_Y+i+blockxy.y-1);
							printf("■");
						}
					}
				} 
				
				if(floor_count>=6){	// 바닥에 있던 시간이 6이상이라면  
					textcolor(block_color[Tetromino]);
					
					for(i=0;i<4;i++){	
						for(j=0;j<4;j++){
							if(block_P[i][j]){					
								gotoxy(frame_X+(j+blockxy.x-1)*2,frame_Y+i+blockxy.y-1);
								printf("■");
								
								a[i+blockxy.y][j+blockxy.x]=Tetromino*10+5;									
							}
						}
					}   
					
					floor_count=0;	// 초기화
					t=true;	// 블록 재생성  
				} 
				
				textcolor(7);
			}
			
			// 플레이어의 입력시 움직임
			if(kbhit()){				
				Keyboard_input();
			} 	
		} 
	}
}



void rotation(){	// 블럭 회전 
	//현재 블록 위치 비우기 
	for(i=0;i<4;i++){	
		for(j=0;j<4;j++){
			if(block_P[i][j]){					
				gotoxy(frame_X+(j+blockxy.x-1)*2,frame_Y+i+blockxy.y-1);
				if(Graduation) Graduation_text();
				else printf("  ");													
			}
		}
	}
	
	if(rota==3) rota=0;
	else rota++;
	
	int max,may;
	
	for(max=0;max<=2;max++){
		for(i=0;i<4;i++){												
			for(j=0;j<4;j++){
				if(block[Tetromino][rota][i][j]){																			
					if(a[i+blockxy.y][j+blockxy.x+max]%10==5) break;	//플레이어 블록과 겹치는 다른 블록이 있는지 검사  													
				}
			}
			
			if(j!=4) break;
		}
		
		if(i==4) break; //만약 장애물이 없다면 나감  
	}
	
	for(may=0;may<=2;may++){
		for(i=0;i<4;i++){		// 왼쪽 플레이어 블록과 겹치는 다른 블록이 있는지 검사	
			for(j=0;j<4;j++){
				if(block[Tetromino][rota][i][j]){																			
					if(a[i+blockxy.y+may][j+blockxy.x]%10==5) break;	  													
				}
			}
			
			if(j!=4) break;
		}
		
		if(i==4) break; //만약 장애물이 없다면 나감  
		
		for(i=0;i<4;i++){		// 오른쪽 플레이어 블록과 겹치는 다른 블록이 있는지 검사 	
			for(j=0;j<4;j++){
				if(block[Tetromino][rota][i][j]){																			
					if(a[i+blockxy.y-may][j+blockxy.x]%10==5) break; 													
				}
			}
			
			if(j!=4) break;
		}
		
		if(i==4){
			may=-may;
			break; //만약 장애물이 없다면 나감
		}  
	}	
	
	if(may==3) may=0;	// may 반복문이 끝까지 돌았다면 장애물이 모두 있으므로 안변함 
	if(max==3) max=0;	// max 반복문이 끝까지 돌았다면 장애물이 모두 있으므로 안변함 
	
	for(i=0;i<4;i++){		// 회전후 자리에 이미 블럭이 놓여져 있는지 검사 											
		for(j=0;j<4;j++){
			if(block[Tetromino][rota][i][j]){																			
				if(a[i+blockxy.y+may][j+blockxy.x+max]%10==5) break;	//플레이어 블록과 겹치는 다른 블록이 있는지 검사  													
			}
		}
		
		if(j!=4) break;
	}
	
	/* 회전값 확인 
	gotoxy(100,20+2);
	printf("회전후 바뀐 x좌표:%d, y좌표:%d  ",max,may);
	*/
	if(i==4) {
		blockxy.x+=max;
		blockxy.y+=may;	
		
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				block_P[i][j]=block[Tetromino][rota][i][j];
			}
		}
	}
	else{
		if(rota==0) rota=3;
		else rota--;
	}		
		
	ax=ay=0;
}

void Game_start(){	//시작 화면 	
	ch=ay=0;
	
	system("cls");
	
	frame(frame_X, frame_Y, 20, 20);
	
	gotoxy(frame_X+44,frame_Y+7);	printf("방향키 ↑: 위로 이동");
	gotoxy(frame_X+44,frame_Y+8);	printf("방향키 ↓: 아래로 이동");
	gotoxy(frame_X+44,frame_Y+10);	printf("스페이스바 : 클릭");

	gotoxy(frame_X+10-2,frame_Y+3);	printf("★텍스트 텍트리스 게임★");
	
	gotoxy(frame_X+10,frame_Y+7);	printf("1. 시작");
	gotoxy(frame_X+10,frame_Y+9);	printf("2. 방법");
	gotoxy(frame_X+10,frame_Y+11);	printf("3. 모드");
	gotoxy(frame_X+10,frame_Y+13);	printf("4. 순위");
	gotoxy(frame_X+10,frame_Y+15);	printf("5.나가기");
	
	
	
	while(ch!=32) {
		gotoxy(frame_X+18,frame_Y+7+ay*2);	printf("<--");
		
		ch=getch();
		
		gotoxy(frame_X+18,frame_Y+7+ay*2);	printf("   ");
		
		switch(ch){
			case 72:
				if(ay>0) ay--;
				break;
			case 80:
				if(ay<4) ay++;
				break;
		} 
	}
}

void frame(int framex, int framey, int x, int y){	// 간편 틀 만들기 

	for(i=-1;i<y+1; i++){
		for(j=-1;j<x+1;j++){
			if(i==-1 || j==-1 || i==y || j==x){					
				gotoxy(framex+j*2,framey+i);
				printf("□");				
			}
		}
	} 
	
}

void Game_screen(){	// 게임 화면 
	system("cls");
	
	gotoxy(hold_X+3,frame_Y-2);	//홀드 칸 위에 Holb출력 
	printf("보류");
	
	gotoxy(next_X+(Mep.x)*2+1, frame_Y-2);	//넥스트 칸 맨 위에 Next출력 
	printf("미리보기");
	
	textcolor(8);	//칸들의 색 설정 
	
	frame(hold_X, frame_Y,5,5);	//홀드 칸 출력 	
	frame(hold_X-4, frame_Y+6+2,7,7);	// 레벨, 점수, 그냥이 들어갈 자리 
	
	for(i=0;i<Mep.y+2; i++){
		for(j=0;j<Mep.x+2;j++){
			if(i==0 || j==0 || i==Mep.y+1 || j==Mep.x+1){					
				gotoxy(frame_X+(j-1)*2,frame_Y+i-1);
				printf("□");
				
				a[i][j]=5;				
			}
			else if(Graduation){
				gotoxy(frame_X+(j-1)*2,frame_Y+i-1);
				Graduation_text();
				textcolor(8);
			}
		}
	} 	 		
	
	frame(next_X+(Mep.x)*2, frame_Y, 5, 12);	// 미리보기 칸 출력 
	
	textcolor(7);
	
	gotoxy(hold_X+1, frame_Y+6+3);	printf("%2d",level);	//  레벨  
	gotoxy(hold_X+4, frame_Y+6+3);	printf("단계");
	
	gotoxy(hold_X-1, frame_Y+6+5);	printf("%6d",score);	//  점수
	gotoxy(hold_X+6, frame_Y+6+5);	printf("점");	 
	
	gotoxy(hold_X+2, frame_Y+6+7);	printf("%3d",b_remove);	//  그냥 
	gotoxy(hold_X+6, frame_Y+6+7);	printf("선");
}
 
bool Game_end(){
	system("cls");
	
	frame(frame_X, frame_Y, 30, 20);

	gotoxy(frame_X+20,frame_Y+6);	printf("END");
	
	gotoxy(frame_X+14,frame_Y+7);	printf("당신의 최종 점수는 %d점 입니다",score);
	gotoxy(frame_X+14,frame_Y+8);	printf("수고하셨습니다");
	
	Sleep(100);
	
	FILE* pt=fopen("TetrisLank.txt","r+");
 	
	
	
	
	if(pt=='\0'){	//파일이 없을때를 대비  
		gotoxy(frame_X+8,frame_Y+12);	printf("현재 랭크파일이 없어, 점수를 갱신할 수 없습니다");
	}
	else if(blo_Limit || col_rand || blo_rand || Mep.x!=10 || Mep.y!=20){
		gotoxy(frame_X+8,frame_Y+12);	printf("현재 모드 적용중, 점수를 갱신할 수 없습니다");
		gotoxy(frame_X+16,frame_Y+14);	printf("--+ 적용된 모드+--"); 
		gotoxy(frame_X+2,frame_Y+15);
		if(Mep.x!=10 || Mep.y!=20) printf(" 게임판 확장,");
		if(blo_Limit) printf(" 블록 확장,"); 
		if(col_rand) printf(" 랜덤 색,"); 
		if(blo_rand) printf(" 랜덤 블록,");
		
		printf("\b "); 
	}	
	else{	
		gotoxy(frame_X+8,frame_Y+10);	printf("랭크에 점수를 갱신하시겠습니까(y/n)");
		do{	ch=getch();	}while(ch!='y' && ch!='n');
		
		if(ch=='y'){
			gotoxy(frame_X+8,frame_Y+10);	printf("랭크에 갱신될 닉네임을 입력해주세요");
			gotoxy(frame_X+8,frame_Y+11);	printf("닉네임:"); 
			scanf("%s",player.name);
			
			player.level=level;
			player.score=score;
			
			for(i=0; i < 10; i++){	
				fscanf(pt,"%s %d %d",&lank[i].name, &lank[i].level, &lank[i].score);
			}
			
			for(i=9;lank[i].score<player.score && i>=0;i--){
				if(i!=9) lank[i+1]=lank[i];
				lank[i]=player;
			}
			
			fseek(pt,0,SEEK_SET);
			for(i=0;i<10;i++){
				fprintf(pt,"%s %d %d\n",lank[i].name, lank[i].level, lank[i].score);
			}
			
			gotoxy(frame_X+8,frame_Y+14);	printf("갱신이 완료되었습니다."); 
		}
	}
	
	fclose(pt);
	
	gotoxy(frame_X+8,frame_Y+17);	printf("로비로 이동하시겠습니까? ( y:예, n:끝내기)");
	
	do{
		ch=getch();
	}while(ch!='y' && ch!='n');
	
	if(ch=='y') return true;
	else return false;
	
} 

void Game_manual(){
	system("cls");
	
	frame(hold_X, frame_Y, 40, 30);

	gotoxy(hold_X+10+4,frame_Y+1);	printf("사용 설명서");
	
	gotoxy(hold_X+10,frame_Y+6);	printf("조작키");
	
	gotoxy(hold_X+8,frame_Y+8);		printf("a키: 일시정지, 일시정지 후 아무 키 입력시 풀림"); 
	gotoxy(hold_X+8,frame_Y+9);		printf("c키: 홀드(블록 보류)"); 
	gotoxy(hold_X+8,frame_Y+11);	printf("스페이스바: 바로 내리기"); 
	gotoxy(hold_X+8,frame_Y+13);	printf("방향키(  ↑  ): 블록 회전"); 
	gotoxy(hold_X+8,frame_Y+14);	printf("방향키(←↓→): 블록 왼쪽/ 아래/ 오른쪽 한칸 이동"); 
	
	gotoxy(hold_X+10,frame_Y+16);	printf("규칙");
	
	gotoxy(hold_X+6,frame_Y+18);	printf("1. 블록을 블록이 나오는 지역까지 쌓았다면 게임 끝"); 
	gotoxy(hold_X+6,frame_Y+20);	printf("2. 방향키(↓)나 스페이스바로 블록을 떨어트린다면 이동거리만큼 +추가 점수"); 
	gotoxy(hold_X+6,frame_Y+22);	printf("3. 줄마다 제거시 점수 획득, 한꺼번에 여러 줄 제거시 +추가 점수"); 
	gotoxy(hold_X+6,frame_Y+24);	printf("4. 점수에 따라 순위를 매김 "); 
	
	gotoxy(hold_X+40,frame_Y+28);	printf("스페이스바 = 뒤로가기..");
	
	do{
		ch=getch();	
	}while(ch!=32);
}

void Game_settings(){
	Graduation=blo_Limit=col_rand=blo_rand=false;
	system("cls");
	
	frame(frame_X, frame_Y, 20, 20);

	gotoxy(frame_X+6,frame_Y+3);	printf("게임 모드 (중복 선택 가능)");
	gotoxy(frame_X+0,frame_Y+4);	printf("*눈금 표시 외 모드 적용시 랭크 갱신 불가");
	
	gotoxy(frame_X+10,frame_Y+7);	printf("게임판 확장");	// Mep.x,Mep.y
	gotoxy(frame_X+10,frame_Y+9);	printf("블록 확장");	// blo_Limit
	gotoxy(frame_X+10,frame_Y+11);	printf("랜덤한 색");	// col_rand
	gotoxy(frame_X+10,frame_Y+13);	printf("랜덤한 블록");	// blo_rand
	gotoxy(frame_X+10,frame_Y+15);	printf("눈금 표시");	// Graduation
	gotoxy(frame_X+10,frame_Y+17);	printf("설정 완료");
	
	
	int set[5]={0}; 
	while(1) {
		gotoxy(frame_X+26,frame_Y+7+ay*2);	printf("<--");
			
		gotoxy(frame_X+44,frame_Y+10);			printf("                                          ");
		gotoxy(frame_X+44,frame_Y+11);			printf("                                          ");
		switch(ay){
			
			case 0:
				gotoxy(frame_X+44,frame_Y+10);	printf("게임판이 넓어집니다");
				gotoxy(frame_X+44,frame_Y+11);	printf("오래 즐길 수 있습니다");
				break;
			case 1:
				gotoxy(frame_X+44,frame_Y+10);	printf("신기한 블록이 나타납니다");
				gotoxy(frame_X+44,frame_Y+11);	printf("게임이 어려워집니다");
				break;
			case 2:
				gotoxy(frame_X+44,frame_Y+10);	printf("줄을 없앨 때마다 블록 색이 달라집니다");
				gotoxy(frame_X+44,frame_Y+11);	printf("지루함이 덜합니다");
				break;
			case 3:
				gotoxy(frame_X+44,frame_Y+10);	printf("블록 이 더욱 무작위로 나옵니다");
				gotoxy(frame_X+44,frame_Y+11);	printf("게임이 어려워집니다");
				break;
			case 4:
				gotoxy(frame_X+44,frame_Y+10);	printf("초보자를 위한 눈금입니다");
				gotoxy(frame_X+44,frame_Y+11);	printf("게임이 원활해집니다");
				break;
		} 
		ch=getch();
		
		if(ch==32){	// 스페이스바를 누를시 
			if(ay==5) break;	// 설정완료라면 끝 
			else{
				if(set[ay]==0){	 
					gotoxy(frame_X+6,frame_Y+7+ay*2);	printf("★");
					set[ay]=1;
				} 
				else{
					gotoxy(frame_X+6,frame_Y+7+ay*2);	printf("  ");
					set[ay]=0;
				}
			}
		}
		
		gotoxy(frame_X+26,frame_Y+7+ay*2);	printf("   ");
		
		switch(ch){
			case 72:
				if(ay>0) ay--;
				break;
			case 80:
				if(ay<5) ay++;
				break;
		} 
	}
	
	if(set[0]){
		Mep.x+=10;
		Mep.y+=10;
	}
	if(set[1]) blo_Limit=true;
	if(set[2]) col_rand=true;
	if(set[3]) blo_rand=true;
	if(set[4]) Graduation=true; 
}

void block_color_settings(){
	block_color[0]=17*11;
	block_color[1]=17*9;
	block_color[2]=17*3;
	block_color[3]=17*6;
	block_color[4]=17*10;
	block_color[5]=17*13;
	block_color[6]=17*12;
	block_color[7]=17*15;
	block_color[8]=17*1;
	block_color[9]=17*4;
	block_color[10]=17*14;
}

void Game_ranking(){
	FILE* fp=fopen("TetrisLank.txt","r");
	
	system("cls");
	
	frame(frame_X, frame_Y, 20, 30);
	
	if(fp=='\0'){
		gotoxy(frame_X+10,frame_Y+5);	printf("현재 랭크파일이 없어");
		gotoxy(frame_X+8,frame_Y+6);	printf("점수를 확인할 수 없습니다");
	} 
	else{
		for(i=0; i < 10; i++){	
			fscanf(fp,"%s %d %d",&lank[i].name, &lank[i].level, &lank[i].score);
		}
		
		gotoxy(frame_X+4,frame_Y+3);	printf("순위	이름	단계	점수");
		for(i=0;i<10 && lank[i].level!=0;i++){
			gotoxy(frame_X+4,frame_Y+i*2+5);	printf("%2d위- %10s  %2d %8d",i+1,lank[i].name, lank[i].level, lank[i].score);
		}
	} 
	
	gotoxy(frame_X+15,frame_Y+28);	printf("스페이스바 = 뒤로가기..");
	
	do{
		ch=getch();	
	}while(ch!=32);
}

void Keyboard_input(){
	switch(ch=getch()){
		case 72:	// 방향키: 위 (회전 기능) 
						
			rotation();	// 블럭 회전 함수 
						
			break;
		case 80:	// 방향키: 아래 (빠른 낙하 기능) 
			for(i=0;i<4;i++){	
				for(j=0;j<4;j++){
					if(block_P[i][j]){																		
						if(a[i+blockxy.y+1][j+blockxy.x]%10==5 ) break;																												
					}
				}
				if(j!=4) break;
			}	
						
			if(i==4){ 
				score++;	//점수 증가 
				ay=1;	// 아래에 블록,바닥이 없을시 한칸 더 빠르게 이동 
			}
						
			break;
		case 75:	// 방향키: 왼쪽 (블록 왼쪽 이동)		
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(block_P[i][j]){
						if( a[i+blockxy.y][j+blockxy.x-1]%10==5) break;																					
					} 							
				}
							
				if(j!=4) break;	//왼쪽에 장애물이 있을시 바로 종료 						
			}		
																			 						
			if(i==4) ax=-1;	// 왼쪽 방향에 블록이나 벽이 없을시 왼쪽으로 한칸 이동 (바로 종료되지 않을시 실행)	
						
			break;
		case 77:	// 방향키: 오른쪽 (블록 오른쪽 이동) 
			for(i=0;i<4;i++){
				for(j=0;j<4;j++){
					if(block_P[i][j]){
						if( a[i+blockxy.y][j+blockxy.x+1]%10==5) break;																				
					} 							
				}
							
				if(j!=4) break;	//오른쪽에 장애물이 있을시 바로 종료 
			}	
							
			if(j==4) ax=1;	// 오른쪽 방향에 블록,벽이 없을시 오른쪽으로 한칸 이동 	(바로 종료되지 않을시 실행)	
								
			break;
		case 32:	// 스페이스바 (바로 착지) 
						
			///블록 지우기 
			for(i=0;i<4;i++){	
				for(j=0;j<4;j++){
					if(block_P[i][j]){					
						gotoxy(frame_X+(j+blockxy.x-1)*2,frame_Y+i+blockxy.y-1);
						if(Graduation) Graduation_text();
						else printf("  ");		
					}
				}
			}
						
			while(i==4){	// 아래에 무언가 있다면 반복문 종료 
				for(i=0;i<4;i++){	
					for(j=0;j<4;j++){
						if(block_P[i][j]){																		
							if(a[i+blockxy.y+1][j+blockxy.x]%10==5) break;																														
						}
					}
								
					if(j!=4) break;	// 아래쪽에 장애물이 있을시 바로 종료
				}	
							
				if(i==4){ 
					score+=4;	// 점수 두배 증강 
					blockxy.y++;	// 아래에 아무것도 없을시 블록 위치 아래로 변경	(바로 종료되지 않을시 실행)		
				}
			}
					
			floor_count=7;	// 바로 블록을 착지 
						 
			break;	
		case 99:	//c키 (홀드에 블록을 저장 / 꺼내기)				
			if(t_hool == false){	// 홀드의 기능을 이미 사용했나 검사 
				int temp;	// 홀드안에 있는 것과 현재 가지고 있는 데이터를 교환시키기 위함. 
							
				///블록 지우기 
				for(i=0;i<4;i++){	
					for(j=0;j<4;j++){
						if(block_P[i][j]){					
							gotoxy(frame_X+(j+blockxy.x-1)*2,frame_Y+i+blockxy.y-1);
							if(Graduation) Graduation_text();
							else printf("  ");		
						}
					}
				}
																			
				if(Hold==7){
					t=true;
				}
				else{
					blockxy.x=4;	// 블록 위치 처음지점으로 이동 
					blockxy.y=1;
					
					rota=0;
					
					for(i=0;i<4;i++){							
						for(j=0;j<4;j++){
							block_P[i][j]=block[Hold][rota][i][j];	// hold에 있는 미노의 데이터를 저장 
						}																
					}
				}
											
				temp=Hold;	//홀드의 값을 딴 곳에 저장  
				Hold=Tetromino;	//홀드에 현재 값을 저장 
				Tetromino=temp;	//따로 저장해둔 홀드의 값을 현재 값으로 저장 
							
				for(i=0;i<4;i++){	// hold칸에 시각적으로 보여줌 	
					for(j=0;j<4;j++){																
						if(block[Hold][0][i][j]){					
							textcolor(block_color[Hold]);
										
							gotoxy(hold_X+(j+1)*2,frame_Y+i);
							printf("■");
										
							textcolor(7);
						}
						else{
							gotoxy(hold_X+(j+1)*2,frame_Y+i);
							printf("  ");
						}
					}
				}
							
				t_hool=true;	// 홀드 기능을 사용했다고 알림		
			}
																 
			break;	
		case 97:	//a키(일시정지)			
						
			do{
				ch=getch();
			}while(ch!='a');
			break;		
	}
}

void Graduation_text(){
	textcolor(16*8);
	printf("■");
	textcolor(7);
}

// 1000줄 넘기! 

#ifndef _BREAKOUT_H
#define _BREAKOUT_H
#define BALLRADIUS 15 //공 지름

#define BRICKWIDTH 64  //벽돌 가로
#define BRICKHEIGHT 40  //벽돌 세로 
#define BRICKLINE 3	//벽돌 줄 수
#define BRICKNO 16	// 줄당 벽돌 갯수


typedef struct {

	int ballX, ballY;    //공 좌표
	int ballDirX, ballDirY;   //공 이동좌표
	int ballSpeed = 10;  //공 속도
	int padX, padY, padWidth;  // 라켓 정의(x, y, 크기)
	int bricks[BRICKLINE][BRICKNO];  // 벽돌 배열
	int repeat = 0;
	int count = 0;

} Brick;

void initGame();   //게임초기화
void moveBall();   //공 움직임
void drawBall();   //현재 공의 위치에 검은색 공 그려줌
void bounceBall();  //공 튀기기
void movePad();    //라켓 움직임
void drawPad();   //라켓 그려줌

void drawBrick();  //벽돌 그려줌
void gameOver();
void levelUp();

#endif
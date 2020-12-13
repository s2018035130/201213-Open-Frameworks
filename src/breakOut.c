#include "ofApp.h"
#include "breakOut.h"
Brick game;  //게임을 위한 변수

			 //게임 초기화
			 //공의 초기위치 화면의 중앙에 설정
			
void initGame() {
	game.ballX = ofGetWidth() / 2;     //공 정중앙 의미
	game.ballY = ofGetHeight() / 2;    //공 정중앙
	game.ballDirX = game.ballDirY = game.ballSpeed = 10;

	game.padX = ofGetWidth() / 2;       //정중앙
	game.padY = ofGetHeight() - 50;   
	game.padWidth = 400;               //라켓 길이

									   //벽돌을 위한 2차원 배열 변수의 모든값을 1로 초기화
									   //1은 벽돌이 있음
									   //0은 벽돌이 없음
	if (game.repeat == 0)
	{
		for (int j = 0; j < BRICKLINE; j++) {
			for (int i = 0; i < BRICKNO; i++) {
				game.bricks[j][i] = 1;
			}
		}
	}
	if (game.repeat > 0)
	{
		for (int j = 0; j < BRICKLINE + game.repeat; j++) {
			for (int i = 0; i < BRICKNO; i++) {
				game.bricks[j][i] = 1;
			}
		}
	}
}
//벽돌을 그리는 함수
//오픈프레임웍스는 도형의 내부 색상과 외곽선 색상을 동일하게 해야한다.
//그래서 노란색으로 벽돌을 그린 후에
//다시 ofNoFill()로 도형 내부를 채우지 않는 모드로, 검은색으로 외곽선을 그려야 한다.
void drawBrick() {
	ofFill();
	ofSetColor(ofColor::yellow);
	for (int j = 0; j < BRICKLINE + game.repeat; j++) {
		for (int i = 0; i < BRICKNO; i++) {
			if (game.bricks[j][i] == 1) {
				ofDrawRectRounded(i*BRICKWIDTH, j*BRICKHEIGHT, BRICKWIDTH, BRICKHEIGHT, 10);
			}

		}
	}
	ofNoFill();
	ofSetColor(ofColor::black);
	for (int j = 0; j < BRICKLINE + game.repeat; j++) {
		for (int i = 0; i < BRICKNO; i++) {
			if (game.bricks[j][i] == 1) {
				ofDrawRectRounded(i*BRICKWIDTH, j*BRICKHEIGHT, BRICKWIDTH, BRICKHEIGHT, 10);
			}

		}
	}
	ofNoFill();
	ofSetColor(ofColor::white);
	for (int j = 0; j < BRICKLINE + game.repeat; j++) {
		for (int i = 0; i < BRICKNO; i++) {
			if (game.bricks[j][i] == 0) {
				ofRect(i*BRICKWIDTH, j*BRICKHEIGHT, BRICKWIDTH, BRICKHEIGHT);
			}
		}
	}

}
//라켓 움직이는 함수
//ofGetMouseX()함수는 오픈프레임웍스에서 제공하는 마우스의 X좌표를 반환하는 함수
void movePad() {
	game.padX = ofGetMouseX();
}
//라켓 그려주는 함수
//ofLine()함수는 선분을 그려주는 함수
void drawPad() {
	ofFill();
	ofSetColor(ofColor::black);
	ofLine(game.padX - game.padWidth / 2, game.padY, game.padX + game.padWidth / 2, game.padY);
}

void moveBall() {
	game.ballX += game.ballDirX;
	game.ballY += game.ballDirY;
	bounceBall();
	gameOver();
	levelUp();
}
//현재 공의 위치에 검은색 공을 그려줌
void drawBall() {
	ofFill();
	ofSetColor(ofColor::black);
	ofCircle(game.ballX, game.ballY, BALLRADIUS);
}

void bounceBall() {
	if (game.ballX <= BALLRADIUS || game.ballX > ofGetWidth() - BALLRADIUS) game.ballDirX *= -1;
	if (game.ballY <= BALLRADIUS) game.ballDirY *= -1;
	if (game.ballY >= ofGetHeight() - BALLRADIUS) game.ballDirY *= -1;
	else if (game.ballY >= game.padY - BALLRADIUS &&
		game.ballX >= game.padX - game.padWidth / 2 &&
		game.ballX <= game.padX + game.padWidth / 2) {
		game.ballDirY *= -1;
	}
	
	if (game.ballY <= BRICKHEIGHT * BRICKLINE + BALLRADIUS) {
		if (game.bricks[game.ballY / BRICKHEIGHT][game.ballX / BRICKWIDTH] == 1) {
			game.bricks[game.ballY / BRICKHEIGHT][game.ballX / BRICKWIDTH] = 0;
			game.ballDirY *= -1;
			game.count++;
		}
	}
}
void gameOver() {
	if (game.ballY >= ofGetHeight() - BALLRADIUS) {
		printf("게임이 종료되었습니다\n");

		initGame();
	}

}void levelUp() {
	if (game.count >= BRICKLINE * BRICKNO)
	{
		game.repeat++;
		initGame();
		game.count = 0;

	}
}
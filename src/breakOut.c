#include "ofApp.h"
#include "breakOut.h"
Brick game;  //������ ���� ����

			 //���� �ʱ�ȭ
			 //���� �ʱ���ġ ȭ���� �߾ӿ� ����
			
void initGame() {
	game.ballX = ofGetWidth() / 2;     //�� ���߾� �ǹ�
	game.ballY = ofGetHeight() / 2;    //�� ���߾�
	game.ballDirX = game.ballDirY = game.ballSpeed = 10;

	game.padX = ofGetWidth() / 2;       //���߾�
	game.padY = ofGetHeight() - 50;   
	game.padWidth = 400;               //���� ����

									   //������ ���� 2���� �迭 ������ ��簪�� 1�� �ʱ�ȭ
									   //1�� ������ ����
									   //0�� ������ ����
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
//������ �׸��� �Լ�
//���������ӿ����� ������ ���� ����� �ܰ��� ������ �����ϰ� �ؾ��Ѵ�.
//�׷��� ��������� ������ �׸� �Ŀ�
//�ٽ� ofNoFill()�� ���� ���θ� ä���� �ʴ� ����, ���������� �ܰ����� �׷��� �Ѵ�.
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
//���� �����̴� �Լ�
//ofGetMouseX()�Լ��� ���������ӿ������� �����ϴ� ���콺�� X��ǥ�� ��ȯ�ϴ� �Լ�
void movePad() {
	game.padX = ofGetMouseX();
}
//���� �׷��ִ� �Լ�
//ofLine()�Լ��� ������ �׷��ִ� �Լ�
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
//���� ���� ��ġ�� ������ ���� �׷���
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
		printf("������ ����Ǿ����ϴ�\n");

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
#ifndef _BREAKOUT_H
#define _BREAKOUT_H
#define BALLRADIUS 15 //�� ����

#define BRICKWIDTH 64  //���� ����
#define BRICKHEIGHT 40  //���� ���� 
#define BRICKLINE 3	//���� �� ��
#define BRICKNO 16	// �ٴ� ���� ����


typedef struct {

	int ballX, ballY;    //�� ��ǥ
	int ballDirX, ballDirY;   //�� �̵���ǥ
	int ballSpeed = 10;  //�� �ӵ�
	int padX, padY, padWidth;  // ���� ����(x, y, ũ��)
	int bricks[BRICKLINE][BRICKNO];  // ���� �迭
	int repeat = 0;
	int count = 0;

} Brick;

void initGame();   //�����ʱ�ȭ
void moveBall();   //�� ������
void drawBall();   //���� ���� ��ġ�� ������ �� �׷���
void bounceBall();  //�� Ƣ���
void movePad();    //���� ������
void drawPad();   //���� �׷���

void drawBrick();  //���� �׷���
void gameOver();
void levelUp();

#endif
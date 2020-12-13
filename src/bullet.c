#include "ofApp.h"
#include "arrayList.h"
#include "breakOut.h"
#include "bullet.h"

extern Brick game;
ArrayList bullet;

//�Ѿ� ����Ʈ �ʱ�ȭ �Լ�
//�Ѿ� �迭 ���� �ʱ�ȭ
void initBullet() {
	init(&bullet);
}

//�Ѿ��� ��ǥ ���� �� ���̳� �������� �浹 ����
void moveBullet() {
	for (int i = 0; i < bullet.size; i++) {
		bullet.buf[i].y -= 10;
		int x = bullet.buf[i].x;
		int y = bullet.buf[i].y;

		//������ �浹 �Ǵ� ��� ���� �浹
		/*if (checkCollisionWithSomething(x, y) == true || y < 0) {
		remove(&bullet, bullet.buf[i]);
		break;
		}*/
		if (game.bricks[bullet.buf[i].y / BRICKHEIGHT][bullet.buf[i].x / BRICKWIDTH] == 1) {
			game.bricks[bullet.buf[i].y / BRICKHEIGHT][bullet.buf[i].x / BRICKWIDTH] = 0;
			remove(&bullet, bullet.buf[i]);
			game.count++;
		}
	}
}

//Ű���尡 ������ �Ѿ� �߻�
void addBullet(int x, int y) {
	Element elem;
	elem.x = x;
	elem.y = y;
	addLast(&bullet, elem); //�迭����Ʈ�� ������ �߰�
}

//��� �Ѿ� �߿��� Ȱ��ȭ �� �Ѿ��� �׸���.
void drawBullet() {
	ofNoFill();
	for (int i = 0; i < bullet.size; i++) {
		ofCircle(bullet.buf[i].x, bullet.buf[i].y, 6);
	}
}

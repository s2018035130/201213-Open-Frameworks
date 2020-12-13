#include "ofApp.h"
#include "arrayList.h"
#include "breakOut.h"
#include "bullet.h"

extern Brick game;
ArrayList bullet;

//총알 리스트 초기화 함수
//총알 배열 변수 초기화
void initBullet() {
	init(&bullet);
}

//총알의 좌표 변경 및 벽이나 벽돌과의 충돌 감지
void moveBullet() {
	for (int i = 0; i < bullet.size; i++) {
		bullet.buf[i].y -= 10;
		int x = bullet.buf[i].x;
		int y = bullet.buf[i].y;

		//벽돌과 충돌 또는 상단 벽에 충돌
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

//키보드가 눌리면 총알 발사
void addBullet(int x, int y) {
	Element elem;
	elem.x = x;
	elem.y = y;
	addLast(&bullet, elem); //배열리스트에 아이템 추가
}

//모든 총알 중에서 활성화 된 총알을 그린다.
void drawBullet() {
	ofNoFill();
	for (int i = 0; i < bullet.size; i++) {
		ofCircle(bullet.buf[i].x, bullet.buf[i].y, 6);
	}
}

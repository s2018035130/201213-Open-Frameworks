#ifndef _BULLET_H
#define _BULLET_H

//총알 리스트 초기화 함수
void initBullet();

//총알을 위로 움직이는 함수
void moveBullet();

//키가 눌리면 총알을 리스트에 추가하는 함수
void addBullet(int x, int y);

//오픈프레임웍스를 이용해서 총알을 그려주는 함수
void drawBullet();

#endif
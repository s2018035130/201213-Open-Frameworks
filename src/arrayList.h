#ifndef _ARRAY_LIST_H
#define _ARRAY_LIST_H
//p.192
#define MAX_LIST_SIZE 100

//typedef int Element;
//�Ѿ��� x,y��ǥ�� ��� �ֱ� ������ ����ü ���
typedef struct {
	int x;
	int y;
} Element;

typedef struct {
	Element buf[MAX_LIST_SIZE];
	int size;
} ArrayList;

void init(ArrayList *list);                  
bool isEmpty(const ArrayList *list);         
bool isFull(const ArrayList *list);         
											
bool isInList(const ArrayList *list, Element elem);    
													   
													   
void addLast(ArrayList *list, Element elem);  
											   
void remove(ArrayList *list, Element elem);   

#endif

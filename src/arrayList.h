#ifndef _ARRAY_LIST_H
#define _ARRAY_LIST_H
//p.192
#define MAX_LIST_SIZE 100

//typedef int Element;
//총알은 x,y좌표를 담고 있기 때문에 구조체 사용
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

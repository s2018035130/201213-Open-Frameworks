#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "arrayList.h"
//구조체 비교연산자 사용번거로움 -> 매크로 선언
#define IS_EQUAL(a, b) ( (a.x == b.x) && (a.y == b.y) )


void init(ArrayList *list) {
	list->size = 0;
}

bool isEmpty(const ArrayList *list) {
	return (list->size == 0);
}

bool isFull(const ArrayList *list) {
	return (list->size == MAX_LIST_SIZE);
}

bool isInList(const ArrayList *list, Element elem) {
	for (int i = 0; i < list->size; i++) {
		if (IS_EQUAL(list->buf[i], elem)) return true;
	}
	return false;
}

void addLast(ArrayList *list, Element elem) {
	if (!isFull(list)) {
		list->buf[list->size] = elem;
		list->size++;
	}
	else printf("Error: List Full\n");
}

void remove(ArrayList *list, Element elem) {
	if (!isInList(list, elem)) {
		printf("Error: not exists\n");
		return;
	}
	if (!isEmpty(list)) {
		for (int i = 0; i < list->size; i++) {
			if (IS_EQUAL(list->buf[i], elem)) {
				for (int j = i + 1; j < list->size; j++) {
					list->buf[j - 1] = list->buf[j];
				}
				list->size--;
				return;
			}
		}
	}
	else
		printf("Error: List Empty\n");
}
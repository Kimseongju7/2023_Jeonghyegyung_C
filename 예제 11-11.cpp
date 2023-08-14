#include<stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996) //scnaf 사용 시 오류 예방
int* myAlloc(int);
void dataInput(int*, int);
void dataOutput(int*, int);
void myDelete(int*);
int main()
{
	int* ip;
	int col;
	printf("column 수 입력 : "); //방의 개수
	scanf("%d", &col);
	ip = myAlloc(col);
	//동적 할당 실패 처리 코드
	if (ip == NULL) printf("동적 메모리 할당 실패!\n");
	else {
		dataInput(ip, col); //실패 했을 때 실행하면 런타임 에러
		dataOutput(ip, col);
		myDelete(ip);
	}
	return 0;
}

int* myAlloc(int col) { //방의 개수만큼 동적 메모리 할당해서 리턴
	int* ip;
	ip = (int*)malloc(sizeof(int) * col);
	//20바이트가 할당되면 ip가 볼 때 이 20 바이트는 int형 5개 배열처럼 보임
	return ip; //주소만 보내주면 사용 가능
}

void dataInput(int* ip, int col) {
	int i;
	for (i = 0; i < col; i++) {
		printf("정수 입력 : ");
		scanf("%d", ip + i); //scanf("%d",&ip[i]); //타입, 차원이 맞고 시작주소를 담고 있으니 배열명처럼 사용 가능
	}
	return;
}

void dataOutput(int* ip, int col) {
	int i;
	for (i = 0; i < col; i++) {
		printf("%5d", *(ip + i));
	}
	printf("\n");
	return;
}

void myDelete(int* ip) {
	if (ip != NULL) { //동적 메모리 할당 성공?
		free(ip);
	}
	return;
}
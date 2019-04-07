#include "../代码和头文件/头文件/._LQueue.h"
#include <stdlib.h>
#include<string.h>
#include<stdio.h>

int flag;   //存放输出的类型

void InitLQueue(LQueue *Q){ //初始化
    Q->front = NULL;
    Q->rear = NULL;
    return;
}

void DestoryLQueue(LQueue *Q){  //摧毁队列
	Node *cur, *tmp;
	cur = Q->front;
	while (NULL != cur) {  //依次释放tmp节点
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	free(Q);
}


Status IsEmptyLQueue(const LQueue *Q){   //判断队列是否为空
	if(Q->front == NULL){
		return TRUE;}
	else {
		return FALSE;}
}


Status GetHeadLQueue(LQueue *Q, void *e){  //取出队头元素
	if(Q->front ==NULL){
		return FALSE;}
	memcpy(e, Q->front->data, Q->length);  //复制
	return TRUE;
}


int LengthLQueue(LQueue *Q){   //判断队列的长度
	int length =0;
	Node *p;  //用一个节点p
	p = Q->front;           //p指向队头
    while(p != NULL)  //利用循环，当p到达尾指针时，length为长度
    {
        length++;
        p = p->next;
    }
	return length;
}


Status EnLQueue(LQueue *Q, void *data){  //入队
	Node *p = (Node*)malloc(sizeof(Node));  //建立一个节点
	if(NULL == p)
		return FALSE;
	p->data = (void*)malloc(Q->length);  //为数据域开辟空间
	memcpy(p->data, data, Q->length);  //拷贝
	p->next = NULL;      //指针
	if(Q->front == NULL)Q->front =p;
	if(Q->rear == NULL)Q->rear = p;
	else
	{
        Q->rear->next = p;
        Q->rear = p;
    }
	return TRUE;
}


void ClearLQueue(LQueue *Q) { //清空队列
	Node *cur, *tmp;
	cur = Q->front;
	while (NULL != cur) {  //依次释放tmp节点
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	Q->front = NULL;    //指向空
	Q->rear = NULL;
	return;
}

Status DeLQueue(LQueue *Q){   //出队
	if(Q->front == NULL){
		return FALSE;}
	Node *p;
	p = Q->front;       //指向队头的下一个节点
	Q->front = p->next;   //将队头的指向p的节点
	free(p);
	return TRUE;
}


Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){ //遍历输出队列
    Node* p;
    p = Q->front;  //p指向队头指针指向的节点
		while (p != NULL) {
			foo(p->data);
			p = p->next;
		}
	return TRUE;
}


void LPrint(void *q){
	if (flag == 1)
		printf("%f", *(double *)q);
	if (flag == 2)
		printf("%c", *(char *)q);
	if (flag == 3)
		printf("%d", *(int *)q);
	printf("-<");
}

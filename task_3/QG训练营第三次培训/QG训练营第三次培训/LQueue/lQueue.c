#include "../�����ͷ�ļ�/ͷ�ļ�/._LQueue.h"
#include <stdlib.h>
#include<string.h>
#include<stdio.h>

int flag;   //������������

void InitLQueue(LQueue *Q){ //��ʼ��
    Q->front = NULL;
    Q->rear = NULL;
    return;
}

void DestoryLQueue(LQueue *Q){  //�ݻٶ���
	Node *cur, *tmp;
	cur = Q->front;
	while (NULL != cur) {  //�����ͷ�tmp�ڵ�
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	free(Q);
}


Status IsEmptyLQueue(const LQueue *Q){   //�ж϶����Ƿ�Ϊ��
	if(Q->front == NULL){
		return TRUE;}
	else {
		return FALSE;}
}


Status GetHeadLQueue(LQueue *Q, void *e){  //ȡ����ͷԪ��
	if(Q->front ==NULL){
		return FALSE;}
	memcpy(e, Q->front->data, Q->length);  //����
	return TRUE;
}


int LengthLQueue(LQueue *Q){   //�ж϶��еĳ���
	int length =0;
	Node *p;  //��һ���ڵ�p
	p = Q->front;           //pָ���ͷ
    while(p != NULL)  //����ѭ������p����βָ��ʱ��lengthΪ����
    {
        length++;
        p = p->next;
    }
	return length;
}


Status EnLQueue(LQueue *Q, void *data){  //���
	Node *p = (Node*)malloc(sizeof(Node));  //����һ���ڵ�
	if(NULL == p)
		return FALSE;
	p->data = (void*)malloc(Q->length);  //Ϊ�����򿪱ٿռ�
	memcpy(p->data, data, Q->length);  //����
	p->next = NULL;      //ָ��
	if(Q->front == NULL)Q->front =p;
	if(Q->rear == NULL)Q->rear = p;
	else
	{
        Q->rear->next = p;
        Q->rear = p;
    }
	return TRUE;
}


void ClearLQueue(LQueue *Q) { //��ն���
	Node *cur, *tmp;
	cur = Q->front;
	while (NULL != cur) {  //�����ͷ�tmp�ڵ�
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	Q->front = NULL;    //ָ���
	Q->rear = NULL;
	return;
}

Status DeLQueue(LQueue *Q){   //����
	if(Q->front == NULL){
		return FALSE;}
	Node *p;
	p = Q->front;       //ָ���ͷ����һ���ڵ�
	Q->front = p->next;   //����ͷ��ָ��p�Ľڵ�
	free(p);
	return TRUE;
}


Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){ //�����������
    Node* p;
    p = Q->front;  //pָ���ͷָ��ָ��Ľڵ�
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

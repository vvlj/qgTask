#include "../�����ͷ�ļ�/ͷ�ļ�/._AQueue.h"


void InitAQueue(AQueue *Q){   //��ʼ������
	int i;
	for (i=0; i<MAXQUEUE;i++)      //ʹ��ѭ��Ϊÿһ��data���ٿռ�
		Q->data[i] = (void*)malloc(Q->length);
	Q->front = Q->rear = 0;
}

void DestoryAQueue(AQueue *Q){  //�ݻٶ���
	int i;
	for(i = 0; i<MAXQUEUE; i++)  //��ÿһ��data�Ŀռ��ͷŵ�
		free(Q->data[i]);
	return;
}

Status IsFullAQueue(const AQueue *Q){  //�������Ƿ�����
	if((Q->rear+1) % MAXQUEUE == Q->front){  //��ʽ
		return TRUE;}
	else{
		return FALSE;}
}

Status IsEmptyAQueue(const AQueue *Q){
	if (Q->front == Q->rear){   //ͷָ���βָ�����
		return TRUE;}
	else {
		return FALSE;}
}

Status GetHeadAQueue(AQueue *Q, void *e){ //�鿴��ͷԪ��
	if (Q->front == Q->rear){   //�ж��Ƿ�Ϊ��
		return FALSE;}
	int i = Q->front;
	i = (i + 1) % MAXQUEUE;
	memcpy(e, Q->data[i], Q->length);
	return TRUE;
}


int LengthAQueue(AQueue *Q){    //ȷ�����г���
	int k;
	k = (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;  //��ʽ
	return (k);
}

Status EnAQueue(AQueue *Q, void *data){  //��Ӳ���
	if ((Q->rear+1) % MAXQUEUE == Q->front){
		return FALSE;
	}
	else{
		Q->rear = (Q->rear + 1) % MAXQUEUE;
		memcpy(Q->data[Q->rear], data, Q->length);  //����
		return TRUE;
	}
}

Status DeAQueue(AQueue *Q){   //���Ӳ���
	if(Q->front == Q->rear){
		return FALSE;
	}
	else{
		Q->front = (Q->front + 1) % MAXQUEUE;  //ͷָ��ָ����һ����Ԫ��
		return TRUE;
	}
}

void ClearAQueue(AQueue *Q){   //��ն���
	if(Q->front == Q->rear){
		return ;}
	Q->front = 0;
	Q->rear = 0;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){  //������������
	int i =0,index =Q->front+1,length =LengthAQueue(Q);
	while (i++<length) {  //���indexû�б�������β
		foo(Q->data[index]);
		index = (index + 1) % MAXQUEUE;
	}
	printf("\n");
	return TRUE;
}

void APrint(void *q){  //�� ӡ����
	if (flag == 1)
		printf("%lf", *(double *)q);
	else if (flag == 2)
		printf("%c", *(char *)q);
	else if (flag == 3)
		printf("%d", *(int *)q);
	printf("-<");
}

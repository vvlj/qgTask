#include "../代码和头文件/头文件/._AQueue.h"


void InitAQueue(AQueue *Q){   //初始化队列
	int i;
	for (i=0; i<MAXQUEUE;i++)      //使用循环为每一个data开辟空间
		Q->data[i] = (void*)malloc(Q->length);
	Q->front = Q->rear = 0;
}

void DestoryAQueue(AQueue *Q){  //摧毁队列
	int i;
	for(i = 0; i<MAXQUEUE; i++)  //将每一个data的空间释放掉
		free(Q->data[i]);
	return;
}

Status IsFullAQueue(const AQueue *Q){  //检查队列是否已满
	if((Q->rear+1) % MAXQUEUE == Q->front){  //公式
		return TRUE;}
	else{
		return FALSE;}
}

Status IsEmptyAQueue(const AQueue *Q){
	if (Q->front == Q->rear){   //头指针和尾指针相等
		return TRUE;}
	else {
		return FALSE;}
}

Status GetHeadAQueue(AQueue *Q, void *e){ //查看队头元素
	if (Q->front == Q->rear){   //判断是否为空
		return FALSE;}
	int i = Q->front;
	i = (i + 1) % MAXQUEUE;
	memcpy(e, Q->data[i], Q->length);
	return TRUE;
}


int LengthAQueue(AQueue *Q){    //确定队列长度
	int k;
	k = (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE;  //公式
	return (k);
}

Status EnAQueue(AQueue *Q, void *data){  //入队操作
	if ((Q->rear+1) % MAXQUEUE == Q->front){
		return FALSE;
	}
	else{
		Q->rear = (Q->rear + 1) % MAXQUEUE;
		memcpy(Q->data[Q->rear], data, Q->length);  //拷贝
		return TRUE;
	}
}

Status DeAQueue(AQueue *Q){   //出队操作
	if(Q->front == Q->rear){
		return FALSE;
	}
	else{
		Q->front = (Q->front + 1) % MAXQUEUE;  //头指针指向下一个队元素
		return TRUE;
	}
}

void ClearAQueue(AQueue *Q){   //清空队列
	if(Q->front == Q->rear){
		return ;}
	Q->front = 0;
	Q->rear = 0;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){  //遍历函数操作
	int i =0,index =Q->front+1,length =LengthAQueue(Q);
	while (i++<length) {  //如果index没有遍历到队尾
		foo(Q->data[index]);
		index = (index + 1) % MAXQUEUE;
	}
	printf("\n");
	return TRUE;
}

void APrint(void *q){  //打 印队列
	if (flag == 1)
		printf("%lf", *(double *)q);
	else if (flag == 2)
		printf("%c", *(char *)q);
	else if (flag == 3)
		printf("%d", *(int *)q);
	printf("-<");
}

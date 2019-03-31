#include "..\head\LinkStack.h"
#include <stdlib.h>
#include <stdio.h>


//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
    if(NULL ==s)return ERROR;
    s->top =NULL;
    s->count =0;
    return SUCCESS;
}
Status isEmptyLStack(LinkStack *s)  //�ж���ջ�Ƿ�Ϊ��
{
    if(NULL ==s || s->count !=0 )return ERROR;
    return SUCCESS;
}
Status getTopLStack(LinkStack *s,ElemType *e)  //�õ�ջ��Ԫ��
{
    if(NULL ==s || isEmptyLStack(s))return ERROR;
    *e =s->top->data;
    return SUCCESS;
}
Status clearLStack(LinkStack *s)   //���ջ
{
    if(NULL ==s || isEmptyLStack(s))return ERROR;
    LinkStackPtr nextNode;      //������һ���ڵ�
    while(s->top != NULL)
    {
        nextNode =s->top->next;  //ѭ������Ľڵ�
        free(s->top);
        s->count--;
        s->top = nextNode;
    }
    return SUCCESS;
}
Status destroyLStack(LinkStack *s)   //����ջ
{
    if(NULL ==s)return ERROR;
    LinkStackPtr nextNode;      //������һ���ڵ�
    while(s->top != NULL)
    {
        nextNode =s->top->next;  //ѭ������Ľڵ�
        free(s->top);
        s->count--;
        s->top = nextNode;
    }
    free(s);        //ͷҲ�ͷŵ�
    return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length)    //���ջ����
{
    *length =s->count;
}
Status pushLStack(LinkStack *s,ElemType data)   //��ջ
{
    if(NULL ==s)return ERROR;
    LinkStackPtr newNodeHead;
    newNodeHead =(LinkStackPtr)malloc(sizeof(StackNode));   //���½ڵ�����ڴ�
    if(NULL ==newNodeHead)return ERROR;
    newNodeHead->data = data;
    newNodeHead->next = s->top; //�½ڵ�nextͷ
    s->top = newNodeHead;   //ͷnext�½ڵ�
    s->count++;
    return SUCCESS;
}
Status popLStack(LinkStack *s,ElemType *data)   //��ջ
{
    if(NULL ==s || isEmptyLStack(s))return ERROR;
    LinkStackPtr curNodeHead;   //Ҫ���ٵĽڵ�
    curNodeHead =s->top;
    s->top = curNodeHead->next; //ͷָ����һλ
    *data = curNodeHead->data;
    s->count--;
    free(curNodeHead);
    return SUCCESS;
}


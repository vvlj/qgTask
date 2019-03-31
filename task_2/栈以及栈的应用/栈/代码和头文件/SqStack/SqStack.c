#include "..\head\SqStack.h"
#include <stdlib.h>
#include <stdio.h>
//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ��ջ
{
    s->elem = (ElemType*)malloc(sizes*sizeof(ElemType)); //����������ڴ�
    if (s->elem == NULL)return ERROR;   //�����ڴ�֮��һ��Ҫ�ж�
    s->top = -1;
    s->size = sizes;
    return SUCCESS;
}
Status isEmptyStack(SqStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
    if(s == NULL || s->top != -1)return ERROR;
    return SUCCESS;
}
Status getTopStack(SqStack *s,ElemType *e)   //�õ�ջ��Ԫ��
{
    if(NULL ==s || isEmptyStack(s))return ERROR;
    *e = s->elem[s->top];
    return SUCCESS;
}
Status clearStack(SqStack *s)   //���ջ
{
    if(NULL == s)return ERROR;
    if(!isEmptyStack(s))s->top = -1;
    return SUCCESS;
}
Status destroyStack(SqStack *s)  //����ջ
{
    if(NULL == s)return ERROR;
    free(s->elem);
    free(s);
    return SUCCESS;
}
Status stackLength(SqStack *s,int *length)   //���ջ����
{
    if(NULL == s)return ERROR;
    *length = s->top+1;
    return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data)  //��ջ
{
    if(NULL == s || s->top == s->size - 1)
        return ERROR;
    s->top++;
    s->elem[s->top] = data;
    return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data)   //��ջ
{
    if(NULL ==s || isEmptyStack(s))
        return ERROR;
    *data = s->elem[s->top];
    s->top--;
    return SUCCESS;
}





#include "..\head\SqStack.h"
#include <stdlib.h>
#include <stdio.h>
//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化栈
{
    s->elem = (ElemType*)malloc(sizes*sizeof(ElemType)); //给数组分配内存
    if (s->elem == NULL)return ERROR;   //分配内存之后一般要判断
    s->top = -1;
    s->size = sizes;
    return SUCCESS;
}
Status isEmptyStack(SqStack *s)   //判断栈是否为空
{
    if(s == NULL || s->top != -1)return ERROR;
    return SUCCESS;
}
Status getTopStack(SqStack *s,ElemType *e)   //得到栈顶元素
{
    if(NULL ==s || isEmptyStack(s))return ERROR;
    *e = s->elem[s->top];
    return SUCCESS;
}
Status clearStack(SqStack *s)   //清空栈
{
    if(NULL == s)return ERROR;
    if(!isEmptyStack(s))s->top = -1;
    return SUCCESS;
}
Status destroyStack(SqStack *s)  //销毁栈
{
    if(NULL == s)return ERROR;
    free(s->elem);
    free(s);
    return SUCCESS;
}
Status stackLength(SqStack *s,int *length)   //检测栈长度
{
    if(NULL == s)return ERROR;
    *length = s->top+1;
    return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data)  //入栈
{
    if(NULL == s || s->top == s->size - 1)
        return ERROR;
    s->top++;
    s->elem[s->top] = data;
    return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data)   //出栈
{
    if(NULL ==s || isEmptyStack(s))
        return ERROR;
    *data = s->elem[s->top];
    s->top--;
    return SUCCESS;
}





#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
LinkStack *stack;   //intջ
int pHase[50];  //���ȼ�hash��

Status infixToPostfix(char *strs,float *p);  //��׺ת��׺
char *getNum(char *strs,float *num);   //�õ�����
Status cal(float *p,float *val);    //�����׺���ʽ
void showPromt();   //��ʾ��
void showPostfix(float *p); //�����׺���ʽ

int main()
{
    stack =(LinkStack*)malloc(sizeof(LinkStack));
    initLStack(stack);
    pHase['+'] =  pHase['-'] = 1;
    pHase['*'] =  pHase['/'] = 2;
    char infix[100];    //��׺
    char *strs=infix;
    float postfix[100];    //��׺
    float *p= postfix;
    showPromt();
    while(SUCCESS)
    {
        printf("��������ȷ����׺���ʽ��\n");
        gets(strs);
        if(*strs =='e')break;
        if(*strs =='c')
        {
            system("CLS");
            showPromt();
        }
        printf("\n");
        if(!infixToPostfix(strs,p))continue;   //����һЩ��ĸʲô��
        float rst;
        if(cal(postfix,&rst))   //���ֶ�����������2**2
        {
            showPostfix(postfix);
            printf("   �����:%f\n",rst);
        }
    }
    return 0;
}

Status infixToPostfix(char* strs,float *p)
{
    float tmp; //���������������������
    Status sign =ERROR;    //SUCCESS:-ǰ������ ERROR:-ǰ�������
    while(*strs != '\0')
    {
        if(*strs ==' ') //�ո�����
        {
            strs++;
            continue;
        }
        if((sign == ERROR && *strs=='-') || (*strs>='0'&&*strs<='9')) //����
        {
            strs =getNum(strs,&tmp);
            *p++ = tmp;    //�����׺���ʽ
            sign =SUCCESS;
        }
        else if(*strs=='(') //�����ţ�
            pushLStack(stack,*strs); //��ջ
        else if(*strs==')')    //������
        {
            while(SUCCESS)
            {
                popLStack(stack,&tmp);
                if(tmp=='(')break;
                *p++ =tmp;    //�����׺���ʽ
            }
        }
        else if(*strs=='+'|| (sign == SUCCESS && *strs=='-')||*strs=='*'||*strs=='/')
        {
            while(SUCCESS)  //���������ջֱ��ջ������������ȼ�С�ڵ�ǰ����������ȼ�
            {
                if(!getTopLStack(stack,&tmp) || pHase[(int)(*strs)] > pHase[(int)(tmp)])break;
                popLStack(stack,&tmp);
                *p++ =tmp;  //�����׺���ʽ
            }
            pushLStack(stack,*strs);
            sign =ERROR;
        }
        else{return ERROR;}
        strs++;
    }
    while(!isEmptyLStack(stack))    //��ջ��ʣ��Ԫ����ջ��
    {
        popLStack(stack,&tmp);
        *p++=tmp;
    }
    *p ='\0';
    return SUCCESS;
}

char *getNum(char *strs,float *num)
{
    char tmpStrs[100];   //��ʱ����ַ���
    char *p =tmpStrs;
    do{
        *p++ =*strs;
        strs++;
    }while(*strs !='\0' && ((*strs >= '0' && *strs <= '9') ||*strs=='.'));
    *num=atof(tmpStrs); //���ַ���ת�ɸ���
    return --strs;  //��Ҫ--
}

Status cal(float *p,float *val)
{
    float left=0,right=0,rst;
    Status tmp()  //����������
    {
        if(popLStack(stack,&right)&&popLStack(stack,&left))
            return SUCCESS;
        return ERROR;
    }
    while(*p != '\0')
    {
        if(*p =='+')
        {
            if(!tmp())return ERROR;
            rst =left+right;
        }
        else if(*p =='-')
        {
            if(!tmp())return ERROR;
            rst =left-right;
        }
        else if(*p =='*')
        {
            if(!tmp())return ERROR;
            rst =left*right;
        }
        else if(*p =='/')
        {
            if(!tmp())return ERROR;
            rst =left/right;
        }
        else{rst =*p;}
        pushLStack(stack,rst);
        p++;
    }
    if(popLStack(stack,&rst) &&isEmptyLStack(stack))    //�պ�Ϊ�������ȷ
    {
        *val =rst;
        return SUCCESS;
    }
    return ERROR;
}
void showPromt()
{
    printf("                 \n");
    printf("*****************\n");
    printf("     �����������\n");
    printf("        ����e�˳�\n");
    printf("        ����c����\n");
    printf("*****************\n");
}

void showPostfix(float *p) //�����׺���ʽ
{
    printf("��׺���ʽ�ǣ�");
    while(*p !='\0')
    {
        if(*p=='+' || *p=='-' || *p=='*' || *p=='/')
            printf("%c",(int)(*p));
        else{printf("(%.2f)",*p);}
        p++;
    }
    printf("\n");
}

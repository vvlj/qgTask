#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
LinkStack *stack;   //int栈
int pHase[50];  //优先级hash表

Status infixToPostfix(char *strs,float *p);  //中缀转后缀
char *getNum(char *strs,float *num);   //得到数字
Status cal(float *p,float *val);    //计算后缀表达式
void showPromt();   //提示语
void showPostfix(float *p); //输出后缀表达式

int main()
{
    stack =(LinkStack*)malloc(sizeof(LinkStack));
    initLStack(stack);
    pHase['+'] =  pHase['-'] = 1;
    pHase['*'] =  pHase['/'] = 2;
    char infix[100];    //中缀
    char *strs=infix;
    float postfix[100];    //后缀
    float *p= postfix;
    showPromt();
    while(SUCCESS)
    {
        printf("请输入正确的中缀表达式：\n");
        gets(strs);
        if(*strs =='e')break;
        if(*strs =='c')
        {
            system("CLS");
            showPromt();
        }
        printf("\n");
        if(!infixToPostfix(strs,p))continue;   //出现一些字母什么的
        float rst;
        if(cal(postfix,&rst))   //出现多个运算符比如2**2
        {
            showPostfix(postfix);
            printf("   结果是:%f\n",rst);
        }
    }
    return 0;
}

Status infixToPostfix(char* strs,float *p)
{
    float tmp; //存放括号里面的四则运算符
    Status sign =ERROR;    //SUCCESS:-前是数字 ERROR:-前是运算符
    while(*strs != '\0')
    {
        if(*strs ==' ') //空格的情况
        {
            strs++;
            continue;
        }
        if((sign == ERROR && *strs=='-') || (*strs>='0'&&*strs<='9')) //数字
        {
            strs =getNum(strs,&tmp);
            *p++ = tmp;    //加入后缀表达式
            sign =SUCCESS;
        }
        else if(*strs=='(') //左括号，
            pushLStack(stack,*strs); //入栈
        else if(*strs==')')    //右括号
        {
            while(SUCCESS)
            {
                popLStack(stack,&tmp);
                if(tmp=='(')break;
                *p++ =tmp;    //加入后缀表达式
            }
        }
        else if(*strs=='+'|| (sign == SUCCESS && *strs=='-')||*strs=='*'||*strs=='/')
        {
            while(SUCCESS)  //运算符，出栈直到栈顶运算符的优先级小于当前运算符的优先级
            {
                if(!getTopLStack(stack,&tmp) || pHase[(int)(*strs)] > pHase[(int)(tmp)])break;
                popLStack(stack,&tmp);
                *p++ =tmp;  //加入后缀表达式
            }
            pushLStack(stack,*strs);
            sign =ERROR;
        }
        else{return ERROR;}
        strs++;
    }
    while(!isEmptyLStack(stack))    //将栈中剩余元素入栈！
    {
        popLStack(stack,&tmp);
        *p++=tmp;
    }
    *p ='\0';
    return SUCCESS;
}

char *getNum(char *strs,float *num)
{
    char tmpStrs[100];   //临时存放字符串
    char *p =tmpStrs;
    do{
        *p++ =*strs;
        strs++;
    }while(*strs !='\0' && ((*strs >= '0' && *strs <= '9') ||*strs=='.'));
    *num=atof(tmpStrs); //讲字符串转成浮点
    return --strs;  //需要--
}

Status cal(float *p,float *val)
{
    float left=0,right=0,rst;
    Status tmp()  //弹出来计算
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
    if(popLStack(stack,&rst) &&isEmptyLStack(stack))    //刚好为结果才正确
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
    printf("     四则运算测试\n");
    printf("        输入e退出\n");
    printf("        输入c清屏\n");
    printf("*****************\n");
}

void showPostfix(float *p) //输出后缀表达式
{
    printf("后缀表达式是：");
    while(*p !='\0')
    {
        if(*p=='+' || *p=='-' || *p=='*' || *p=='/')
            printf("%c",(int)(*p));
        else{printf("(%.2f)",*p);}
        p++;
    }
    printf("\n");
}

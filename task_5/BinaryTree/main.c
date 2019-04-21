#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

void showTable();
void test();
int getDigit(); //获取数字
void clr();
Status ifInit(int destroyStatus);   //是否初始化
Status print(TElemType e);   //输出函数

int main()
{
    test();
    return 0;
}


void showTable()
{
    printf("                          \n");
    printf("                          \n");
    printf("选择测试功能\n");
    printf("        选项1：构造空二叉树T\n");
    printf("        选项2：摧毁二叉树T\n");
    printf("        选项3：构造二叉树T\n");
    printf("        选项4：先序遍历二叉树T\n");
    printf("        选项5：中序遍历二叉树T\n");
    printf("        选项6：后序遍历二叉树T\n");
    printf("        选项7：层序遍历二叉树T\n");
    printf("        选项8：对构造出的前缀表达式二叉树求值\n");
    printf("        选项0退出\n");
    printf("        #号代表空孩子\n");
    printf("***************************\n");
}

void test()
{
    BiTree *t = (BiTree*)malloc(sizeof(BiTree));
    char definition[100];

    int num =1,status = 1;                                       //选择功能、摧毁标
    while(num)
    {
        showTable();
        if(!status)
        {
            printf("前序遍历  ：");
            PreOrderTraverse(*t,print);
            printf("\n");
            printf("中序序遍历：");
            InOrderTraverse(*t,print);
            printf("\n");
            printf("后序遍历  ：");
            PostOrderTraverse(*t,print);
            printf("\n");
            printf("层次遍历  ：");
            LevelOrderTraverse(*t,print);
            printf("\n***************************\n");
        }
        num =getDigit();
        switch(num)
        {
            case 1:
            {
                if(status)
                {
                    if(InitBiTree(t))
                    {
                        printf("初始化成功\n");
                        status = 0;
                    }
                    else{printf("初始化失败\n");}
                }
                break;
            }
            case 2:
                if(ifInit(status))
                {
                    if((DestroyBiTree(t)))
                    {
                        printf("摧毁成功\n");
                        status = 1;
                    }
                    else{printf("摧毁失败\n");}
                }
                break;
            case 3:
                if(ifInit(status))
                {
                    gets(definition);
                    if((CreateBiTree(t,definition)))
                    {
                        printf("种树成功\n");
                    }
                    else{printf("种树成功\n");}
                }
                break;
            case 4:
                if(ifInit(status))
                {
                    PreOrderTraverse(*t,print);
                }
                break;
            case 5:
                if(ifInit(status))
                {
                    InOrderTraverse(*t,print);
                }
                break;
            case 6:
                if(ifInit(status))
                {
                    PostOrderTraverse(*t,print);
                }
                break;
            case 7:
                if(ifInit(status))
                {
                    LevelOrderTraverse(*t,print);
                }
                break;
            case 8:
                if(ifInit(status))
                {
                    int val =  Value(*t);
                    printf("结果是：%d\n",val);
                }
                break;
        }
        clr();

    }
}


int getDigit()
{
    char num[20];
    gets(num);
    return atoi(num);   //异常返回0
}


void clr()
{
    printf("按回车返回:");
    getchar();
    system("CLS");
}

Status ifInit(int destroyStatus)
{
    if(destroyStatus){
        printf("        未初始化\n");
        return ERROR;
    }
    return SUCCESS;
}

Status print(TElemType e)
{
    printf("%c ",e);
    return SUCCESS;
}


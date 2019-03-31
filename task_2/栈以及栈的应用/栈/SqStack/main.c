#include <stdio.h>
#include <stdlib.h>
#include "../代码和头文件/head/SqStack.h"
void showSqStackTable();    //界面显示函数
void SqStackTest();
Status ifInit(int destroyStatus);
void showStack(SqStack *s); //实时显示栈
int main()
{
    SqStackTest();
    return 0;
}

void showSqStackTable()
{
    printf("                          \n");
    printf("                          \n");
    printf("选择测试单链表功能\n");
    printf("        选项1：初始化\n");
    printf("        选项2：摧毁\n");
    printf("        选项3：压入\n");
    printf("        选项4：弹出\n");
    printf("        选项5：清空\n");
    printf("        选项6：判断栈是否为空\n");
    printf("        选项7：得到栈顶元素\n");
    printf("        选项8：检测栈长度\n");
    printf("        选项0:退出\n");
    printf("***************************\n");

}

void SqStackTest()
{
    int num,destroyStatus =1;                                       //选择功能、摧毁标志
    SqStack *test;
    ElemType *e =(ElemType*)malloc(sizeof(ElemType));   //存储节点值
    while(num)
    {
        showSqStackTable();
        if(!destroyStatus)showStack(test);
        while(1)
        {
            num =getchar();
            num -='0';
            if(num >-1 && num <10){
                getchar();
                break;
            }
        }
        switch(num)
        {
            case 1:{
                if(destroyStatus){
                    test = (SqStack*)malloc(sizeof(SqStack));            //分配内存
                    char strs[10];
                    int sizes;
                    while(1){
                        printf("输入一个非负整数:\n");
                        gets(strs);
                        sizes = atoi(strs);
                        if(sizes > 0)break;
                    }
                    if(initStack(test,sizes))
                    {
                        printf("    初始化成功\n");
                        destroyStatus =0;
                    }
                }
                break;
            }
            case 2:
                if(ifInit(destroyStatus))
                {
                    if(destroyStack(test)){
                        printf("    摧毁成功\n");
                        destroyStatus =1;
                    }
                    else{printf("    摧毁失败\n");}
                }
                break;
            case 3:
                if(ifInit(destroyStatus))
                {
                    printf("    输入一个值压入\n");
                    scanf("%d",e);

                    if(pushStack(test,*e))printf("    压入成功\n");
                    else{printf("    压入失败\n");}
                }
                break;
            case 4:
                if(ifInit(destroyStatus))
                {
                    if(popStack(test,e))printf("    弹出%d\n",*e);
                    else{printf("    弹出失败\n");}
                }
                break;
            case 5:
                if(ifInit(destroyStatus))
                {
                    if(clearStack(test))printf("    清空成功\n");
                    else{printf("    清空失败\n");}
                }
                break;
            case 6:
                if(ifInit(destroyStatus))
                {
                    if(isEmptyStack(test))printf("    栈为空\n");
                    else{printf("    栈为空不为空\n");}
                }
                break;
            case 7:
                if(ifInit(destroyStatus))
                {
                    if(getTopStack(test,e)){
                        printf("    该元素是%d\n",*e);
                    }
                    else{printf("    得到失败\n");}
                }
                break;
            case 8:
                if(ifInit(destroyStatus))
                {
                    int *length =(int*)malloc(sizeof(int));
                    if(stackLength(test,length))printf("    改栈长度%d\n",*length);
                    else{printf("    摧毁失败\n");}
                }
                break;
        }
        printf("按回车返回:");
        getchar();
        system("CLS");
    }
}

Status ifInit(int destroyStatus)
{
    if(destroyStatus){
        printf("        未初始化\n");
        return ERROR;
    }
    return SUCCESS;
}

void showStack(SqStack *s){
    for(int i = 0;i <= s->top;i++)
        printf("%d ",s->elem[i]);
    printf("\n***************************\n");
}

#include <stdio.h>
#include <stdlib.h>
#include "../�����ͷ�ļ�/head/SqStack.h"
void showSqStackTable();    //������ʾ����
void SqStackTest();
Status ifInit(int destroyStatus);
void showStack(SqStack *s); //ʵʱ��ʾջ
int main()
{
    SqStackTest();
    return 0;
}

void showSqStackTable()
{
    printf("                          \n");
    printf("                          \n");
    printf("ѡ����Ե�������\n");
    printf("        ѡ��1����ʼ��\n");
    printf("        ѡ��2���ݻ�\n");
    printf("        ѡ��3��ѹ��\n");
    printf("        ѡ��4������\n");
    printf("        ѡ��5�����\n");
    printf("        ѡ��6���ж�ջ�Ƿ�Ϊ��\n");
    printf("        ѡ��7���õ�ջ��Ԫ��\n");
    printf("        ѡ��8�����ջ����\n");
    printf("        ѡ��0:�˳�\n");
    printf("***************************\n");

}

void SqStackTest()
{
    int num,destroyStatus =1;                                       //ѡ���ܡ��ݻٱ�־
    SqStack *test;
    ElemType *e =(ElemType*)malloc(sizeof(ElemType));   //�洢�ڵ�ֵ
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
                    test = (SqStack*)malloc(sizeof(SqStack));            //�����ڴ�
                    char strs[10];
                    int sizes;
                    while(1){
                        printf("����һ���Ǹ�����:\n");
                        gets(strs);
                        sizes = atoi(strs);
                        if(sizes > 0)break;
                    }
                    if(initStack(test,sizes))
                    {
                        printf("    ��ʼ���ɹ�\n");
                        destroyStatus =0;
                    }
                }
                break;
            }
            case 2:
                if(ifInit(destroyStatus))
                {
                    if(destroyStack(test)){
                        printf("    �ݻٳɹ�\n");
                        destroyStatus =1;
                    }
                    else{printf("    �ݻ�ʧ��\n");}
                }
                break;
            case 3:
                if(ifInit(destroyStatus))
                {
                    printf("    ����һ��ֵѹ��\n");
                    scanf("%d",e);

                    if(pushStack(test,*e))printf("    ѹ��ɹ�\n");
                    else{printf("    ѹ��ʧ��\n");}
                }
                break;
            case 4:
                if(ifInit(destroyStatus))
                {
                    if(popStack(test,e))printf("    ����%d\n",*e);
                    else{printf("    ����ʧ��\n");}
                }
                break;
            case 5:
                if(ifInit(destroyStatus))
                {
                    if(clearStack(test))printf("    ��ճɹ�\n");
                    else{printf("    ���ʧ��\n");}
                }
                break;
            case 6:
                if(ifInit(destroyStatus))
                {
                    if(isEmptyStack(test))printf("    ջΪ��\n");
                    else{printf("    ջΪ�ղ�Ϊ��\n");}
                }
                break;
            case 7:
                if(ifInit(destroyStatus))
                {
                    if(getTopStack(test,e)){
                        printf("    ��Ԫ����%d\n",*e);
                    }
                    else{printf("    �õ�ʧ��\n");}
                }
                break;
            case 8:
                if(ifInit(destroyStatus))
                {
                    int *length =(int*)malloc(sizeof(int));
                    if(stackLength(test,length))printf("    ��ջ����%d\n",*length);
                    else{printf("    �ݻ�ʧ��\n");}
                }
                break;
        }
        printf("���س�����:");
        getchar();
        system("CLS");
    }
}

Status ifInit(int destroyStatus)
{
    if(destroyStatus){
        printf("        δ��ʼ��\n");
        return ERROR;
    }
    return SUCCESS;
}

void showStack(SqStack *s){
    for(int i = 0;i <= s->top;i++)
        printf("%d ",s->elem[i]);
    printf("\n***************************\n");
}

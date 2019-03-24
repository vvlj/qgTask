#include <stdio.h>
#include "../�����ͷ�ļ�/head/duLinkedList.h"

void showDuLLinkedListTable();           //��ʾ���Թ���ѡ��
void DuLLinkedListTest();               //���Թ��ܺ���
void printNodeValue(ElemType e);        //�ڵ�ֵ�������
Status ifInit(int destroyStatus);       //�Ƿ��ʼ������
int main()
{
    DuLLinkedListTest();
    return 0;
}
void showDuLLinkedListTable()
{
    printf("                          \n");
    printf("                          \n");
    printf("ѡ�����˫��������\n");
    printf("        ѡ��1����ʼ��\n");
    printf("        ѡ��2���ݻ�\n");
    printf("        ѡ��3��ǰ��\n");
    printf("        ѡ��4�����\n");
    printf("        ѡ��5��ɾ��\n");
    printf("        ѡ��6������\n");
    printf("        ѡ��0:�˳�\n");
    printf("***************************\n");
}
void DuLLinkedListTest()
{
    int num,destroyStatus =1;                                           //ѡ���ܡ��ݻٱ�־
    DuLinkedList *testList;
    testList = (DuLinkedList*)malloc(sizeof(DuLinkedList));            //��ָ��ṹ��ָ���ָ������ڴ�
    while(num)
    {
        showDuLLinkedListTable();
        if(!destroyStatus){
            TraverseList_DuL(*testList,printNodeValue);
            printf("***************************\n");
        }
        scanf("%d",&num);
        switch(num){
            case 1:
                if(destroyStatus){
                    if(InitList_DuL(testList)){
                        printf("        ���������ʼ���ɹ�\n");
                        destroyStatus =0;
                    }
                    else{printf("        ���������ʼ��ʧ��\n");}
                }
                else{printf("        ���������ѳ�ʼ��\n");}
                break;
            case 2:
                if(ifInit(destroyStatus)){
                    DestroyList_DuL(testList);
                    destroyStatus=1;
                    printf("        ��������ݻٳɹ�\n");
                }
                break;
            case 3:
                if(ifInit(destroyStatus)){
                    printf("        ������һ��ֵ���뵽ͷ�ڵ�ǰһ���ڵ�:\n");
                    DuLNode *q =(DuLinkedList)malloc(sizeof(DuLNode));
                    scanf("%d",&q->data);
                    if(InsertBeforeList_DuL(*testList,q))
                        printf("        ����%d�ɹ�\n",q->data);
                    else{printf("        ����%dʧ��\n",q->data);}
                }
                break;
            case 4:
                if(ifInit(destroyStatus)){
                    printf("        ������һ��ֵ���뵽ͷ�ڵ��һ���ڵ�:\n");
                    DuLNode *q =(DuLinkedList)malloc(sizeof(DuLNode));
                    scanf("%d",&q->data);
                    if(InsertAfterList_DuL(*testList,q))
                        printf("        ����%d�ɹ�\n",q->data);
                    else{printf("        ����%dʧ��\n",q->data);}
                }
                break;
            case 5:
                if(ifInit(destroyStatus)){
                    printf("        ɾ���ڵ��һ���ڵ㲢��ֵ��e\n");
                    ElemType *e =(ElemType*)malloc(sizeof(ElemType));
                    if(DeleteList_DuL(*testList,e))
                        printf("        �ɹ�");
                    else{printf("        ʧ��");}
                    }
                break;
            case 6:
                if(ifInit(destroyStatus)){
                    printf("        �������ÿ���ڵ��ֵ\n");
                    TraverseList_DuL(*testList,printNodeValue);
                }
                break;
        }
        printf("���س�����:");
        getchar();
        getchar();
        system("CLS");
    }
}
void printNodeValue(ElemType e)
{
    printf("%d - ",e);
}

Status ifInit(int destroyStatus)
{
    if(destroyStatus){
        printf("        ��������δ��ʼ��\n");
        return ERROR;
    }
    return SUCCESS;
}

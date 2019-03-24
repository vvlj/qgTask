#include <stdio.h>
#include "../代码和头文件/head/duLinkedList.h"

void showDuLLinkedListTable();           //显示测试功能选项
void DuLLinkedListTest();               //测试功能函数
void printNodeValue(ElemType e);        //节点值输出函数
Status ifInit(int destroyStatus);       //是否初始化函数
int main()
{
    DuLLinkedListTest();
    return 0;
}
void showDuLLinkedListTable()
{
    printf("                          \n");
    printf("                          \n");
    printf("选择测试双向链表功能\n");
    printf("        选项1：初始化\n");
    printf("        选项2：摧毁\n");
    printf("        选项3：前插\n");
    printf("        选项4：后插\n");
    printf("        选项5：删除\n");
    printf("        选项6：遍历\n");
    printf("        选项0:退出\n");
    printf("***************************\n");
}
void DuLLinkedListTest()
{
    int num,destroyStatus =1;                                           //选择功能、摧毁标志
    DuLinkedList *testList;
    testList = (DuLinkedList*)malloc(sizeof(DuLinkedList));            //给指向结构体指针的指针分配内存
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
                        printf("        测试链表初始化成功\n");
                        destroyStatus =0;
                    }
                    else{printf("        测试链表初始化失败\n");}
                }
                else{printf("        测试链表已初始化\n");}
                break;
            case 2:
                if(ifInit(destroyStatus)){
                    DestroyList_DuL(testList);
                    destroyStatus=1;
                    printf("        测试链表摧毁成功\n");
                }
                break;
            case 3:
                if(ifInit(destroyStatus)){
                    printf("        请输入一个值插入到头节点前一个节点:\n");
                    DuLNode *q =(DuLinkedList)malloc(sizeof(DuLNode));
                    scanf("%d",&q->data);
                    if(InsertBeforeList_DuL(*testList,q))
                        printf("        插入%d成功\n",q->data);
                    else{printf("        插入%d失败\n",q->data);}
                }
                break;
            case 4:
                if(ifInit(destroyStatus)){
                    printf("        请输入一个值插入到头节点后一个节点:\n");
                    DuLNode *q =(DuLinkedList)malloc(sizeof(DuLNode));
                    scanf("%d",&q->data);
                    if(InsertAfterList_DuL(*testList,q))
                        printf("        插入%d成功\n",q->data);
                    else{printf("        插入%d失败\n",q->data);}
                }
                break;
            case 5:
                if(ifInit(destroyStatus)){
                    printf("        删除节点后一个节点并赋值给e\n");
                    ElemType *e =(ElemType*)malloc(sizeof(ElemType));
                    if(DeleteList_DuL(*testList,e))
                        printf("        成功");
                    else{printf("        失败");}
                    }
                break;
            case 6:
                if(ifInit(destroyStatus)){
                    printf("        遍历输出每个节点的值\n");
                    TraverseList_DuL(*testList,printNodeValue);
                }
                break;
        }
        printf("按回车返回:");
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
        printf("        测试链表未初始化\n");
        return ERROR;
    }
    return SUCCESS;
}

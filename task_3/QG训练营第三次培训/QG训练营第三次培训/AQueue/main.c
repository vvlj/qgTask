#include "../�����ͷ�ļ�/ͷ�ļ�/._AQueue.h"

void choose();  //ѡ����е�����
void showSqStackTable();    //������ʾ����
void SqStackTest(); //��������
Status ifInit(int destroyStatus);   //�Ƿ��ʼ��

int main()
{
    SqStackTest();
    return 0;
}

void showSqStackTable()
{
    printf("                          \n");
    printf("                          \n");
    printf("ѡ����Թ���\n");
    printf("        ѡ��1����ʼ��\n");
    printf("        ѡ��2���ݻ�\n");
    printf("        ѡ��3��ѹ��\n");
    printf("        ѡ��4������\n");
    printf("        ѡ��5�����\n");
    printf("        ѡ��6���ж��Ƿ�Ϊ��\n");
    printf("        ѡ��7���õ���Ԫ��\n");
    printf("        ѡ��8����ⳤ��\n");
    printf("        ѡ��0:�˳�\n");
    printf("***************************\n");

}


void SqStackTest()
{
    int num,destroyStatus =1;                                       //ѡ���ܡ��ݻٱ�־
    AQueue *test;
    int e;

    while(num)
    {
        showSqStackTable();
        if(!destroyStatus)
        {
            if(flag == 1)printf("��ǰ��������Ϊdouble\n");
            if(flag == 2)printf("��ǰ��������Ϊchar\n");
            if(flag == 3)printf("��ǰ��������Ϊint\n");
            TraverseAQueue(test,APrint);
            printf("\n***************************\n");
        }
        while(1)        //ֻ������0-9
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
                    test = (AQueue*)malloc(sizeof(AQueue));            //�����ڴ�
                    choose();
                    if(flag == 1)
                    {
                        test->length = sizeof(double);
                        double e;
                    }
                    if(flag == 2)
                    {
                        test->length = sizeof(char);
                        char e;
                    }
                    if(flag == 3)
                    {
                        test->length = sizeof(int);
                        int e;
                    }
                    InitAQueue(test);
                    printf("    ��ʼ���ɹ�\n");
                    destroyStatus =0;
                    }
                }
                break;

            case 2:
                if(ifInit(destroyStatus))
                {
                    DestoryAQueue(test);
                    printf("    �ݻٳɹ�\n");
                    destroyStatus =1;
                }
                break;
            case 3:
                if(ifInit(destroyStatus))
                {
                    printf("����һ��ֵѹ�룺\n");
                    if(flag == 1)scanf("%lf",&e);
                    if(flag == 2)scanf("%c",&e);
                    if(flag == 3)scanf("%d",&e);
                    getchar();
                    if(EnAQueue(test,&e))printf("    ѹ��ɹ�\n");
                    else{printf("    ѹ��ʧ��\n");}
                }
                break;
            case 4:
                if(ifInit(destroyStatus))
                {
                    if(DeAQueue(test))printf("    �����ɹ�\n");
                    else{printf("    ����ʧ��\n");}
                }
                break;
            case 5:
                if(ifInit(destroyStatus))
                {
                    ClearAQueue(test);
                    printf("    ��ճɹ�\n");
                }
                break;
            case 6:
                if(ifInit(destroyStatus))
                {
                    if(IsEmptyAQueue(test))printf("    Ϊ��\n");
                    else{printf("    ��Ϊ��\n");}
                }
                break;
            case 7:
                if(ifInit(destroyStatus))
                {
                    if(GetHeadAQueue(test,&e)){
                    if(flag == 1)printf("    ��Ԫ����%f\n",e);
                    if(flag == 2)printf("    ��Ԫ����%c\n",e);
                    if(flag == 3)printf("    ��Ԫ����%d\n",e);
                    }
                    else{printf("    �õ�ʧ��\n");}
                }
                break;
            case 8:
                if(ifInit(destroyStatus))
                {
                    int length;
                    length = LengthAQueue(test);
                    printf("    ����%d\n",length);
                }
                break;
        }
        printf("���س�����:");
        getchar();
        system("CLS");
    }
}


void choose()
{
    printf("    ������һ����������,Ĭ��Ϊint��\n");
    printf("    ����1��double��\n");
    printf("    ����2��char��\n");
    printf("    ����3��int��\n");
    while(TRUE)        //ֻ������0-9
        {
            flag =getchar();
            flag -='0';
            if(flag >0 && flag <4){
                getchar();
                break;
            }
        }
}

Status ifInit(int destroyStatus)
{
    if(destroyStatus){
        printf("        δ��ʼ��\n");
        return FALSE;
    }
    return TRUE;
}

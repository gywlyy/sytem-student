#include <stdio.h>
#include <stdlib.h>             //exit����ͷ�ļ� 
#include <string.h>             //�ַ�����ز���ͷ�ļ� 
#define  MAX_STUDENT  30        //���ѧ���� 

//����������������10���Ӻ�����ÿ��������Ӧһ������ 
//void student_scanf(int n);
//void student_printf(int n);
//int student_find_name(int n);
//int student_find_num(int n);
//void student_sort_num(int n);
//void student_sort_sum(int n);
void student_scanf(int n);
void student_printf(int n);
int student_find_name(int n);
int student_find_num(int n);
int student_alter_num(int n);
int student_alter_name(int n);
int student_delete_num(int n);
int student_delete_name(int n);
//ȫ��������������ڴ洢ѧ����Ϣ 
char names[MAX_STUDENT][50];
int math[MAX_STUDENT];
int english[MAX_STUDENT];
int computer[MAX_STUDENT];
int sum[MAX_STUDENT];
int num[MAX_STUDENT];


//���±�������ѧ����Ϣ����������Ϊ��ʱ���� 
//int temp_num[MAX_STUDENT];
//char temp_names[MAX_STUDENT][50];
//int temp_math[MAX_STUDENT];
//int temp_english[MAX_STUDENT];
//int temp_computer[MAX_STUDENT];
//int temp_sum[MAX_STUDENT];
//sort����洢�ź����ѧ�Ż������±� 
int sort[MAX_STUDENT];
//ѭ��ȫ�ֱ��� 
//int i, j;

//main������
int main(void)
{
int i, j;

    int choice,n;
    while (1)
    {
//        printf("*************************************\n");
//        printf("��ӭʹ��ѧ���ɼ�����ϵͳ\n");
//        printf("[1] ��������ѧ����Ϣ\n");
//        printf("[2] �������ѧ���ɼ�\n");
//        printf("[3] ��ѧ�Ų���ĳ��ѧ����Ϣ\n");
//        printf("[4] ����������ĳ��ѧ����Ϣ\n");
////      printf("[5] ��ѧ�Ŷ�ѧ������\n");
////      printf("[6] ���ܳɼ���ѧ������\n");
//        printf("[7] ��ѧ���޸�ĳ��ѧ����Ϣ\n");
//        printf("[8] �������޸�ĳ��ѧ����Ϣ\n");
//        printf("[9] ��ѧ��ɾ��ĳ��ѧ����Ϣ\n");
//        printf("[10] ������ɾ��ĳ��ѧ����Ϣ\n");
//        printf("[0] �˳�����\n");
//        printf("����������ѡ��0 - 9��:");
//        scanf("%d",&choice);
//        printf("**************************************)\n");
//
//        switch (choice)
    printf("******************************************************\n");
	printf("*              ��ӭʹ��ѧ���ɼ�����ϵͳ              *\n");
	printf("******************************************************\n");
	printf("*              ��ѡ�����б�                        *\n");
	printf("******************************************************\n");
	printf("*              1¼��ѧ����Ϣ                         *\n");
	printf("*              2��ӡѧ����Ϣ                         *\n");
	printf("*              3ѧ�Ų���ѧ����Ϣ                     *\n");
	printf("*              4��������ѧ����Ϣ                     *\n");
	printf("*              5ѧ���޸�ѧ����Ϣ                     *\n");
	printf("*              6�����޸�ѧ����Ϣ                     *\n");
	printf("*              7ѧ��ɾ��ѧ����Ϣ                     *\n");
	printf("*              8����ɾ��ѧ����Ϣ                     *\n");
	printf("*              0�˳�ϵͳ                             *\n"); 
	printf("******************************************************\n");
	printf("**************************************************����\n");
    scanf("%d",&choice);

        switch (choice)
        {
        case 1://¼��;
            printf("������¼���ѧ����Ϣ���� ");
            scanf("%d",&n); 
            student_scanf(n);
            break;

        case 2://���;
            student_printf(n);
            break;

        case 3://����ѧ�Ų���
            student_find_num(n);
            break;

        case 4://������������
            student_find_name(n);
            break;

//        case 5://��ѧ������
//            student_sort_num(n);
//            break;
//
//        case 6://���������� 
//            student_sort_sum(n);
//            break;

        case 5://��ѧ���޸� 
            student_alter_num(n);
            break;

        case 6://�������޸� 
            student_alter_name(n);
            break;

        case 7://��ѧ��ɾ�� 
            student_delete_num(n);
            n--;
            break;

        case 8://������ɾ�� 
            student_delete_name(n);
            n--;
            break;

        case 0://�˳����� 
            printf("�˳�����\n");
            printf("���������ллʹ��!\n");
            exit(0);

        default:
            printf("������Ĳ˵��������������룡\n");

        }

    }
    return 0;
}
//1.������Ϣ
void student_scanf(int n)
{int i, j;


    for (i = 0; i<n; ++i)
    {
        printf("\n�������%d��ѧ������Ϣ:\n", i + 1);
        printf("\nѧ��:");
        scanf("%d", &num[i]);
        printf("\n����:");
        scanf("%s", names[i]);
        printf("\n��ѧ�ɼ�:");
        scanf("%d", &math[i]);
        printf("\nӢ��ɼ�:");
        scanf("%d", &english[i]);
        printf("\n������ɼ�:");
        scanf("%d", &computer[i]);
        //�����ܳɼ�
        sum[i] = math[i] + english[i] + computer[i];
    }
}
//2.��ӡ��Ϣ        
void student_printf(int n)
//char names[MAX_STUDENT][50];
//int math[MAX_STUDENT];
//int english[MAX_STUDENT];
//int computer[MAX_STUDENT];
//int sum[MAX_STUDENT];
//int num[MAX_STUDENT];
//int i, j;

{
int i, j;

    printf("\nѧ��\t����\t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t�ܳɼ�\n");
    printf("----------------------------------------------------------\n");

    for (i = 0; i<n; ++i)
    {
        printf("%d\t%s\t%d\t\t%d\t\t%d\t\t%d\n", num[i], names[i], math[i], english[i], computer[i], sum[i]);
    }
    printf("-------------------------------------------------------\n");
}

//3.��ѧ�Ų���
int student_find_num(int n)
//char names[MAX_STUDENT][50];
//int math[MAX_STUDENT];
//int english[MAX_STUDENT];
//int computer[MAX_STUDENT];
//int sum[MAX_STUDENT];
//int num[MAX_STUDENT];
//int i, j;

{
int i, j;
    int nums;
    int result;
    printf("����������ҵ�ѧ��ѧ��:");
    scanf("%d",&nums);
    result= -1;
    for (i = 0; i<n; ++i)
    {
        if (nums == num[i])
        {
            result = i;

            break;
        }

    }

    //����ж�qֵ
    if (result == -1)
    {
        printf("û�и�ѧ����Ϣ!\n");
        return 0;
    }
    else
    {
        //�ȴ�ӡ��ͷ
        printf("\nѧ��\t\t����\t\t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t�ܳɼ�\n");
        //�ٴ�ӡ����

        printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\t%d\n", num[result], names[result], math[result], english[result], computer[result], sum[result]);
        printf("��ӡ�����ҽ��!\n");
    }
    return 1;
}

//4.���������ҳɼ�
int student_find_name(int n)
//char names[MAX_STUDENT][50];
//int math[MAX_STUDENT];
//int english[MAX_STUDENT];
//int computer[MAX_STUDENT];
//int sum[MAX_STUDENT];
//int num[MAX_STUDENT];


{
int i, j;
    char name[200];
    int result;
    printf("����������ҵ�ѧ������:");
    scanf("%s", name);
    result = -1;
    for (i = 0; i<n; ++i)
    {
        if (strcmp(name, names[i]) == 0)
        {
            result = i;
            break;
        }
    }
    if (result == -1)
    {//δ�ҵ����
        printf("û�и�ѧ����Ϣ!\n");
        return 0;
    }
    else//�ҵ����
    {
        printf("\nѧ��\t����\t��ѧ�ɼ�\tӢ��ɼ�\t������ɼ�\t�ܳɼ�\n");
        printf("%d\t%s\t%d\t\t%d\t\t%d\t\t%d\n", num[result], names[result], math[result], english[result], computer[result], sum[result]);
        printf("����ɲ���!\n");
    }


    return 1;
}

//5.��ѧ������
//void student_sort_num(int n)
//{
//    int min,max;
//    for(i=0; i<n; ++i)  //������ʱ���� 
//    {
//        temp_num[i] = num[i];
//    }
//
//    max = 0;        //����ѧ�����ֵ�������±����sort��������һ��ֵ�� 
//    for(j=1; j<n; j++)
//    {
//        if(temp_num[max]<temp_num[j])
//            max = j;
//    } 
//    sort[n-1] = max;    //sort��������һ���� 
//    for(i=0; i<n-1; ++i)
//    {
//        min = i;        //����ѧ����Сֵ
//        for(j=0; j<n; ++j)
//        {
//            if(temp_num[min]>temp_num[j])
//                min = j;
//        } 
//        //sort�����¼�����ѧ����Ϣ���±� 
//        sort[i] = min;
//        temp_num[min] = temp_num[max];      //������ʱ���齫���ҹ���ѧ����Ϣ��ѧ����Ϊ���ֵ���ų����Ҹ���        
//    }
//    for(i=0; i<n; ++i)  //�ٸ���һ����ʱ���� 
//    {
//        temp_num[i] = num[i];
//        strcpy(temp_names[i],names[i]);
//        temp_math[i] = math[i];
//        temp_english[i] = english[i];
//        temp_computer[i] = computer[i];
//        temp_sum[i] = sum[i];
//    }
//
//    for(i=0; i<n; i++)  //�����±��ԭ��������޸� 
//    {
//        num[i] = temp_num[sort[i]]; 
//        strcpy(names[i],temp_names[sort[i]]); 
//        math[i] = temp_math[sort[i]]; 
//        english[i] = temp_english[sort[i]]; 
//        computer[i] = temp_computer[sort[i]]; 
//        sum[i] = temp_sum[sort[i]];
//    }
//    printf("������ϣ��밴�˵���2�鿴��������\n");
//    return ;
//}
//
////6.���ܳɼ�����
//void student_sort_sum(int n)
//{
//    int min,max;
//    for(i=0; i<n; ++i)  //������ʱ���� 
//    {
//        temp_sum[i] = sum[i];
//    }
//
//    max = 0;        //�����ܳɼ����ֵ�������±����sort��������һ��ֵ�� 
//    for(j=1; j<n; j++)
//    {
//        if(temp_sum[max]<temp_sum[j])
//            max = j;
//    } 
//    sort[n-1] = max;    //sort��������һ���� 
//    for(i=0; i<n-1; ++i)
//    {
//        min = i;        //�����ܳɼ���Сֵ
//        for(j=0; j<n; ++j)
//        {
//            if(temp_sum[min]>temp_sum[j])
//                min = j;
//        } 
//        //sort�����¼�����ѧ����Ϣ���±� 
//        sort[i] = min;
//        temp_sum[min] = temp_sum[max];      //������ʱ���齫���ҹ���ѧ����Ϣ���ܳɼ���Ϊ���ֵ���ų����Ҹ���       
//    }
//    for(i=0; i<n; ++i)  //�ٸ���һ����ʱ���� 
//    {
//        temp_num[i] = num[i];
//        strcpy(temp_names[i],names[i]);
//        temp_math[i] = math[i];
//        temp_english[i] = english[i];
//        temp_computer[i] = computer[i];
//        temp_sum[i] = sum[i];
//    }
//
//    for(i=0; i<n; i++)  //�����±��ԭ��������޸� 
//    {
//        num[i] = temp_num[sort[i]]; 
//        strcpy(names[i],temp_names[sort[i]]); 
//        math[i] = temp_math[sort[i]]; 
//        english[i] = temp_english[sort[i]]; 
//        computer[i] = temp_computer[sort[i]]; 
//        sum[i] = temp_sum[sort[i]];
//    }
//    printf("������ϣ��밴�˵���2�鿴��������\n");
//    return ;
//}

//5.��ѧ���޸�ѧ����5Ϣ
int student_alter_num(int n)
//char names[MAX_STUDENT][50];
//int math[MAX_STUDENT];
//int english[MAX_STUDENT];
//int computer[MAX_STUDENT];
//int sum[MAX_STUDENT];
//int num[MAX_STUDENT];
//int i, j;
// 
{int i, j;
    int nums;
    int result;
    printf("��������޸ĵ�ѧ��ѧ��:");
    scanf("%d",&nums);
    result= -1;
    for (i = 0; i<n; ++i)
    {
        if (nums == num[i])
        {
            result = i;
            break;
        }
    }

    //����ж�qֵ
    if (result == -1)
    {
        printf("û�и�ѧ����Ϣ!\n");
        return 0;
    }
    else    //�޸���Ϣֵ 
    {
        printf("�����������ѧ����Ϣ��\n");
        printf("ѧ�ţ�\n");
        scanf("%d",&num[result]);
        printf("������\n");
        scanf("%s",names[result]); 
        printf("��ѧ�ɼ���\n");
        scanf("%d",&math[result]);
        printf("Ӣ��ɼ���\n");
        scanf("%d",&english[result]);
        printf("������ɼ���\n");
        scanf("%d",&computer[result]);
        sum[result] = math[result] + english[result] + computer[result];
    }
    return 1;
} 

//.6�������޸�ѧ����Ϣ
int student_alter_name(int n) 
//char names[MAX_STUDENT][50];
//int math[MAX_STUDENT];
//int english[MAX_STUDENT];
//int computer[MAX_STUDENT];
//int sum[MAX_STUDENT];
//int num[MAX_STUDENT];
//int i, j;

{
int i, j;
    char name[50];
    int result;
    printf("��������޸ĵ�ѧ������:");
    scanf("%s",name);
    result= -1;
    for (i = 0; i<n; ++i)
    {
        if (strcmp(name,names[i])==0)
        {
            result = i;
            break;
        }
    }
    //����ж�qֵ
    if (result == -1)
    {
        printf("û�и�ѧ����Ϣ!\n");
        return 0;
    }
    else        //�޸���Ϣֵ 
    {
        printf("�����������ѧ����Ϣ��\n");
        printf("ѧ�ţ�\n");
        scanf("%d",&num[result]);
        printf("������\n");
        scanf("%s",names[result]); 
        printf("��ѧ�ɼ���\n");
        scanf("%d",&math[result]);
        printf("Ӣ��ɼ���\n");
        scanf("%d",&english[result]);
        printf("������ɼ���\n");
        scanf("%d",&computer[result]);
        sum[result] = math[result] + english[result] + computer[result];
    }
    return 1;
} 


//7.��ѧ��ɾ��ѧ����Ϣ
int student_delete_num(int n) 
//char names[MAX_STUDENT][50];
//int math[MAX_STUDENT];
//int english[MAX_STUDENT];
//int computer[MAX_STUDENT];
//int sum[MAX_STUDENT];
//int num[MAX_STUDENT];
//int i, j;

{int i, j;

    int nums;
    int result;
    printf("�������ɾ����ѧ��ѧ��:");
    scanf("%d",&nums);
    result= -1;
    for (i = 0; i<n; ++i)
    {
        if (nums == num[i])
        {
            result = i;
            break;
        }
    }
    //����ж�qֵ
    if (result == -1)
    {
        printf("û�и�ѧ����Ϣ!\n");
        return 0;
    }
    else    //ɾ����ǰѧ����Ϣ��Ϊ�������result��λ������ǰŲһ��λ�� 
    {
        for(i=result; i<n-1; ++i)   //�����main�����У�Ҫ��n��ֵ��1 
        {
            num[i] = num[i+1]; 
            strcpy(names[i],names[i+1]); 
            math[i] = math[i+1]; 
            english[i] = english[i+1]; 
            computer[i] = computer[i+1]; 
            sum[i] = sum[i+1];
        } 

    }
    return 1;
} 

//8.������ɾ��ѧ����Ϣ
int student_delete_name(int n) 
//char names[MAX_STUDENT][50];
//int math[MAX_STUDENT];
//int english[MAX_STUDENT];
//int computer[MAX_STUDENT];
//int sum[MAX_STUDENT];
//int num[MAX_STUDENT];
//int i, j;

{int i, j;
    char name[50];
    int result;
    printf("�������ɾ����ѧ������:");
    scanf("%s",name);
    result= -1;
    for (i = 0; i<n; ++i)
    {
        if (strcmp(name,names[i])==0)
        {
            result = i;
            break;
        }
    }
    //����ж�qֵ
    if (result == -1)
    {
        printf("û�и�ѧ����Ϣ!\n");
        return 0;
    }
    else    //ɾ����ǰѧ����Ϣ��Ϊ�������result��λ������ǰŲһ��λ�� 
    {
        for(i=result; i<n-1; ++i)       //�����main�����У�Ҫ��n��ֵ��1 
        {
            num[i] = num[i+1]; 
            strcpy(names[i],names[i+1]); 
            math[i] = math[i+1]; 
            english[i] = english[i+1]; 
            computer[i] = computer[i+1]; 
            sum[i] = sum[i+1];
        } 
    }
    return 1;
} 



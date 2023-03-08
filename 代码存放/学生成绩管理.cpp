#include <stdio.h>
#include <stdlib.h>
#define MAX_STUDENTS 50

struct student {
    int id;
    char name[20];
    int score;
};

struct student students[MAX_STUDENTS];
int num_students = 0;

void add_student() {
    struct student s;
    printf("������ѧ��ѧ�ţ�");
    scanf("%d", &s.id);
    printf("������ѧ��������");
    scanf("%s", s.name);
    printf("������ѧ���ɼ���");
    scanf("%d", &s.score);
    students[num_students++] = s;
    printf("��ӳɹ���\n");
}

void print_all_students() {
    printf("ѧ��\t����\t�ɼ�\n");
    for (int i = 0; i < num_students; i++) {
        struct student s = students[i];
        printf("%d\t%s\t%d\n", s.id, s.name, s.score);
    }
}

void find_student() {
    int id;
    printf("������Ҫ���ҵ�ѧ��ѧ�ţ�");
    scanf("%d", &id);
    for (int i = 0; i < num_students; i++) {
        struct student s = students[i];
        if (s.id == id) {
            printf("ѧ��\t����\t�ɼ�\n");
            printf("%d\t%s\t%d\n", s.id, s.name, s.score);
            return;
        }
    }
    printf("û���ҵ���ѧ����\n");
}

int main() {
    int choice;
    do {
        printf("��ѡ�������\n");
        printf("1. ���ѧ��\n");
        printf("2. ��ʾ����ѧ��\n");
        printf("3. ����ѧ��\n");
        printf("0. �˳�����\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                print_all_students();
                break;
            case 3:
                find_student();
                break;
            case 0:
                printf("ллʹ�ã�\n");
                break;
            default:
                printf("��Ч��ѡ��\n");
                break;
        }
//    system("cls");
//    system("pause");   //��ͣ 
    } while (choice != 0);
   
    return 0;
}

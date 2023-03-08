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
    printf("请输入学生学号：");
    scanf("%d", &s.id);
    printf("请输入学生姓名：");
    scanf("%s", s.name);
    printf("请输入学生成绩：");
    scanf("%d", &s.score);
    students[num_students++] = s;
    printf("添加成功！\n");
}

void print_all_students() {
    printf("学号\t姓名\t成绩\n");
    for (int i = 0; i < num_students; i++) {
        struct student s = students[i];
        printf("%d\t%s\t%d\n", s.id, s.name, s.score);
    }
}

void find_student() {
    int id;
    printf("请输入要查找的学生学号：");
    scanf("%d", &id);
    for (int i = 0; i < num_students; i++) {
        struct student s = students[i];
        if (s.id == id) {
            printf("学号\t姓名\t成绩\n");
            printf("%d\t%s\t%d\n", s.id, s.name, s.score);
            return;
        }
    }
    printf("没有找到该学生！\n");
}

int main() {
    int choice;
    do {
        printf("请选择操作：\n");
        printf("1. 添加学生\n");
        printf("2. 显示所有学生\n");
        printf("3. 查找学生\n");
        printf("0. 退出程序\n");
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
                printf("谢谢使用！\n");
                break;
            default:
                printf("无效的选择！\n");
                break;
        }
//    system("cls");
//    system("pause");   //暂停 
    } while (choice != 0);
   
    return 0;
}

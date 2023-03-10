#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int age;
    char student_id[20];
    int temperature;
    int contact_with_sick;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("已达到最大学生数量。\n");
        return;
    }

    Student new_student;

    printf("请输入学生姓名: ");
    scanf("%s", new_student.name);

    printf("请输入学生年龄: ");
    scanf("%d", &new_student.age);

    printf("请输入学生学号: ");
    scanf("%s", new_student.student_id);

    printf("请输入学生体温: ");
    scanf("%d", &new_student.temperature);

    printf("该学生是否接触过病患? (1 = 是，0 = 否): ");
     scanf("%d", &new_student.contact_with_sick);

    students[student_count++] = new_student;

}

void save_data() {
   FILE *fp;
   fp = fopen("data.txt", "w");

   if (fp == NULL) {
       printf("无法打开文件。\n");
       return;
   }

   for (int i = 0; i < student_count; i++) {
       fprintf(fp, "%s %d %s %d %d\n",
               students[i].name,
               students[i].age,
               students[i].student_id,
               students[i].temperature,
               students[i].contact_with_sick);
   }

   fclose(fp);
}

void load_data() {
   FILE *fp;
   fp = fopen("data.txt", "r");

   if (fp == NULL) {
       printf("无法打开文件。\n");
       return;
   }
   
   while (!feof(fp)) {
       Student new_student;

       fscanf(fp, "%s %d %s %d %d\n",
              new_student.name,
              &new_student.age,
              new_student.student_id,
              &new_student.temperature,
              &new_student.contact_with_sick);

       students[student_count++] = new_student;
   }

   fclose(fp);
}

int main() {

  load_data();

  int choice;

  do {
      printf("\n菜单:\n");
      printf("[1] 添加新学生\n");
      printf("[2] 保存数据\n");
      printf("[3] 加载数据\n");
      printf("[4] 退出程序\n");

      scanf("%d", &choice);

      switch(choice) {
          case 1:
              add_student();
              break;
               case 2:
              save_data();
              break;
          case 3:
              load_data();
              break;
          case 4:
              exit(0);
          default:
              break;
      }
  } while(1);

}

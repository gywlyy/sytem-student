#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//数组不需要我们手动分配内存空间，由系统自动分配
void create();
void initData();
void add();
void remove();//删除 
void search();
void update();
void sortNodeByTotal();
void show();
void store();
int findTheNode(struct Student student[], int num);
void output(struct Student student);
struct Student{//学生结构体
	int num;
	char name[20];
	float math;
	float english;
	float computer;
	float ave;    //平均分 
	float sum;    //总分 
}student[50];//int a [50]
int count = 0;//记录当前数组中有数据的节点个数
//有一辆50座位的客车
//当前车上的人数来收费


int main(){
	create();
	return 0;
}

void create(){
	int a = 0;
	initData();
	printf("当前文件中有%d条数据\n", count);
//	printf("\t\t\t欢迎使用学生成绩管理系统\n");
//	printf("1：添加一条学生数据\n");
//	printf("2：删除一条学生数据\n");
//	printf("3：查找一条学生数据\n");
//	printf("4：修改一条学生数据\n");
//	printf("5：显示所有学生数据\n");
//	printf("6：按照学生成绩排序\n");
//	printf("7：学生数据存档并退出\n");
	printf("******************************************************\n");
	printf("*              欢迎使用学生成绩管理系统              *\n");
	printf("******************************************************\n");
	printf("*              请选择功能列表                        *\n");
	printf("******************************************************\n");
	printf("*              1添加一名学生信息                     *\n");
	printf("*              2删除一名学生信息                     *\n");
	printf("*              3查找一名学生信息                     *\n");
	printf("*              4修改一名学生信息                     *\n");
	printf("*              5显示所有学生信息                     *\n");
	printf("*              6所以学生成绩排序                     *\n");
	printf("*              7存入文档并且退出                     *\n");
//	printf("*              8姓名删除学生信息                     *\n");
//	printf("*              0退出系统                             *\n"); 
	printf("******************************************************\n");

	while (1){
		scanf("%d", &a);
		switch (a){
		case 1:add(); break;
		case 2:remove(); break;
		case 3:search(); break;
		case 4:update(); break;
		case 5:show(); break;
		case 6:sortNodeByTotal(); break;
		case 7:store();
		}
	}
}
 
void initData(){
	FILE * fp = NULL;
	fp = fopen("student.txt", "r");
	if (!fp){
		printf("文件打开失败\n");
		exit(0); 
	}
	while (1){
		fscanf(fp, "%d%s%f%f%f%f%f", &student[count].num, student[count].name, &student[count].math, &student[count].english, &student[count].computer, &student[count].ave, &student[count].sum);
		if (feof(fp)){
			break;
		}
		count++;
	}
}
//1增加 
void add(){

	student[count].ave = 0;
	student[count].sum = 0;
	printf("请输入学号\n");
	scanf("%d", &student[count].num);

	printf("请输入姓名\n");
	scanf("%s", student[count].name);

	printf("请输入高数\n");
	scanf("%f", &student[count].math);
	student[count].sum += student[count].math;

	printf("请输入英语\n");
	scanf("%f", &student[count].english);
	student[count].sum += student[count].english;

	printf("请输入计算机\n");
	scanf("%f", &student[count].computer);
	student[count].sum += student[count].computer;

	student[count].ave = student[count].sum / 3.0;


	printf("%s同学的信息添加成功\n", student[count].name);
	count++;
}
//用结构体数组实现节点的删除
//覆盖即删除
void remove(){
	int num = 0;
	int target = 0;//用于接收目标结点的下标

	printf("请输入你想删除学生的学号\n");
	scanf("%d", &num);
	target = findTheNode(student, num);

	if (target < 0){
		printf("对不起，查无此纪录\n");
		return;
	}
	else{

		for (int i = target; i < count; i++){
			student[i] = student[i + 1];
		}
		printf("删除成功\n");
		count--;
	}
}

void search(){
	int num = 0;
	int target = 0;
	printf("请输入你想查找学生的学号\n");
	scanf("%d", &num);
	target = findTheNode(student, num);
	if (target<0){
		printf("查无此人\n");
	}
	else{
		output(student[target]);
	}
}

//4修改 
void update(){
	int num = 0;
	int target = 0;
	printf("请输入你想修改学生的学号\n");
	scanf("%d", &num);
	target = findTheNode(student, num);
	if (target <0){
		printf("查无此人\n");
	}
	else{
		printf("请输入学号\n");
		scanf("%d", &student[target].num);

		printf("请输入姓名\n");
		scanf("%s", student[target].name);

		printf("请输入高数\n");
		scanf("%f", &student[target].math);
		student[target].sum+= student[target].math;

		printf("请输入英语\n");
		scanf("%f", &student[target].english);
		student[target].sum += student[target].english;

		printf("请输入计算机\n");
		scanf("%f", &student[target].computer);
		student[target].sum += student[target].computer;

		student[target].ave = student[target].sum / 3.0;

		printf("修改成功\n");
		output(student[target]);
	}
}

void sortNodeByTotal(){
	struct Student temp;
	for (int i = 0; i < count - 1; i++){
		for (int j = 0; j < count - 1 - i; j++){
			if (student[j].sum<student[j+1].sum){
				temp = student[j + 1];
				student[j + 1] = student[j];
				student[j]= temp;
			}
		}
	}
	printf("排序完成\n");
	show();
}

//5展示 
void show(){
	for (int i = 0; i < count; i++){
		output(student[i]);
	}
}

void output(struct Student student){//传入节点
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("学号:%d\t姓名:%s\t高数:%.2f\t英语:%.2f\t计算机%.2f\t平均分:%.2f\t总分:%.2f\n",
		student.num, student.name, student.math, student.english
		, student.computer, student.ave, student.sum);
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
}

int findTheNode(struct Student student[], int num){
	int temp = -1;
	for (int i = 0; i < count; i++){
		if (student[i].num == num){
			temp = i;
			break;
		}
	}
	return temp;
}

void store(){
	FILE * fp = NULL;
	fp = fopen("student.txt", "w");
	for (int i = 0; i < count; i++){
		fprintf(fp, "%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", student[i].num, student[i].name, student[i].math, student[i].english, student[i].computer, student[i].ave, student[i].sum);
	}
	printf("数据保存成功，程序已退出\n");
	exit(0);
}


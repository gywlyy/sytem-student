#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//���鲻��Ҫ�����ֶ������ڴ�ռ䣬��ϵͳ�Զ�����
void create();
void initData();
void add();
void remove();//ɾ�� 
void search();
void update();
void sortNodeByTotal();
void show();
void store();
int findTheNode(struct Student student[], int num);
void output(struct Student student);
struct Student{//ѧ���ṹ��
	int num;
	char name[20];
	float math;
	float english;
	float computer;
	float ave;    //ƽ���� 
	float sum;    //�ܷ� 
}student[50];//int a [50]
int count = 0;//��¼��ǰ�����������ݵĽڵ����
//��һ��50��λ�Ŀͳ�
//��ǰ���ϵ��������շ�


int main(){
	create();
	return 0;
}

void create(){
	int a = 0;
	initData();
	printf("��ǰ�ļ�����%d������\n", count);
//	printf("\t\t\t��ӭʹ��ѧ���ɼ�����ϵͳ\n");
//	printf("1�����һ��ѧ������\n");
//	printf("2��ɾ��һ��ѧ������\n");
//	printf("3������һ��ѧ������\n");
//	printf("4���޸�һ��ѧ������\n");
//	printf("5����ʾ����ѧ������\n");
//	printf("6������ѧ���ɼ�����\n");
//	printf("7��ѧ�����ݴ浵���˳�\n");
	printf("******************************************************\n");
	printf("*              ��ӭʹ��ѧ���ɼ�����ϵͳ              *\n");
	printf("******************************************************\n");
	printf("*              ��ѡ�����б�                        *\n");
	printf("******************************************************\n");
	printf("*              1���һ��ѧ����Ϣ                     *\n");
	printf("*              2ɾ��һ��ѧ����Ϣ                     *\n");
	printf("*              3����һ��ѧ����Ϣ                     *\n");
	printf("*              4�޸�һ��ѧ����Ϣ                     *\n");
	printf("*              5��ʾ����ѧ����Ϣ                     *\n");
	printf("*              6����ѧ���ɼ�����                     *\n");
	printf("*              7�����ĵ������˳�                     *\n");
//	printf("*              8����ɾ��ѧ����Ϣ                     *\n");
//	printf("*              0�˳�ϵͳ                             *\n"); 
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
		printf("�ļ���ʧ��\n");
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
//1���� 
void add(){

	student[count].ave = 0;
	student[count].sum = 0;
	printf("������ѧ��\n");
	scanf("%d", &student[count].num);

	printf("����������\n");
	scanf("%s", student[count].name);

	printf("���������\n");
	scanf("%f", &student[count].math);
	student[count].sum += student[count].math;

	printf("������Ӣ��\n");
	scanf("%f", &student[count].english);
	student[count].sum += student[count].english;

	printf("����������\n");
	scanf("%f", &student[count].computer);
	student[count].sum += student[count].computer;

	student[count].ave = student[count].sum / 3.0;


	printf("%sͬѧ����Ϣ��ӳɹ�\n", student[count].name);
	count++;
}
//�ýṹ������ʵ�ֽڵ��ɾ��
//���Ǽ�ɾ��
void remove(){
	int num = 0;
	int target = 0;//���ڽ���Ŀ������±�

	printf("����������ɾ��ѧ����ѧ��\n");
	scanf("%d", &num);
	target = findTheNode(student, num);

	if (target < 0){
		printf("�Բ��𣬲��޴˼�¼\n");
		return;
	}
	else{

		for (int i = target; i < count; i++){
			student[i] = student[i + 1];
		}
		printf("ɾ���ɹ�\n");
		count--;
	}
}

void search(){
	int num = 0;
	int target = 0;
	printf("�������������ѧ����ѧ��\n");
	scanf("%d", &num);
	target = findTheNode(student, num);
	if (target<0){
		printf("���޴���\n");
	}
	else{
		output(student[target]);
	}
}

//4�޸� 
void update(){
	int num = 0;
	int target = 0;
	printf("�����������޸�ѧ����ѧ��\n");
	scanf("%d", &num);
	target = findTheNode(student, num);
	if (target <0){
		printf("���޴���\n");
	}
	else{
		printf("������ѧ��\n");
		scanf("%d", &student[target].num);

		printf("����������\n");
		scanf("%s", student[target].name);

		printf("���������\n");
		scanf("%f", &student[target].math);
		student[target].sum+= student[target].math;

		printf("������Ӣ��\n");
		scanf("%f", &student[target].english);
		student[target].sum += student[target].english;

		printf("����������\n");
		scanf("%f", &student[target].computer);
		student[target].sum += student[target].computer;

		student[target].ave = student[target].sum / 3.0;

		printf("�޸ĳɹ�\n");
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
	printf("�������\n");
	show();
}

//5չʾ 
void show(){
	for (int i = 0; i < count; i++){
		output(student[i]);
	}
}

void output(struct Student student){//����ڵ�
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("ѧ��:%d\t����:%s\t����:%.2f\tӢ��:%.2f\t�����%.2f\tƽ����:%.2f\t�ܷ�:%.2f\n",
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
	printf("���ݱ���ɹ����������˳�\n");
	exit(0);
}


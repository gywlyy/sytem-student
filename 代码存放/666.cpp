struct student {
    int id;              // 学号
    char name[20];       // 姓名
    char gender[10];     // 性别
    float score[5];      // 成绩，包括5门课程
    float total_score;   // 总分
    float avg_score;     // 平均分
    int rank;            // 排名
};

//输入一个班级的学生的基本信息和成绩
void input_students(struct student stu[], int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        printf("请输入第%d个学生的基本信息和成绩：\n", i + 1);
        printf("学号：");
        scanf("%d", &stu[i].id);
        printf("姓名：");
        scanf("%s", stu[i].name);
        printf("性别：");
        scanf("%s", stu[i].gender);
        printf("5门课程的成绩：");
        for (j = 0; j < 5; j++) {
            scanf("%f", &stu[i].score[j]);
        }
    }
}

//按姓名或者学号查找学生信息
int search_student(struct student stu[], int n, int id, char name[])
{
    int i;
    for (i = 0; i < n; i++) {
        if ((id > 0 && stu[i].id == id) || (strcmp(stu[i].name, name) == 0)) {
            return i; // 返回学生在数组中的下标
        }
    }
    return -1; // 没有找到对应的学生
}

//修改学生信息
void modify_student(struct student stu[], int n)
{
    int id;
    char name[20];
    int index;
    printf("请输入要修改学生的学号或姓名：");
    scanf("%d%s", &id, name);
    index = search_student(stu, n, id, name);
    if (index >= 0) {
        printf("请输入修改后的学生信息：\n");
        printf("学号：");
        scanf("%d", &stu[index].id);
        printf("姓名：");
        scanf("%s", stu[index].name);
        printf("性别：");
        scanf("%s", stu[index].gender);
        printf("5门课程的成绩：");
        int j;
        for (j = 0; j < 5; j++) {
            scanf("%f", &stu[index].score[j]);
        }
    } else {
        printf("没有找到对应的学生\n");
    }
}

//删除学生信息
void delete_student(struct student stu[], int *n)
{
    int id;
    char name[20];
    int index, i;
    printf("请输入要删除学生的学号或姓名：");
    scanf("%d%s", &id, name);
    index = search_student(stu, *n, id, name);
    if (index >= 0)
    {
    	for (i = index; i < (*n) - 1; i++) 
		{
        stu[i] = stu[i + 1];
        }
        (*n)--;
        printf("删除成功\n");
    } else {
        printf("没有找到对应的学生\n");
    }

//保存学生信息到文件中
void save_students(struct student stu[], int n, char *filename)
{
    FILE *fp;
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("无法打开文件\n");
        return;
    }
    fwrite(stu, sizeof(struct student), n, fp);
    fclose(fp);
}

//从文件中读取学生信息
int load_students(struct student stu[], int max_n, char *filename)
{
    FILE *fp;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        return 0;
    }
    int n = fread(stu, sizeof(struct student), max_n, fp);
    fclose(fp);
    return n;
}

//计算每个学生各门功课总分和平均分，按学号或总分排序输出每个学生的基本信息及总分、平均分和名次
void calculate_score(struct student stu[], int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        float total = 0;
        for (j = 0; j < 5; j++) {
            total += stu[i].score[j];
        }
        stu[i].total_score = total;
        stu[i].avg_score = total / 5;
    }
    for (i = 0; i < n; i++) {
        int rank = 1;
        for (j = 0; j < n; j++) {
            if (stu[j].total_score > stu[i].total_score) {
                rank++;
            }
        }
        stu[i].rank = rank;
    }
}

void sort_students(struct student stu[], int n, int mode)
{
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if ((mode == 1 && stu[i].id > stu[j].id) || (mode == 2 && stu[i].total_score > stu[j].total_score)) {
                struct student temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }
}

void print_students(struct student stu[], int n)
{
    int i;
    printf("%-8s%-12s%-6s%-8s%-8s%-8s%-8s%-8s\n", "学号", "姓名", "性别", "语文", "数学", "英语", "物理", "总分");
    for (i = 0; i < n; i++) {
        printf("%-8d%-12s%-6s%-8.2f%-8.2f%-8.2f%-8.2f%-8.2f\n",
            stu[i].id, stu[i].name, stu[i].gender,
            stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3],
            stu[i].total_score);
    }
}
``


//计算全班各门功课的平均分，显示每门课程中低于平均分的每一个学生的学号，姓名，性别，科目，成绩
void calculate_course_avg(struct student stu[], int n, float *avg)
{
    int i, j;
    float sum[5] = {0};
    for (i = 0; i < n; i++) {
        for (j = 0; j < 5; j++) {
            sum[j] += stu[i].score[j];
        }
    }
    for (i = 0; i < 5; i++) {
        avg[i] = sum[i] / n;
    }
}

void print_below_avg(struct student stu[], int n, float *avg)
{
    int i, j;
    printf("语文低于平均分的学生：\n");
    printf("%-8s%-12s%-6s%-8s\n", "学号", "姓名", "性别", "成绩");
    for (i = 0; i < n; i++) {
        if (stu[i].score[0] < avg[0]) {
            printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[0]);
        }
    }
    printf("数学低于平均分的学生：\n");
    printf("%-8s%-12s%-6s%-8s\n", "学号", "姓名", "性别", "成绩");
    for (i = 0; i < n; i++) {
        if (stu[i].score[1] < avg[1]) {
            printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[1]);
        }
    }
    printf("英语低于平均分的学生：\n");
    printf("%-8s%-12s%-6s%-8s\n", "学号", "姓名", "性别", "成绩");
    for (i = 0; i < n; i++) {
        if (stu[i].score[2] < avg[2]) {
            printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[2]);
        }
    }
    printf("物理低于平均分的学生：\n");
    printf("%-8s%-12s%-6s%-8s\n", "学号", "姓名", "性别", "成绩");
    for (i = 0; i < n; i++) {
        if (stu[i].score[3] < avg[3]) {
            printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[3]);
        }
    }
}

void print_above_90(struct student stu[], int n)
{
    int i, j;
    printf("语文90分以上的学生：\n");
    printf("%-8s%-12s%-6s%-8s\n", "学号", "姓名", "性别", "成绩");
    for (i = 0; i < n; i++) {
	if (stu[i].score[0] > 90) {
	printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[0]);
	}
	}
	printf("数学90分以上的学生：\n");
	printf("%-8s%-12s%-6s%-8s\n", "学号", "姓名", "性别", "成绩");
	for (i = 0; i < n; i++) {
	if (stu[i].score[1] > 90) {
	printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[1]);
	}
	}
	printf("英语90分以上的学生：\n");
	printf("%-8s%-12s%-6s%-8s\n", "学号", "姓名", "性别", "成绩");
	for (i = 0; i < n; i++) {
	if (stu[i].score[2] > 90) {
	printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[2]);
	}
	}
	printf("物理90分以上的学生：\n");
	printf("%-8s%-12s%-6s%-8s\n", "学号", "姓名", "性别", "成绩");
	for (i = 0; i < n; i++) {
	if (stu[i].score[3] > 90) {
	printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[3]);
	}
	}
	}
	
	void print_failed(struct student stu[], int n)
	{
	int i, j;
	printf("语文不及格的学生：\n");
	printf("%-8s%-12s%-6s%-8s\n", "学号", "姓名", "性别", "成绩");
	for (i = 0; i < n; i++) {
	if (stu[i].score[0] < 60) {
	printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[0]);
	}
	}
	printf("数学不及格的学生：\n");
	printf("%-8s%-12s%-6s%-8s\n", "学号", "姓名", "性别", "成绩");
	for (i = 0; i < n; i++) {
	if (stu[i].score[1] < 60) {
	printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[1]);
	}
	}
	printf("英语不及格的学生：\n");
	printf("%-8s%-12s%-6s%-8s\n", "学号", "姓名", "性别", "成绩");



//主函数
int main()
{
	struct student stu[MAX_STU];
	int n = 0;
	char choice;
	int is_logged_in = 0;
	char username[20], password[20];
	while (1)
	{
		printf("欢迎使用学生成绩管理系统！\n");
		printf("请选择您需要的操作：\n");
		printf("1. 登录\n");
		printf("2. 退出\n");
		printf("请输入您的选择：");
		scanf("%c", &choice);
		switch (choice) {
			case '1':
			if (is_logged_in) 
			{
				printf("您已经登录了！\n");
				break;
			}
	printf("请输入用户名和密码：\n");
	scanf("%s%s", username, password);
	if (strcmp(username, "admin") == 0 && strcmp(password, "123456") == 0) {
	is_logged_in = 1;
	printf("登录成功！\n");
	} else {
	printf("用户名或密码错误！\n");
	}
	break;
	case '2':
	printf("欢迎再次使用！\n");
	exit(0);
	default:
	printf("输入错误，请重新输入！\n");
	break;
	}
	while (is_logged_in) {
	printf("请选择您需要的操作：\n");
	printf("1. 录入学生成绩\n");
	printf("2. 查找学生信息\n");
	printf("3. 修改学生信息\n");
	printf("4. 删除学生信息\n");
	printf("5. 保存学生信息\n");
	printf("6. 计算学生成绩\n");
	printf("7. 显示全班低于平均分的学生信息\n");
	printf("8. 显示各科成绩90分以上和不及格的学生信息\n");
	printf("9. 退出登录\n");
	printf("请输入您的选择：");
	scanf(" %c", &choice);
	switch (choice) {
	case '1':
	n = input(stu);
	break;
	case '2':
	search(stu, n);
	break;
	case '3':
	update(stu, n);
	break;
	case '4':
	del(stu, &n);
	break;
	case '5':
	save(stu, n);
	break;
	case '6':
	sort(stu, n);
	break;
	case '7':
	print_below_avg(stu, n);
	break;
	case '8':
	print_good_failed(stu, n);
	break;
	case '9':
	printf("退出登录成功！\n");
	is_logged_in = 0;
	break;
	default:
	printf("输入错误，请重新输入！\n");
	break;
	}
	}
	}
	return 0;
} 


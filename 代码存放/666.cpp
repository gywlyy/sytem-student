struct student {
    int id;              // ѧ��
    char name[20];       // ����
    char gender[10];     // �Ա�
    float score[5];      // �ɼ�������5�ſγ�
    float total_score;   // �ܷ�
    float avg_score;     // ƽ����
    int rank;            // ����
};

//����һ���༶��ѧ���Ļ�����Ϣ�ͳɼ�
void input_students(struct student stu[], int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        printf("�������%d��ѧ���Ļ�����Ϣ�ͳɼ���\n", i + 1);
        printf("ѧ�ţ�");
        scanf("%d", &stu[i].id);
        printf("������");
        scanf("%s", stu[i].name);
        printf("�Ա�");
        scanf("%s", stu[i].gender);
        printf("5�ſγ̵ĳɼ���");
        for (j = 0; j < 5; j++) {
            scanf("%f", &stu[i].score[j]);
        }
    }
}

//����������ѧ�Ų���ѧ����Ϣ
int search_student(struct student stu[], int n, int id, char name[])
{
    int i;
    for (i = 0; i < n; i++) {
        if ((id > 0 && stu[i].id == id) || (strcmp(stu[i].name, name) == 0)) {
            return i; // ����ѧ���������е��±�
        }
    }
    return -1; // û���ҵ���Ӧ��ѧ��
}

//�޸�ѧ����Ϣ
void modify_student(struct student stu[], int n)
{
    int id;
    char name[20];
    int index;
    printf("������Ҫ�޸�ѧ����ѧ�Ż�������");
    scanf("%d%s", &id, name);
    index = search_student(stu, n, id, name);
    if (index >= 0) {
        printf("�������޸ĺ��ѧ����Ϣ��\n");
        printf("ѧ�ţ�");
        scanf("%d", &stu[index].id);
        printf("������");
        scanf("%s", stu[index].name);
        printf("�Ա�");
        scanf("%s", stu[index].gender);
        printf("5�ſγ̵ĳɼ���");
        int j;
        for (j = 0; j < 5; j++) {
            scanf("%f", &stu[index].score[j]);
        }
    } else {
        printf("û���ҵ���Ӧ��ѧ��\n");
    }
}

//ɾ��ѧ����Ϣ
void delete_student(struct student stu[], int *n)
{
    int id;
    char name[20];
    int index, i;
    printf("������Ҫɾ��ѧ����ѧ�Ż�������");
    scanf("%d%s", &id, name);
    index = search_student(stu, *n, id, name);
    if (index >= 0)
    {
    	for (i = index; i < (*n) - 1; i++) 
		{
        stu[i] = stu[i + 1];
        }
        (*n)--;
        printf("ɾ���ɹ�\n");
    } else {
        printf("û���ҵ���Ӧ��ѧ��\n");
    }

//����ѧ����Ϣ���ļ���
void save_students(struct student stu[], int n, char *filename)
{
    FILE *fp;
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("�޷����ļ�\n");
        return;
    }
    fwrite(stu, sizeof(struct student), n, fp);
    fclose(fp);
}

//���ļ��ж�ȡѧ����Ϣ
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

//����ÿ��ѧ�����Ź����ֺܷ�ƽ���֣���ѧ�Ż��ܷ��������ÿ��ѧ���Ļ�����Ϣ���ܷ֡�ƽ���ֺ�����
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
    printf("%-8s%-12s%-6s%-8s%-8s%-8s%-8s%-8s\n", "ѧ��", "����", "�Ա�", "����", "��ѧ", "Ӣ��", "����", "�ܷ�");
    for (i = 0; i < n; i++) {
        printf("%-8d%-12s%-6s%-8.2f%-8.2f%-8.2f%-8.2f%-8.2f\n",
            stu[i].id, stu[i].name, stu[i].gender,
            stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].score[3],
            stu[i].total_score);
    }
}
``


//����ȫ����Ź��ε�ƽ���֣���ʾÿ�ſγ��е���ƽ���ֵ�ÿһ��ѧ����ѧ�ţ��������Ա𣬿�Ŀ���ɼ�
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
    printf("���ĵ���ƽ���ֵ�ѧ����\n");
    printf("%-8s%-12s%-6s%-8s\n", "ѧ��", "����", "�Ա�", "�ɼ�");
    for (i = 0; i < n; i++) {
        if (stu[i].score[0] < avg[0]) {
            printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[0]);
        }
    }
    printf("��ѧ����ƽ���ֵ�ѧ����\n");
    printf("%-8s%-12s%-6s%-8s\n", "ѧ��", "����", "�Ա�", "�ɼ�");
    for (i = 0; i < n; i++) {
        if (stu[i].score[1] < avg[1]) {
            printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[1]);
        }
    }
    printf("Ӣ�����ƽ���ֵ�ѧ����\n");
    printf("%-8s%-12s%-6s%-8s\n", "ѧ��", "����", "�Ա�", "�ɼ�");
    for (i = 0; i < n; i++) {
        if (stu[i].score[2] < avg[2]) {
            printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[2]);
        }
    }
    printf("�������ƽ���ֵ�ѧ����\n");
    printf("%-8s%-12s%-6s%-8s\n", "ѧ��", "����", "�Ա�", "�ɼ�");
    for (i = 0; i < n; i++) {
        if (stu[i].score[3] < avg[3]) {
            printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[3]);
        }
    }
}

void print_above_90(struct student stu[], int n)
{
    int i, j;
    printf("����90�����ϵ�ѧ����\n");
    printf("%-8s%-12s%-6s%-8s\n", "ѧ��", "����", "�Ա�", "�ɼ�");
    for (i = 0; i < n; i++) {
	if (stu[i].score[0] > 90) {
	printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[0]);
	}
	}
	printf("��ѧ90�����ϵ�ѧ����\n");
	printf("%-8s%-12s%-6s%-8s\n", "ѧ��", "����", "�Ա�", "�ɼ�");
	for (i = 0; i < n; i++) {
	if (stu[i].score[1] > 90) {
	printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[1]);
	}
	}
	printf("Ӣ��90�����ϵ�ѧ����\n");
	printf("%-8s%-12s%-6s%-8s\n", "ѧ��", "����", "�Ա�", "�ɼ�");
	for (i = 0; i < n; i++) {
	if (stu[i].score[2] > 90) {
	printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[2]);
	}
	}
	printf("����90�����ϵ�ѧ����\n");
	printf("%-8s%-12s%-6s%-8s\n", "ѧ��", "����", "�Ա�", "�ɼ�");
	for (i = 0; i < n; i++) {
	if (stu[i].score[3] > 90) {
	printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[3]);
	}
	}
	}
	
	void print_failed(struct student stu[], int n)
	{
	int i, j;
	printf("���Ĳ������ѧ����\n");
	printf("%-8s%-12s%-6s%-8s\n", "ѧ��", "����", "�Ա�", "�ɼ�");
	for (i = 0; i < n; i++) {
	if (stu[i].score[0] < 60) {
	printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[0]);
	}
	}
	printf("��ѧ�������ѧ����\n");
	printf("%-8s%-12s%-6s%-8s\n", "ѧ��", "����", "�Ա�", "�ɼ�");
	for (i = 0; i < n; i++) {
	if (stu[i].score[1] < 60) {
	printf("%-8d%-12s%-6s%-8.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].score[1]);
	}
	}
	printf("Ӣ�ﲻ�����ѧ����\n");
	printf("%-8s%-12s%-6s%-8s\n", "ѧ��", "����", "�Ա�", "�ɼ�");



//������
int main()
{
	struct student stu[MAX_STU];
	int n = 0;
	char choice;
	int is_logged_in = 0;
	char username[20], password[20];
	while (1)
	{
		printf("��ӭʹ��ѧ���ɼ�����ϵͳ��\n");
		printf("��ѡ������Ҫ�Ĳ�����\n");
		printf("1. ��¼\n");
		printf("2. �˳�\n");
		printf("����������ѡ��");
		scanf("%c", &choice);
		switch (choice) {
			case '1':
			if (is_logged_in) 
			{
				printf("���Ѿ���¼�ˣ�\n");
				break;
			}
	printf("�������û��������룺\n");
	scanf("%s%s", username, password);
	if (strcmp(username, "admin") == 0 && strcmp(password, "123456") == 0) {
	is_logged_in = 1;
	printf("��¼�ɹ���\n");
	} else {
	printf("�û������������\n");
	}
	break;
	case '2':
	printf("��ӭ�ٴ�ʹ�ã�\n");
	exit(0);
	default:
	printf("����������������룡\n");
	break;
	}
	while (is_logged_in) {
	printf("��ѡ������Ҫ�Ĳ�����\n");
	printf("1. ¼��ѧ���ɼ�\n");
	printf("2. ����ѧ����Ϣ\n");
	printf("3. �޸�ѧ����Ϣ\n");
	printf("4. ɾ��ѧ����Ϣ\n");
	printf("5. ����ѧ����Ϣ\n");
	printf("6. ����ѧ���ɼ�\n");
	printf("7. ��ʾȫ�����ƽ���ֵ�ѧ����Ϣ\n");
	printf("8. ��ʾ���Ƴɼ�90�����ϺͲ������ѧ����Ϣ\n");
	printf("9. �˳���¼\n");
	printf("����������ѡ��");
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
	printf("�˳���¼�ɹ���\n");
	is_logged_in = 0;
	break;
	default:
	printf("����������������룡\n");
	break;
	}
	}
	}
	return 0;
} 


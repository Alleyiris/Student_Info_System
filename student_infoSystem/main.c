//ѧ����Ϣ����ϵͳ

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
/*����ṹ��*/
typedef struct stu_info
{
	char num[10];//ѧ��
	char name[8];//����
	char sex[2];//�Ա�
	int score;//�ɼ�
	struct stu_info* next;
}stu;

stu* creat(int );//����
void insert(stu* );//����
void delete(stu* );//ɾ��
void search(stu* );//����

int main()
{
	int n;
	printf("/*ѧ����Ϣ����ϵͳ*/\n");
	printf("������ѧ��������");
	scanf("%d", &n);
	getchar();
	/*��������*/
	stu* phead = creat(n);

	/*����ctrl+Z��ֹ����*/
	printf("��Ҫ�������밴�س�\n");
	char c1,c2,c3;
	while ((getchar()) != EOF)
	{
		/*����*/
		printf("�Ƿ�Ҫ������Ϣ����y/n��");
		scanf("%c", &c1);
		getchar();
		if (c1 == 'y')
		{
			insert(phead, n);
			n++;
		}
		/*ɾ��*/
		printf("�Ƿ�Ҫɾ����Ϣ����y/n��");
		scanf("%c", &c2);
		getchar();
		if (c2 == 'y')
		{
			delete(phead);
			n--;
		}
		/*��ѯ*/
		printf("�Ƿ�Ҫ��ѯ��Ϣ����y/n��");
		scanf("%c", &c3);
		getchar();
		if (c3 == 'y')
			search(phead);
		printf("����Ctrl + Z��ֹ����\n��Ҫ�������밴�س�\n");
	}

	/*�ͷ��ڴ�*/
	stu* tmp=phead;
	stu* temp = phead;
	while (temp)
	{
		tmp = temp;
		temp = temp->next;
		free(tmp);
	}
	return 0;
}

/*��������*/
stu* creat(int n)
{
	int i = 0;
	char num[10];//ѧ��
	char name[8];//����
	char sex[2];//�Ա�
	int score;//�ɼ�	
	//����ͷ�ڵ�
	stu* phead = (stu*)malloc(sizeof(stu));
	if (phead == NULL)
	{
		printf("����ʧ��\n");
		exit(-1);
	}
	stu* ptail = phead;
	ptail->next = NULL;
	//��������
	for (i = 0; i < n; i++)
	{
		printf("�������%d��ѧ������Ϣ��\n", i + 1);
		printf("ѧ�ţ�");
		gets(num);
		printf("������");
		gets(name);
		printf("�Ա�");
		gets(sex);
		printf("�ɼ���");
		scanf("%d", &score);
		getchar();
		stu* pnew = (stu*)malloc(sizeof(stu));
		if (pnew == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);
		}
		strcpy(pnew->num, num);//ѧ��
		strcpy(pnew->name, name);//����
		strcpy(pnew->sex, sex);//�Ա�
		pnew->score = score;//�ɼ�
		pnew->next = NULL;
		ptail->next = pnew;
		ptail = pnew;
	}
	return phead;
}
/*������Ϣ*/
void insert(stu* phead, int m)
{
	int i = 1;
	int n;//�ڵ�λ��
	printf("������Ҫ�����λ�ã�");
	scanf("%d", &n);
	getchar();
	stu* tmp = phead;
	stu* temp = phead->next;
	stu* pnew = (stu*)malloc(sizeof(stu));
	char num[10];//ѧ��
	char name[8];//����
	char sex[2];//�Ա�
	int score;//�ɼ�
	if (n < m)
	{
		for (i = 1; i < n; i++)
		{
			tmp = tmp->next;
			temp = tmp->next;
		}
		printf("������%d��ѧ������Ϣ��\n", n);
		printf("ѧ�ţ�");
		gets(num);
		printf("������");
		gets(name);
		printf("�Ա�");
		gets(sex);
		printf("�ɼ���");
		scanf("%d", &score);
		strcpy(pnew->num, num);//ѧ��
		strcpy(pnew->name, name);//����
		strcpy(pnew->sex, sex);//�Ա�
		pnew->score = score;//�ɼ�
		//��tmp��temp֮�����һ���½ڵ�
		tmp->next = pnew;
		pnew->next = temp;
		getchar();//��ջ�����
		printf("����ɹ�\n");
	}
	else if (n == m)
	{
		for (i = 0; i < n; i++)
		{
			tmp = tmp->next;
		}
		printf("������%d��ѧ������Ϣ��\n", n);
		printf("ѧ�ţ�");
		gets(num);
		printf("������");
		gets(name);
		printf("�Ա�");
		gets(sex);
		printf("�ɼ���");
		scanf("%d", &score);
		strcpy(pnew->num, num);//ѧ��
		strcpy(pnew->name, name);//����
		strcpy(pnew->sex, sex);//�Ա�
		pnew->score = score;//�ɼ�
		pnew->next = NULL;
		tmp->next = pnew;
		getchar();//��ջ�����
		printf("����ɹ�\n");
	}
	else
		printf("�����벻����%d����\n", m);
}
/*ɾ����Ϣ*/
void delete(stu* phead)
{
	int i = 0;
	char num[10];//ѧ��
	printf("������Ҫɾ����ѧ��ѧ�ţ�");
	gets(num);
	stu* tmp = phead;
	stu* temp = phead;
	while (tmp)
	{
		//�����������
		if (strcmp(tmp->num, num) != 0)
		{
			temp = tmp;
			tmp = tmp->next;
			if (tmp == NULL)
			{
				printf("ɾ��ʧ�ܣ�\n");
				return;
			}
		}
		else
			break;
	}
	temp->next = tmp->next;
	free(tmp);
	printf("ɾ���ɹ���\n");
}
/*��ѯ��Ϣ*/
void search(stu* phead)
{
	int i = 1;//���ڱ���Ƿ��ѯ��ѧ����Ϣ
	char num[10];//ѧ��
	printf("������Ҫ��ѯѧ����ѧ�ţ�");
	gets(num);

	stu* tmp = phead->next;
	while (tmp)
	{
		if (strcmp(tmp->num, num) == 0)
		{
			i = 0;
			printf("��ѧ����������");
			printf("%s\n", tmp->name);
			printf("��ѧ�����Ա�");
			printf("%s\n", tmp->sex);
			printf("��ѧ���ĳɼ���");
			printf("%d\n", tmp->score);
		}
		tmp = tmp->next;
	}
	if (i)
		printf("δ��ѯ����ѧ����\n");
}
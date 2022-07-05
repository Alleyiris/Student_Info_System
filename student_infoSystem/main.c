//学生信息管理系统

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
/*定义结构体*/
typedef struct stu_info
{
	char num[10];//学号
	char name[8];//姓名
	char sex[2];//性别
	int score;//成绩
	struct stu_info* next;
}stu;

stu* creat(int );//创建
void insert(stu* );//插入
void delete(stu* );//删除
void search(stu* );//查找

int main()
{
	int n;
	printf("/*学生信息管理系统*/\n");
	printf("请输入学生个数：");
	scanf("%d", &n);
	getchar();
	/*创建链表*/
	stu* phead = creat(n);

	/*键入ctrl+Z终止程序*/
	printf("若要继续，请按回车\n");
	char c1,c2,c3;
	while ((getchar()) != EOF)
	{
		/*插入*/
		printf("是否要插入信息？（y/n）");
		scanf("%c", &c1);
		getchar();
		if (c1 == 'y')
		{
			insert(phead, n);
			n++;
		}
		/*删除*/
		printf("是否要删除信息？（y/n）");
		scanf("%c", &c2);
		getchar();
		if (c2 == 'y')
		{
			delete(phead);
			n--;
		}
		/*查询*/
		printf("是否要查询信息？（y/n）");
		scanf("%c", &c3);
		getchar();
		if (c3 == 'y')
			search(phead);
		printf("键入Ctrl + Z终止程序\n若要继续，请按回车\n");
	}

	/*释放内存*/
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

/*创建链表*/
stu* creat(int n)
{
	int i = 0;
	char num[10];//学号
	char name[8];//姓名
	char sex[2];//性别
	int score;//成绩	
	//分配头节点
	stu* phead = (stu*)malloc(sizeof(stu));
	if (phead == NULL)
	{
		printf("分配失败\n");
		exit(-1);
	}
	stu* ptail = phead;
	ptail->next = NULL;
	//创建链表
	for (i = 0; i < n; i++)
	{
		printf("请输入第%d个学生的信息：\n", i + 1);
		printf("学号：");
		gets(num);
		printf("姓名：");
		gets(name);
		printf("性别：");
		gets(sex);
		printf("成绩：");
		scanf("%d", &score);
		getchar();
		stu* pnew = (stu*)malloc(sizeof(stu));
		if (pnew == NULL)
		{
			printf("分配失败\n");
			exit(-1);
		}
		strcpy(pnew->num, num);//学号
		strcpy(pnew->name, name);//姓名
		strcpy(pnew->sex, sex);//性别
		pnew->score = score;//成绩
		pnew->next = NULL;
		ptail->next = pnew;
		ptail = pnew;
	}
	return phead;
}
/*插入信息*/
void insert(stu* phead, int m)
{
	int i = 1;
	int n;//节点位置
	printf("请输入要插入的位置：");
	scanf("%d", &n);
	getchar();
	stu* tmp = phead;
	stu* temp = phead->next;
	stu* pnew = (stu*)malloc(sizeof(stu));
	char num[10];//学号
	char name[8];//姓名
	char sex[2];//性别
	int score;//成绩
	if (n < m)
	{
		for (i = 1; i < n; i++)
		{
			tmp = tmp->next;
			temp = tmp->next;
		}
		printf("请插入第%d个学生的信息：\n", n);
		printf("学号：");
		gets(num);
		printf("姓名：");
		gets(name);
		printf("性别：");
		gets(sex);
		printf("成绩：");
		scanf("%d", &score);
		strcpy(pnew->num, num);//学号
		strcpy(pnew->name, name);//姓名
		strcpy(pnew->sex, sex);//性别
		pnew->score = score;//成绩
		//在tmp和temp之间插入一个新节点
		tmp->next = pnew;
		pnew->next = temp;
		getchar();//清空缓冲区
		printf("插入成功\n");
	}
	else if (n == m)
	{
		for (i = 0; i < n; i++)
		{
			tmp = tmp->next;
		}
		printf("请插入第%d个学生的信息：\n", n);
		printf("学号：");
		gets(num);
		printf("姓名：");
		gets(name);
		printf("性别：");
		gets(sex);
		printf("成绩：");
		scanf("%d", &score);
		strcpy(pnew->num, num);//学号
		strcpy(pnew->name, name);//姓名
		strcpy(pnew->sex, sex);//性别
		pnew->score = score;//成绩
		pnew->next = NULL;
		tmp->next = pnew;
		getchar();//清空缓冲区
		printf("插入成功\n");
	}
	else
		printf("请输入不超过%d的数\n", m);
}
/*删除信息*/
void delete(stu* phead)
{
	int i = 0;
	char num[10];//学号
	printf("请输入要删除的学生学号：");
	gets(num);
	stu* tmp = phead;
	stu* temp = phead;
	while (tmp)
	{
		//遍历链表查找
		if (strcmp(tmp->num, num) != 0)
		{
			temp = tmp;
			tmp = tmp->next;
			if (tmp == NULL)
			{
				printf("删除失败！\n");
				return;
			}
		}
		else
			break;
	}
	temp->next = tmp->next;
	free(tmp);
	printf("删除成功！\n");
}
/*查询信息*/
void search(stu* phead)
{
	int i = 1;//用于标记是否查询到学生信息
	char num[10];//学号
	printf("请输入要查询学生的学号：");
	gets(num);

	stu* tmp = phead->next;
	while (tmp)
	{
		if (strcmp(tmp->num, num) == 0)
		{
			i = 0;
			printf("该学生的姓名：");
			printf("%s\n", tmp->name);
			printf("该学生的性别：");
			printf("%s\n", tmp->sex);
			printf("该学生的成绩：");
			printf("%d\n", tmp->score);
		}
		tmp = tmp->next;
	}
	if (i)
		printf("未查询到该学生！\n");
}
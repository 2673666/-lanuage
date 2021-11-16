#define _CRT_SECURE_NO_WARNINGS

#include"contact.h"

////通讯录的初始化（静态)
//void InitContact(Contact* pc)
//{
//	(pc->sz) = 0;
//	memset((pc->data), 0, sizeof(pc->data));//void *memset( void *dest, int c, size_t count );
//}


//通讯录的初始化（动态）
void InitContact(Contact* pc)
{
	pc->data = (Peoinfo*)malloc(DEFAULT_SZ*sizeof(Peoinfo));
	if (pc->data == NULL)
	{
		perror("InitContact");
		printf("通讯录创建失败\n");
		return;
	}
	pc->Capcity = DEFAULT_SZ;
	pc->sz = 0;
}

////联系人的添加（静态）
//void Addpeoinfo(Contact* pc)
//{
//	//首先得判断通讯录是否有联系人
//	if ((pc->sz) == MAX)
//	{
//		printf("通讯录已满，无法添加联系人\n");
//		return;
//	}
//
//	printf("请输入联系人的姓名：->\n");
//	scanf("%s", &(pc->data[pc->sz].name));  //错误示例 scanf("%s\n", &(pc->data[pc->sz].name));
//														//此处的 \n 有碍scanf读取回车键结束输入
//	printf("请输入联系人的电话:->\n");
//	scanf("%s", &(pc->data[pc->sz].number));
//
//	printf("请输入联系人的性别:->\n");
//	scanf("%s", &(pc->data[pc->sz].sex));
//
//	printf("请输入联系人的地址:->\n");
//	scanf("%s", &(pc->data[pc->sz].addr));
//
//	printf("请输入联系人的年龄:->\n");
//	scanf("%d", &(pc->data[pc->sz].age));
//
//	printf("添加联系人成功\n");
//	(pc->sz)++;
//}

//判断通讯录是否需要扩容
//void CheckCapacity(Contact* pc)
//{
//	if (pc->sz == pc->Capcity)
//	{
//		Peoinfo*ptr = (Peoinfo*)realloc(pc->data, (pc->Capcity + INC_SZ) * sizeof(Peoinfo));
//		if (ptr == NULL)
//		{
//			perror("AddContact");
//			printf("扩容失败\n");
//			return;
//		}
//		pc->data = ptr;
//		pc->Capcity += INC_SZ;
//		printf("扩容成功\n");
//	}
//
//}

//动态版本联系人的增加
void Addpeoinfo(Contact* pc)
{
	//首先得判断通讯录是否有空间存放联系人
	//没有则需扩容
	if (pc->sz == pc->Capcity)
	{
		Peoinfo* ptr = (Peoinfo*)realloc(pc->data, (pc->Capcity + INC_SZ) * sizeof(Peoinfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->Capcity += INC_SZ;
			printf("扩容成功\n");
		}
		else
		{
			perror("AddContact");
			printf("扩容失败\n");
			return;
		}
	}

	printf("请输入联系人的姓名:->");
	scanf("%s", &(pc->data[pc->sz].name));  //错误示例 scanf("%s\n", &(pc->data[pc->sz].name));
														//此处的 \n 有碍scanf读取回车键结束输入
	printf("请输入联系人的电话:->");
	scanf("%s", &(pc->data[pc->sz].number));

	printf("请输入联系人的性别:->");
	scanf("%s", &(pc->data[pc->sz].sex));

	printf("请输入联系人的地址:->");
	scanf("%s", &(pc->data[pc->sz].addr));

	printf("请输入联系人的年龄:->");
	scanf("%d", &(pc->data[pc->sz].age));

	printf("添加联系人成功\n");
	(pc->sz)++;
	pc->Capcity++;
}
//删除联系人
void Delpeoinfo(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	//首先得判断通讯录里是否有联系人
	if (pc->sz == 0)
	{
		printf("当前联系人为0，无法进行删除操作\n");
		return;
	}
	printf("请输入要删除的联系人名字\n");
	scanf("%s", name);
	//用户输入想要删除的联系人之后需要查找是否有此联系人，如果有，就返回一个坐标，便于操作
	int pos = Finebyname(pc, name);
	if (pos == -1)
	{
		printf("您要删除的联系人不存在\n");
		return;
	}
	int i = 0;
	for (i=pos; i < pc->sz-1; pos++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("成功删除联系人%s\n", name);
} 

//联系人的查找
static int Finebyname(Contact* pc, char name[])
{
	int i = 0;
	if (pc->sz == 0)
	{
		printf("通讯录暂时还没有联系人\n");
		return 0;
	}
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;//return -1 必须放在for循环外面，防止一次运行就return，结束函数执行
}


//通讯录的打印
void Pricontact(Contact* pc)
{
	int i = 0;
	//打印标题
	printf("%-10s\t%-10s\t%-10s\t%-12s\t%-20s\n", "名字", "性别", "年龄", "电话", "地址");
	//  \t  相当于 tab 键；  %10s（右对齐） 相当于占10个字符空间，%-s （左对齐）相当于占10个字符空间
	for (i = 0; i < (pc->sz); i++)
	{
		printf
		("%-10s\t %-10s\t %-10d\t %-12s\t %-20s\n",
			pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].number,
			pc->data[i].addr
		);
	}
}

//联系人的修改
void Modpeoinfo(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改的联系人名字：->\n");
	scanf("%s", name);

	int pos = Finebyname(pc, name);

	if (pos == -1)
	{
		printf("要修改的联系人不存在,请重新选择\n");
		return;
	}
	printf("请输入修改后联系人的姓名：->\n");
	scanf("%s", &(pc->data[pos].name)); 

	printf("请输入修改后联系人的电话:->\n");
	scanf("%s", &(pc->data[pos].number));

	printf("请输入修改后联系人的性别:->\n");
	scanf("%s", &(pc->data[pos].sex));

	printf("请输入修改后联系人的地址:->\n");
	scanf("%s", &(pc->data[pos].addr));

	printf("请输入修改后联系人的年龄:->\n");
	scanf("%d", &(pc->data[pos].age));

	printf("修改联系人成功\n");
}

//联系人的查找
void Serpeoinfo(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找的联系人名字：->\n");
	scanf("%s", name);
	int pos = Finebyname(pc, name);

	if (pos == -1)
	{
		printf("您查找的联系人不存在");
		return;
	}
	printf("找到了，该联系人信息如下:\n");
	//打印标题
	printf("%-10s\t%-10s\t%-10s\t%-12s\t%-20s\n", "名字","性别", "年龄", "电话", "地址");
	printf
	(
		"%-10s\t%-10s\t%-10d\t%-12s\t%-20s\n",
	pc->data[pos].name,
	pc->data[pos].sex,
	pc->data[pos].age,
	pc->data[pos].number,
	pc->data[pos].addr
	);
}

//通讯录的释放
void DestoryContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->Capcity = 0;
	pc->sz = 0;
}


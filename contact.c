#define _CRT_SECURE_NO_WARNINGS

#include"contact.h"

////ͨѶ¼�ĳ�ʼ������̬)
//void InitContact(Contact* pc)
//{
//	(pc->sz) = 0;
//	memset((pc->data), 0, sizeof(pc->data));//void *memset( void *dest, int c, size_t count );
//}


//ͨѶ¼�ĳ�ʼ������̬��
void InitContact(Contact* pc)
{
	pc->data = (Peoinfo*)malloc(DEFAULT_SZ*sizeof(Peoinfo));
	if (pc->data == NULL)
	{
		perror("InitContact");
		printf("ͨѶ¼����ʧ��\n");
		return;
	}
	pc->Capcity = DEFAULT_SZ;
	pc->sz = 0;
}

////��ϵ�˵���ӣ���̬��
//void Addpeoinfo(Contact* pc)
//{
//	//���ȵ��ж�ͨѶ¼�Ƿ�����ϵ��
//	if ((pc->sz) == MAX)
//	{
//		printf("ͨѶ¼�������޷������ϵ��\n");
//		return;
//	}
//
//	printf("��������ϵ�˵�������->\n");
//	scanf("%s", &(pc->data[pc->sz].name));  //����ʾ�� scanf("%s\n", &(pc->data[pc->sz].name));
//														//�˴��� \n �а�scanf��ȡ�س�����������
//	printf("��������ϵ�˵ĵ绰:->\n");
//	scanf("%s", &(pc->data[pc->sz].number));
//
//	printf("��������ϵ�˵��Ա�:->\n");
//	scanf("%s", &(pc->data[pc->sz].sex));
//
//	printf("��������ϵ�˵ĵ�ַ:->\n");
//	scanf("%s", &(pc->data[pc->sz].addr));
//
//	printf("��������ϵ�˵�����:->\n");
//	scanf("%d", &(pc->data[pc->sz].age));
//
//	printf("�����ϵ�˳ɹ�\n");
//	(pc->sz)++;
//}

//�ж�ͨѶ¼�Ƿ���Ҫ����
//void CheckCapacity(Contact* pc)
//{
//	if (pc->sz == pc->Capcity)
//	{
//		Peoinfo*ptr = (Peoinfo*)realloc(pc->data, (pc->Capcity + INC_SZ) * sizeof(Peoinfo));
//		if (ptr == NULL)
//		{
//			perror("AddContact");
//			printf("����ʧ��\n");
//			return;
//		}
//		pc->data = ptr;
//		pc->Capcity += INC_SZ;
//		printf("���ݳɹ�\n");
//	}
//
//}

//��̬�汾��ϵ�˵�����
void Addpeoinfo(Contact* pc)
{
	//���ȵ��ж�ͨѶ¼�Ƿ��пռ�����ϵ��
	//û����������
	if (pc->sz == pc->Capcity)
	{
		Peoinfo* ptr = (Peoinfo*)realloc(pc->data, (pc->Capcity + INC_SZ) * sizeof(Peoinfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->Capcity += INC_SZ;
			printf("���ݳɹ�\n");
		}
		else
		{
			perror("AddContact");
			printf("����ʧ��\n");
			return;
		}
	}

	printf("��������ϵ�˵�����:->");
	scanf("%s", &(pc->data[pc->sz].name));  //����ʾ�� scanf("%s\n", &(pc->data[pc->sz].name));
														//�˴��� \n �а�scanf��ȡ�س�����������
	printf("��������ϵ�˵ĵ绰:->");
	scanf("%s", &(pc->data[pc->sz].number));

	printf("��������ϵ�˵��Ա�:->");
	scanf("%s", &(pc->data[pc->sz].sex));

	printf("��������ϵ�˵ĵ�ַ:->");
	scanf("%s", &(pc->data[pc->sz].addr));

	printf("��������ϵ�˵�����:->");
	scanf("%d", &(pc->data[pc->sz].age));

	printf("�����ϵ�˳ɹ�\n");
	(pc->sz)++;
	pc->Capcity++;
}
//ɾ����ϵ��
void Delpeoinfo(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	//���ȵ��ж�ͨѶ¼���Ƿ�����ϵ��
	if (pc->sz == 0)
	{
		printf("��ǰ��ϵ��Ϊ0���޷�����ɾ������\n");
		return;
	}
	printf("������Ҫɾ������ϵ������\n");
	scanf("%s", name);
	//�û�������Ҫɾ������ϵ��֮����Ҫ�����Ƿ��д���ϵ�ˣ�����У��ͷ���һ�����꣬���ڲ���
	int pos = Finebyname(pc, name);
	if (pos == -1)
	{
		printf("��Ҫɾ������ϵ�˲�����\n");
		return;
	}
	int i = 0;
	for (i=pos; i < pc->sz-1; pos++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("�ɹ�ɾ����ϵ��%s\n", name);
} 

//��ϵ�˵Ĳ���
static int Finebyname(Contact* pc, char name[])
{
	int i = 0;
	if (pc->sz == 0)
	{
		printf("ͨѶ¼��ʱ��û����ϵ��\n");
		return 0;
	}
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;//return -1 �������forѭ�����棬��ֹһ�����о�return����������ִ��
}


//ͨѶ¼�Ĵ�ӡ
void Pricontact(Contact* pc)
{
	int i = 0;
	//��ӡ����
	printf("%-10s\t%-10s\t%-10s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	//  \t  �൱�� tab ����  %10s���Ҷ��룩 �൱��ռ10���ַ��ռ䣬%-s ������룩�൱��ռ10���ַ��ռ�
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

//��ϵ�˵��޸�
void Modpeoinfo(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸ĵ���ϵ�����֣�->\n");
	scanf("%s", name);

	int pos = Finebyname(pc, name);

	if (pos == -1)
	{
		printf("Ҫ�޸ĵ���ϵ�˲�����,������ѡ��\n");
		return;
	}
	printf("�������޸ĺ���ϵ�˵�������->\n");
	scanf("%s", &(pc->data[pos].name)); 

	printf("�������޸ĺ���ϵ�˵ĵ绰:->\n");
	scanf("%s", &(pc->data[pos].number));

	printf("�������޸ĺ���ϵ�˵��Ա�:->\n");
	scanf("%s", &(pc->data[pos].sex));

	printf("�������޸ĺ���ϵ�˵ĵ�ַ:->\n");
	scanf("%s", &(pc->data[pos].addr));

	printf("�������޸ĺ���ϵ�˵�����:->\n");
	scanf("%d", &(pc->data[pos].age));

	printf("�޸���ϵ�˳ɹ�\n");
}

//��ϵ�˵Ĳ���
void Serpeoinfo(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ���ҵ���ϵ�����֣�->\n");
	scanf("%s", name);
	int pos = Finebyname(pc, name);

	if (pos == -1)
	{
		printf("�����ҵ���ϵ�˲�����");
		return;
	}
	printf("�ҵ��ˣ�����ϵ����Ϣ����:\n");
	//��ӡ����
	printf("%-10s\t%-10s\t%-10s\t%-12s\t%-20s\n", "����","�Ա�", "����", "�绰", "��ַ");
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

//ͨѶ¼���ͷ�
void DestoryContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->Capcity = 0;
	pc->sz = 0;
}


#pragma once
#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1000

#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_NUMBER 12
#define MAX_ADDR 20

//��̬ͨѶ¼
#define DEFAULT_SZ 3
#define INC_SZ 2

// typedef����peoinfo   ���� struct peoinfo ������Ϊ peoinfo
typedef struct Peoinfo	//�ýṹ���ʾÿһ����ϵ��
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char number[MAX_NUMBER];
	char addr[MAX_ADDR];
}Peoinfo;

//��̬�汾��ͨѶ¼
//typedef struct Contact	//�ýṹ���ʾͨѶ¼
//{
//	Peoinfo data[MAX];//�˴�����ϵ�˵�һ������
//	int sz;	//��¼��ǰͨѶ¼����Ч��ϵ�˵�����
//}Contact;

//��̬�汾��ͨѶ¼
typedef struct Contact	//�ýṹ���ʾͨѶ¼
{
	Peoinfo* data;
	int sz;	
	int Capcity;
}Contact;

//ͨѶ¼��ʼ��
void InitContact(Contact* pc);

//�����ϵ��
void Addpeoinfo(Contact* pc);

//ɾ����ϵ��
void Delpeoinfo(Contact* pc);

//��ӡͨѶ·¼
void Pricontact(Contact* pc);

//��ϵ�˵��޸�
void Modpeoinfo(Contact* pc);

//��ϵ�˵Ĳ���
void Serpeoinfo(Contact* pc);

//ͨѶ¼���ͷ�
void DestoryContact(Contact* pc);

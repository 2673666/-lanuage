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

//动态通讯录
#define DEFAULT_SZ 3
#define INC_SZ 2

// typedef……peoinfo   即给 struct peoinfo 重命名为 peoinfo
typedef struct Peoinfo	//该结构体表示每一个联系人
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char number[MAX_NUMBER];
	char addr[MAX_ADDR];
}Peoinfo;

//静态版本的通讯录
//typedef struct Contact	//该结构体表示通讯录
//{
//	Peoinfo data[MAX];//此处是联系人的一个数组
//	int sz;	//记录当前通讯录里有效联系人的数量
//}Contact;

//动态版本的通讯录
typedef struct Contact	//该结构体表示通讯录
{
	Peoinfo* data;
	int sz;	
	int Capcity;
}Contact;

//通讯录初始化
void InitContact(Contact* pc);

//添加联系人
void Addpeoinfo(Contact* pc);

//删除联系人
void Delpeoinfo(Contact* pc);

//打印通讯路录
void Pricontact(Contact* pc);

//联系人的修改
void Modpeoinfo(Contact* pc);

//联系人的查找
void Serpeoinfo(Contact* pc);

//通讯录的释放
void DestoryContact(Contact* pc);

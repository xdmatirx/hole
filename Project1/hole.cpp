#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS

//bool ReadCsvFile(char* filePath)
//{
//    char data[1024];
//    FILE* fp = fopen(filePath, "r");
//    if (!fp)
//    {
//        printf("can't open file\n");
//        return false;
//    }
//    while (!feof(fp))
//    {
//        fscanf(fp, "%s", &data);
//        printf("%s", data);
//        printf("\n");
//    }
//    printf("\n");
//    fclose(fp);
//    return true;
//}

//��������fnameָ���ļ���ȫ�����ݣ�����򲻿��ļ����򷵻�NULL������ʾ���ļ����� 



char* getfileall(char* fname)
{
	FILE* fp;
	char* datalog;
    char* datas;
	char txt[82];
	int filesize;
    int n = 0;

	if ((fp = fopen(fname, "r")) == NULL) {
		printf("���ļ�%s����\n", fname);
		return NULL;
	}

	fseek(fp, 0, SEEK_END);

	filesize = ftell(fp);
    datalog = (char*)malloc(filesize);
    datas = (char*)malloc(filesize);
    datalog[0] = 0;
    datas[0] = 0;

	rewind(fp);
	while ((fgets(txt, 90, fp)) != NULL) {
        strcat(datas, txt);
       /* sscanf(txt,);
        if (txt[72] == 'D' ) {
            strcat(datalog, txt);

        }*/
        /*if (txt[72] == 'D') {
           
        }*/
        
	    //function
       


	}
	fclose(fp);
    return datas;
	//return str;
}

/*
 destin   ��   �����ַ�����
 source   ��   Դ�ַ�����
 start   :   ��ʼ��ȡ��λ�á���ȡֵ��0��ʼ������C�ַ������ص㣻��startΪ���������ʾ���������ȡ����
 maxlen   :   ��ȡ�ĳ��ȡ������ȳ����ַ����ĳ��ȣ����ַ���ʵ�ʳ��ȼ��㡣��
 */
char* substring(char* destin, char* source, int   start, int   maxlen)
{
    char* p;
    char* address;
    int   n = 0; /*�ַ����ĳ���*/
    int   oldstart;
    int   i;

   /* assert((destin != NULL) && (source != NULL));*/

    address = destin;
    /*���ַ�������*/
    p = source;
    while (*p++ != '/0')
    {
        n++;
    }

    /*��startΪ��������Ӻ���ǰ*/
    //if (start < 0)
    //{
    //    /*�����ʼ��λ�ó����ַ������ȣ��򲻽��н�ȡ*/
    //    if (-start > n - 1)
    //    {
    //        return   NULL;
    //    }
    //    oldstart = start;
    //    start = n + start - maxlen + 1;
    //    if (start < 0)
    //    {
    //        start = 0;
    //        maxlen += oldstart;
    //    }
    //}

    /*�����ʼ��λ�ó����ַ������ȣ��򲻽��н�ȡ*/
    if (start > n - 1)
    {
        return   NULL;
    }

    if (start + maxlen > n)
    {
        maxlen = n - start;
    }

    for (i = 0, p = source; i < maxlen; i++)
    {
        *destin++ = *(p + (start++));
    }
    *destin = '/0';

    return   address;
}

int main()
{
	char* p;
	char* fname = "D:\\iges\\testC\\Project1\\Project1\\fanghole.IGS";
	char* delim = "\n";
	char* data;
	char* data3 = "";
	char* want = "126";
	p = getfileall(fname);
	if (p != NULL) {
		printf(p);
        
		/*data = strtok(p, delim);
        substring();
		printf(data);
		data3 = strtok(p+90, delim);
		printf(data3);*/
		
		/*strncpy(data3, data, 3);
		printf(data3);
		if (data3 == want) {
			printf(p);
		}
		*/
	};
    char* m = "ajs126fdkj";

    data3 = strstr(m,want);
    printf(data3);
	//printf("%s" ,strtok(p, delim));
	
	return 0;
}
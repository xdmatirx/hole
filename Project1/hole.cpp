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

//函数返回fname指定文件的全部内容，如果打不开文件，则返回NULL，并显示打开文件错误 



char* getfileall(char* fname)
{
	FILE* fp;
	char* datalog;
    char* datas;
	char txt[82];
	int filesize;
    int n = 0;

	if ((fp = fopen(fname, "r")) == NULL) {
		printf("打开文件%s错误\n", fname);
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
 destin   ：   返回字符串。
 source   ：   源字符串。
 start   :   开始截取的位置。（取值从0开始，保持C字符串的特点；若start为负数，则表示从右往左截取。）
 maxlen   :   截取的长度。（长度超过字符串的长度，按字符串实际长度计算。）
 */
char* substring(char* destin, char* source, int   start, int   maxlen)
{
    char* p;
    char* address;
    int   n = 0; /*字符串的长度*/
    int   oldstart;
    int   i;

   /* assert((destin != NULL) && (source != NULL));*/

    address = destin;
    /*求字符串长度*/
    p = source;
    while (*p++ != '/0')
    {
        n++;
    }

    /*若start为负数，则从后往前*/
    //if (start < 0)
    //{
    //    /*如果开始的位置超过字符串长度，则不进行截取*/
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

    /*如果开始的位置超过字符串长度，则不进行截取*/
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
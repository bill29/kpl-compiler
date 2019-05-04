#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "nhap4_tree.h"
int main(){
	node *root;
	make_tree(&root);
	char str1[]="";
	int nhap=str1[0]-'\0';
	//printf("xin chao den voi chuong trinh cua toi  \n");
	FILE *file;
	file=fopen("vanban.txt","r");
	char ch;
	int line=0;
	int column=0;
	//mình phải đọc là tất cả các kí tự rồi nối lại , vãi đãi
	char str[20];
	int i=0;
	while(feof(file)==0){
		//cứ 1 dấu cách trở đi là một từ mới được đưa vào
		//cứ qua một dấu cách là một column được thêm vào
		//cứ kết thúc một dòng thì dòng đấy được thêm vào
		//cứ hết một dòng thì column lại được reset về 0
		if(isalpha(ch)!=0){
			str[i]=ch;
			i++;
		}
		if((ch-' ')==0||(ch-'\n')==0){
			str[i]='\0';
			if(isalpha(str[0])!=0){
				//printf("%s ",str );
				//printf("%d %d \n ",line,column );
				insert_tree(&root,str,line,column);
			}

			i=0;
			column++;
			if(ch=='\n'){
				line++;
				column=0;
			}
		}
		if(ch=='.'){
			char x=fgetc(file);
			if(isalpha(x)!=0){
				str[i]=ch;
				i++;
				str[i]=x;
				i++;
			}
			else {
				str[i]='\0';
				//printf("%s %d %d \n",str,line,column );
				insert_tree(&root,str,line,column);
				i=0;
				column=0;
			}
		}
		ch=fgetc(file);
	}
	printf("TOI IN TU CAY RA MOT CACH HOAN CHINH NHE \n");
	print_inoder(root);
	return 0;
}
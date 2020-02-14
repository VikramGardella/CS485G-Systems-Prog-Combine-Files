#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void appendAll(FILE* curr, FILE* writeTo){
	char st[999];
//	printf("inside appendAll\n");
	if(curr){
		while(fscanf(curr, "%s", st)!=EOF){
			printf("%s", st);
			fprintf(writeTo, "%s", st);
		}
		fclose(curr);
	}
	if(writeTo){
		while(fscanf(writeTo,"%s", st)!=EOF){
//			printf("about to print writeTo");
			printf("%s\n", st);		//	fprintf(comb, "%s", str);
		}
	}

}

void appendStart(FILE* curr, int en, FILE* writeTo){
	char st[999];
	printf("success if %d = 123\n",en);
	int counter = 0;
	while((fscanf(curr, "%s", st)!=EOF)){
		int sig = (int)(strlen(st));
		while(counter<en&&counter<sig){
			char te = st[counter];
			printf("te variable is %c", te);
			if((counter<sig)&&(counter<(en))){//???
				printf("%d",counter);
				printf("%c",te);
				fprintf(writeTo,"%c",te);
			}
			counter++;
		}
	}
}

void appendEnd(FILE* curr, int en, FILE* writeTo){
	char st[999];
	printf("success if %d = 123\n",en);
	int counter = 0;
	while((fscanf(curr, "%s", st)!=EOF)){
		int sig = (int)(strlen(st));
		while(counter<sig){
			if(counter>=(sig-en)){
				char te = st[counter];
				printf("te variable is %c", te);
				printf("%d",counter);
				printf("%c",te);
				fprintf(writeTo,"%c",te);
			}
			counter++;
		}
	}
}



int main(int argc, char *argv[]){
	int currArg = 1;
	int fileInd = 0;
	FILE* comb = fopen("combined.txt","w");
	printf("Successfully allocated memory for files.\n");
	printf("\n%d\n", argc);
	char str[999];
	FILE* currApp;
	while(currArg < argc){
	char* com = argv[currArg];
	if(argv[currArg]!=NULL)
		if(strcmp(argv[currArg],"-a")==0){
			printf("Planning to apend all of file.\n");
			if((currArg+1) >= argc)
				printf("error");
			else{
				currApp = fopen(argv[currArg+1], "r");
				appendAll(currApp, comb);
			}
		}
		if(com[0]=='-'&&com[1]=='s'&&strlen(com)>2){
			int cInt = 2;
			int digits[10];
			int total = 0;
			int digUsed = 0;
			while(cInt<strlen(com)){
				if(isdigit(com[cInt])){
					digits[(cInt-2)] = com[cInt] - '0';
					digUsed++;
//					printf("\nthis digit is %d\n",digits[cInt-2]);
				}
				cInt++;
			}
//			printf("digits used is %d\n", digUsed);
			int dCount = 0;
			while(dCount<digUsed){
				int calc = 0;
				int power = 1;
				while(calc<dCount){
					power*=10;
					calc++;
				}
//				printf("The corresponding digit is %d\n",digits[digUsed-dCount-1]);
//				printf("The magnitude is %d\n", power);
				total+=(digits[digUsed-dCount-1]*power);
//				printf("total is now %d\n",total);
				dCount++;
			}


			printf("Planning to append first %d bytes.\n", total);
			if((currArg+1) >= argc)
				printf("error\n");
			else{
				currApp = fopen(argv[currArg+1], "r");
				appendStart(currApp, total, comb);
			}
		}
		if(com[0]=='-'&&com[1]=='e'&&strlen(com)>2){
			int cInt = 2;
			int digits[10];
			int total = 0;
			int digUsed = 0;
			while(cInt<strlen(com)){
				if(isdigit(com[cInt])){
					digits[(cInt-2)] = com[cInt] - '0';
					digUsed++;
//					printf("\nthis digit is %d\n",digits[cInt-2]);
				}
				cInt++;
			}
			printf("digits used is %d\n", digUsed);
			int dCount = 0;
			while(dCount<digUsed){
				int calc = 0;
				int power = 1;
				while(calc<dCount){
					power*=10;
					calc++;
				}
//				printf("The corresponding digit is %d\n",digits[digUsed-dCount-1]);
//				printf("The magnitude is %d\n", power);
				total+=(digits[digUsed-dCount-1]*power);
//				printf("total is now %d\n",total);
				dCount++;

			}

			printf("Planning to append last %d bytes.\n", total);
			if((currArg+1) >= argc)
				printf("error\n");
			else{
				currApp = fopen(argv[currArg+1], "r");
				appendEnd(currApp, total, comb);
			}
		}
		currArg+=2;
	}

//	free(inFiles);
	fclose(comb);
}

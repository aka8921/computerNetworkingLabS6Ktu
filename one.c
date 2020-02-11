#include<stdio.h>
#include<unistd.h>
int main(){
int a[2],pid;
pipe(a);
char s[10],s10[10];
pid=fork();
if (pid==0)
    {
    read(a[0],s10,10);
    printf("the entered string is %s\n",s10);
    }
else     if(pid<0)
    printf("error");
else
    {
    scanf("%s",s);
    write(a[1],s,10);
    printf("the string is %s \n",s);
    }
}


#include<stdio.h>
#include<unistd.h>
int main(){
int pid,a[10],b[10];
pipe(a);
pipe(b);
char s1[20],s2[20];
pid=fork();
if (pid>0)
{
printf("enter the string\n");
scanf("%s",s1);
write(a[1],s1,20);
printf("parent is reading\n");
read(b[0],s2,20);
printf("entered string is %s\n",s2);
}
else if(pid==0)
{
printf("child is processing\n");
read(a[0],s1,20);
printf("enter the string is %s\n",s1);
printf("child is writing\n");
printf("enter the string\n");
scanf("%s",s2);
write(b[1],s2,20);
}
else
{
printf("error\n");
}
}


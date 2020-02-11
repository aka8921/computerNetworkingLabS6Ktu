#include<stdio.h>
#include<unistd.h>
int main(){
int i;
int pid,s;
pid=fork();
if (pid==0)
{
printf("even numbers,childprocess\n");
printf("ppid:%d\n",getppid());
for (i=0;i<=10;i++)
{
 sleep(1);
 if (i%2==0)
 { printf("%d",i);
 printf("\n");
}
}
}
else if (pid>0)
{
wait(&s);
printf("odd numbers,parent process\n");
printf("pid:%d\n",getpid());
for (i=0;i<10;i++)
{ 
 
if (i%2!=0)
 {
  printf("%d",i);
 printf("\n");
}
}
}
else

printf("no process is created\n");

}



#include<stdio.h>
#include<unistd.h>
int main(){
    int pid,a[10],b[10];
    pipe(a);
    pipe(b);
    char s1[20],s2[20],s3[20],s4[20];
    pid=fork();
    if (pid>0)
        {
        scanf("%s",s1);
        write(a[1],s1,20);
        read(b[0],s4,20);
        printf("[parent]entered string is %s\n",s4);
        }
    else if(pid==0)
        {
        read(a[0],s2,20);
        printf("[child]entered string is %s\n",s2);
        scanf("%s",s3);
        write(b[1],s3,20);
        }
    else
        {
        printf("error\n");
        }
}


#include<stdio.h>
#include<stdlib.h>
void f(){

    FILE *fp;int i, n=0, k=0;
    
    fp=fopen("source.txt","w");
    
    for (i=0;i<5;i++) fprintf(fp,"%d",i);
    
    fclose(fp);
    
    fp=fopen("source.txt","r");
    
    fscanf(fp,"%d%d",&n,&k);
    
    printf("%d,%d",n,k);
    
    fclose(fp);
    
}

int main(){
    f();
    return 0;
}
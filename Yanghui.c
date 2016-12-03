/*************************************************************************
	>> File Name: Yanghui.c
	>> Author:HuaiShuo 
	>> Created Time: Sat 03 Dec 2016 08:40:41 PM CST
 ************************************************************************/

#include<stdio.h>
main(){
    int a[100][100],n,i,j,k; /*k是用来控制缩进长度的*/    
    printf("Please enter the number of level\n");
    scanf("%d",&n);
    for(i=0;i<100;i++){
        for(j=0;j<=i;j++){
            if(j==0||j==i){
                        a[i][j]=1;
                        
            }  else{
                        a[i][j]=a[i-1][j-1]+a[i-1][j];
                        
            }
                
        }

    }

    for(i=0;i<n;i++){
        
        for(k=1;k<=(n-i);++k)
          printf("   ");/*有三个空格，根据后面输出项的宽度决定，即后面的1/2*/

        for(j=0;j<=i;j++){
            printf("%6d",a[i][j]);/*最好设为偶数个宽度，根据你写的程序，其实4就合适了*/

        }
        printf("\n");

    }
}
//我从网上下载的。

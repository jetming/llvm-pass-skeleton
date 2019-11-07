/*************************************************************************
	> File Name: for_while.c
	> Author: jetming
	> Mail: puzhiming@migu.cn
	> Created Time: Wed 08 May 2019 08:05:25 PM PDT
    > Description: description
 ************************************************************************/
#include<stdio.h>

void test_for()
{
    int a = 0;
    for(int i=0; i< 10; i++){
        a += i; 
    }

}

void test_while()
{
    int i = 0;
    while(i < 10){
        i++;
    }
}

int main()
{
    test_for();
    test_while();

    return 0;
}
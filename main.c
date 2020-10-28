/*******************************************************
**程序描述：学生成绩管理系统V1.0
**日期：2020/10/28
**作业题目：实验五
**score[N],num[N]：分别记录成绩与学号
**score1[N],num1[N]：分别记录初始成绩与学号
**n，inp，i：学生人数，输入操作数字，计数以完成数组输入输出
**sum，avg：数组求和，求平均数
********************************************************/
#include <stdio.h>
#include <stdlib.h>
#define N 30

void InfoInput(long num[],int score[],int n);       //信息输入
void GetSumAvg(int score[],int n);                  //分数求和求平均数
void ArrangeScoreH2L(long num[],int score[],int n); //分数由高到低排序
void ArrangeScoreL2H(long num[],int score[],int n); //分数由低到高排序
void ArrangeNumL2H(long num[],int score[],int n);   //学号由低到高排序
void SearchInfo(long num[],int score[],int n);      //查找学号对应分数、排名
void GetPercentage(int score[],int n);              //获得各成绩所占百分比
void PrintInfo(long num[],int score[],int n);       //打印出初始输入信息

int main()
{
    printf("Number:200210403\n");
    printf("Name:蔡宇双\n");
    printf("Subject No.5 - program No.1\n");

    int score[N],score1[N],n,inp,i;
    long num[N],num1[N];
    do{
        printf("---------------------------------------------\n");
        printf("1.Input record\n");
        printf("2.Calculate total and average score of course\n");
        printf("3.Sort in descending order by score\n");
        printf("4.Sort in ascending order by score\n");
        printf("5.Sort in ascending order by student's ID\n");
        printf("6.Search by student's ID\n");
        printf("7.Statistic analysis\n");
        printf("8.List record\n");
        printf("9.Exit\n");
        printf("---------------------------------------------\n");
        printf("Please enter your choice:");
        scanf("%d",&inp);
        if(inp == 1)
        {
             printf("How many students?");
             scanf("%d",&n);
             InfoInput(num,score,n);
             for(i = 0;i < n;i++)
             {
                 num1[i] = num[i];
                 score1[i] = score[i];
             }
        }
        else if(inp == 2)
             GetSumAvg(score,n);
        else if(inp == 3)
        {
            ArrangeScoreH2L(num,score,n);
            PrintInfo(num,score,n);
        }
        else if(inp == 4)
        {
            ArrangeScoreL2H(num,score,n);
            PrintInfo(num,score,n);
        }
        else if(inp == 5)
        {
            ArrangeNumL2H(num,score,n);
            PrintInfo(num,score,n);
        }
        else if(inp == 6)
        {
            ArrangeScoreH2L(num,score,n);
            SearchInfo(num,score,n);
        }
        else if(inp == 7)
            GetPercentage(score,n);
        else if(inp == 8)
            for(i = 0;i < n;i++)
                printf("%ld %d\n",num1[i],score1[i]);
        else if(inp == 9)
            return 0;
        else
            printf("Wrong number!");
    }while(inp <= 9 && inp >= 1);
    return 0;
}

void InfoInput(long num[],int score[],int n)
{
    int i;
    printf("Please input student's ID and score,format as:(20201111 89)\n");
    for(i = 0;i <= n-1;i++)
        scanf("%ld %d",&num[i],&score[i]);
    printf("Have stored the data successfully,thx!\n");
}

void GetSumAvg(int score[],int n)
{
    int sum = 0;
    int i;
    float avg;
    for(i = 0;i <= n-1;i++)
        sum = sum + score[i];
    printf("Sum of them is %d\n",sum);
    avg = (1.00 * sum) / n;
    printf("Average is %.2f\n",avg);
}

void ArrangeScoreH2L(long num[],int score[],int n)
{
    int temp2,i,j;
    long temp1;
    for(j = 0;j <= n-2;j++)
    {
        for(i = j;i <= n-2;i++)
        {
            if(score[j] <= score[i+1])
            {
                temp2 = score[i+1];
                score[i+1] = score[j];
                score[j] = temp2;

                temp1 = num[i+1];
                num[i+1] = num[j];
                num[j] = temp1;
            }
        }
    }
}

void ArrangeScoreL2H(long num[],int score[],int n)
{
    int temp2,i,j;
    long temp1;
    for(j = 0;j <= n-2;j++)
    {
        for(i = j;i <= n-2;i++)
        {
            if(score[j] >= score[i+1])
            {
                temp2 = score[i+1];
                score[i+1] = score[j];
                score[j] = temp2;

                temp1 = num[i+1];
                num[i+1] = num[j];
                num[j] = temp1;
            }
        }
    }
}

void ArrangeNumL2H(long num[],int score[],int n)
{
    int temp2,i,j;
    long temp1;
    for(j = 0;j <= n-2;j++)
    {
        for(i = j;i <= n-2;i++)
        {
            if(num[j] >= num[i+1])
            {
                temp2 = score[i+1];
                score[i+1] = score[j];
                score[j] = temp2;

                temp1 = num[i+1];
                num[i+1] = num[j];
                num[j] = temp1;
            }
        }
    }
}

void SearchInfo(long num[],int score[],int n)
{
    int k;
    long number;
    printf("Input ID you wanna search:");
    scanf("%ld",&number);
    for(k = 0;k <= n-1;k++)
    {
        if(num[k] == number)
        {
            printf("Rank is %d,Score is %d\n",k+1,score[k]);
            return;
        }
    }
    printf("Not found!\n");
}

void GetPercentage(int score[],int n)
{
    int i,t[5] = {0};
    for(i = 0;i < n;i++)
    {
        if(score[i]>=0&&score[i]<=59)
            t[0]++;
        else if(score[i]>=60&&score[i]<=69)
            t[1]++;
        else if(score[i]>=70&&score[i]<=79)
            t[2]++;
        else if(score[i]>=80&&score[i]<=89)
            t[3]++;
        else if(score[i]>=90&&score[i]<=100)
            t[4]++;
    }
    printf("Excellent(90~100)\t%.2f%%\n",(float)(t[0]*100)/n);
    printf("Good(80~89)      \t%.2f%%\n",(float)(t[1]*100)/n);
    printf("Average(70~79)   \t%.2f%%\n",(float)(t[2]*100)/n);
    printf("Passed(60~69)    \t%.2f%%\n",(float)(t[3]*100)/n);
    printf("Failed(0~59)     \t%.2f%%\n",(float)(t[4]*100)/n);

}

void PrintInfo(long num[],int score[],int n)
{
    int i;
    for(i = 0;i <= n-1;i++)
        printf("%ld %d\n",num[i],score[i]);
}

/*可用十组数据
2020111111 89
2020111113 44
2020111115 67
2020111114 84
2020111112 69
2020111116 76
2020111117 69
2020111119 48
2020111120 82
2020111118 96
           */



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Date.h"
#include "Design.h"
void help(){
  printf("\n1.Day name of a date");
  printf("\n2.Days between two dates");
  printf("\n3.Get age");
  printf("\n4.Get calender of a month of a year");
  printf("\n5.Get calender of a year");
  printf("\n6.Clear screen\n7.Help\n8.Exit\n");
}
void print_month(int m,int y){
  int days=DAYS_IN_MONTH[m-1];
  if(is_leap_year(y) && m==2)
  days++;
  printf("                  ");
  yellow();underline();
  printf("%s",MONTHS[m-1]);
  reset();
  printf("\n\n");
  blue();
  printf("Mon Tue Wed Thu Fri Sat Sun\n\n");
  reset();
  DATE t={.day=1,.month=m,.year=y};
  char *name=get_day_name(t);
  int skip;
  for(int i=0;i<7;i++){
    if(strcmp(DAYS[i],name)==0){
      skip=i;
      break;
    }
  }
  green();
  for(int i=1;i<=skip;i++)
    printf("    ");
  int row=skip;
  for(int i=1;i<=days;i++){
    if(i>9)
    printf("%d  ",i);
    else 
    printf("%d   ",i);
    row++;
    if(row==7){
      printf("\n");
      row=0;
    }
  }
  printf("\n");
  reset();
}
void print_year(int y){
  for(int i=1;i<=12;i++){
    print_month(i,y);
    printf("\n");
  }
}
int main(){
    system("clear");
    red();header();reset();
    green();
    help();
    reset();
    red();
    printf("\n[Note: Enter dates from January 1,1900.Don't enter any dates before the date spcified !! ]\n\n");
    reset();
    int command;
    do{
      blue();
      printf("\nChoice> ");
      reset();
      scanf("%d",&command);
      if(command==1){
        blue();
        printf("Date: ");
        reset();
        DATE t;
        scanf("%d-%d-%d",&t.day,&t.month,&t.year);
        red();
        printf("Day name -- %s.",get_day_name(t));
        reset();
       }
      else if(command==2){
        DATE a,b;
        blue();
        printf("Date 1: ");
        reset();
        scanf("%d-%d-%d",&a.day,&a.month,&a.year);
        blue();
        printf("Date 2: ");
        reset();
        scanf("%d-%d-%d",&b.day,&b.month,&b.year);
        red();
        if(b.year<a.year || (b.year==a.year && b.month<a.month)||(b.year==a.year && b.month==a.month && b.day<a.day))
        printf("Day difference -- %d days.",days_between_dates(b,a));
        else
        printf("Day difference -- %d days.",days_between_dates(a,b));
        reset();
       }
      else if(command==3){
        DATE a,b;
        blue();
        printf("Date of Birth: ");
        reset();
        scanf("%d-%d-%d",&a.day,&a.month,&a.year);
        blue();
        printf("Today: ");
        reset();
        scanf("%d-%d-%d",&b.day,&b.month,&b.year);
        int t_d=days_between_dates(a,b);
        red();
        if(t_d%365==0)
        printf("Age -- %d days -- %d years old.",t_d,t_d/365);
        else
        printf("Age -- %d days -- %d+ years old.",t_d,t_d/365);
        reset();
        }
        else if(command==4){
           blue();
           printf("Month-Year: ");
           reset();
           DATE t;
           scanf("%d-%d%*c",&t.month,&t.year);
           system("clear");
           print_month(t.month,t.year);
           printf("\n\nPress enter to continue...");
           char c;
           scanf("%c",&c);
           system("clear");
        }
        else if(command==5){
           blue();
           printf("Year: ");
           reset();
           DATE t;
           scanf("%d%*c",&t.year);
           system("clear");
           print_year(t.year);
           printf("\n\nPress enter to continue...");
           char c;
           scanf("%c",&c);
           system("clear");
        }
        else if(command==6){
          system("clear");
          red();
          header();
          reset();
        }
       else if(command==7){
          system("clear");
          red();
          header();
          reset();
          green();
          help();
          reset();
       }
       else if(command==8){
         system("clear");
         exit(0);
       }
  } while(command<=8);
    return 0;
}
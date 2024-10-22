#include<stdio.h>
void red(){
    printf("\033[0;31m");
}
void green(){
    printf("\033[0;32m");
}
void yellow(){
    printf("\033[0;33m");
}
void blue(){
    printf("\033[0;34m");
}
void reset(){
    printf("\033[0m");
}
void header(){
    printf("                  ");
    printf("Calender\n\n");
}
void underline(){
    printf("\033[4m");
}
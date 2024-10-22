typedef struct{
   int day;
   int month;
   int year;
} DATE;
int DAYS_IN_MONTH[]={31,28,31,30,31,30,31,31,30,31,30,31};
char *DAYS[]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
char *MONTHS[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
const DATE D={.day=1,.month=1,.year=1900};
int is_leap_year(int y){
    int res;
    if(y%100==0 && y%400==0){
       res=1;
    }
    else if(y%100!=0 && y%4==0){
        res=1;
    }
    else
    res=0;
    return res;
}
int days_between_years(int y1,int y2){
    int res=0;
    int first_leap=0,last_leap=0;
    int i=y1;
    int found=0;
   while(i<=y2){
   if(is_leap_year(i))
   {
      found=1;
      break;
   }
    i++;
  }
   if(found)
   first_leap=i;
   found=0;
   i=y2;
   while(i>=y1){
      if(is_leap_year(i)){
         found=1;
         break;
      }
      i--;
   }
   if(found)
   last_leap=i;
   int total_leap=0;
   if(last_leap==0);
   else{
      total_leap=(last_leap-first_leap)/4+1;
   }
   res=total_leap*366+(y2-y1+1-total_leap)*365; 
  return res;
}
int days_between_months(int m1,int m2){
   int res=0;
   for(int i=m1;i<=m2;i++){
      res+=DAYS_IN_MONTH[i-1];
   }
   return res;
}
int days_between_dates(DATE a,DATE b){
  int res=0;
  if(a.day==b.day && a.month==b.month && a.year==b.year);
  else if(a.day!=b.day && a.month==b.month && a.year==b.year){
    res+=(b.day-a.day);
  }
  else if(a.month!=b.month && a.year==b.year){
       res+=days_between_months(a.month,b.month-1);
       res-=a.day;
       res+=b.day;
       if(is_leap_year(a.year) && (a.month<=2 && a.day<29) && b.month>2) res++;
       if(is_leap_year(a.year) && (a.month==2 && a.day==29) && b.month>2) res++;
}
  else if(a.year!=b.year){
       if(b.year-a.year>1){
          res+=days_between_months(a.month,12);
          res-=a.day;
          res+=days_between_months(1,b.month-1);
          res+=b.day;
          res+=days_between_years(a.year+1,b.year-1);
          if(is_leap_year(a.year) && (a.month<=2 && a.day<29)) res++;
          if(is_leap_year(b.year) && b.month>2) res++;
       }
       else{
          res+=days_between_months(a.month,12);
          res-=a.day;
          res+=days_between_months(1,b.month-1);
          res+=b.day;
          if(is_leap_year(a.year) && (a.month<=2 && a.day<29)) res++;
          if(is_leap_year(b.year) && b.month>2) res++;
       }
  }
  return res;
}
char* get_day_name(DATE a){
   int total_days=days_between_dates(D,a);
   static char *res;
   int rem=total_days%7;
   res=DAYS[rem];
   return res;
}
int years_from_days(int days){
   return days/365;
}
int months_from_days(int days){
   return days/30;
}


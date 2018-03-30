
//【最大公因数和最小公倍数】
int GCD(int a, int b)       //求最大公因数（递归算法）
{
  return b==0?a:GCD(b,a%b); //集更换位置和辗转相除于一身
}

int LCM(int a, int b)       //求最小公倍数
{
  return a * b / GCD(a,b);
}

//【求素数】（编程复杂度最小）
bool IsPrime(int num)
{
  if(num < 2)
    return false;
  for(int i = 2; i < num; i++)
    if(num%i==0)
      return false;
  return true;
}

//【日期变换】进位思想编程复杂度最小
class Date {
public:
  void nextDay()
  {
    day++;
    if(day>daynum[month])       //利用数组将月份与天数对应起来
    {
      if(!(IsLeapYear(year) && month==2 && day==29))
      {
        day = 1;
        month++;
      }
    }
    if(month>12)
    {
      month = 1;
      year++;
    }
  }
  void previousDay()
  {
    day--;
    if(day==0)
    {
      month--;
      if(IsLeapYear(year) && month==2)
        day = 29;
      else
        day = daynum[month];
    }
    if(month==0)
    {
      month = 12;
      year--;
    }
  }
private:
  int year, month, day;
};

//

int GCD(int a, int b)       //求最大公因数
{
  return b==0?a:GCD(b,a%b); //集更换位置和辗转相除于一身
}

int LCM(int a, int b)       //求最小公倍数
{
  return a * b / GCD(a,b);
}


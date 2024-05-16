#include <iostream>


double calculated_salary(int years, double base);

int main ()
{
  int years = 12;
  double base = 10000;
  double bob_salary = calculated_salary( years, base); 
  std::cout << " bob's salary is " << bob_salary << "." << std::endl;
}

double calculated_salary(int years, double base)
{
  double salary;

  if(years <= 5)
    return base;

  else
    {
      salary = base + (base * 0.1 * (double) years);

      if(salary <= (2 * base))
	return salary;

      else //if (salary >= ( 2 * base))
	return (2 * base);
    }
}

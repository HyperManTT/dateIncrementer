#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year)
{
    if(year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            if(year % 400 == 0)
            {
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}


void nextDay(int day, int month, int year)
{
    int monthsWith30 [] = {9, 4, 6, 11};
    if (month == 2)
    {
        if (day == 28)
        {
            if(isLeapYear(year))
            {
                printf("%d-%d-%d", day + 1, month, year);
            }
            else
            {
                printf("%d-%d-%d", 1, 3, year);
            }
        }
        else
        {
            printf("%d-%d-%d", day + 1, month, year);
        }
    }
    else if (month == 12)
    {
        if (day == 31)
        {
            printf("%d-%d-%d", 1, 1, year + 1);
        }
        else
        {
            printf("%d-%d-%d", day + 1, month, year);
        }
    }
    else
    {
        if (day == 30)
        {
            int doesMonthHave30 = 0;
            int i;
            for(i = 0; i < 3; i++)
            {
                if(month == monthsWith30[i])
                {
                    doesMonthHave30 = 1;
                }
            }

            if(doesMonthHave30)
            {
                printf("%d-%d-%d", 1, month + 1, year);
            }
            else
            {
                printf("%d-%d-%d", day + 1, month, year);
            }
        }

        else if(day == 31)
        {
            printf("%d-%d-%d", 1, month + 1, year);
        }

        else
        {
            printf("%d-%d-%d", day + 1, month, year);
        }
    }

}

int main()
{
    int month = 10;
    int year = 2015;
    int day = 31;
    nextDay(day, month, year);
}

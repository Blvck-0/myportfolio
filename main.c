#include <stdio.h>
#include <stdbool.h>


int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 char *months[] = {
    "",
    "January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"
};

int input_year(void) {
    int year;
    printf("Please enter a year: ");
    scanf("%d", &year);
    return year;
}

int determinedaycode(int year)
{
	int daycode;
	int d1, d2, d3;

	d1 = (year - 1.)/ 4.0;
	d2 = (year - 1.)/ 100.;
	d3 = (year - 1.)/ 400.;
	daycode = (year + d1 - d2 + d3) %7;
	return daycode;
}

void set_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        days[2] = 29;
    } else {
        days[2] = 28;
    }
}

void print_calendar(int year, int daycode) {
    int month, day;

    for (month = 1; month <= 12; month++) {
        printf("\n\n%s\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n", months[month]);

        for (day = 1; day <= 1 + daycode * 5; day++) {
            printf(" ");
        }

        for (day = 1; day <= days[month]; day++) {
            printf("%2d", day);

            if ((day + daycode) % 7 > 0) {
                printf("   ");
            } else {
                printf("\n ");
            }
        }

        daycode = (daycode + days[month]) % 7;
    }
    printf("\n");
}

int main(void) {
    int year, daycode;

    year = input_year();
    daycode = determinedaycode(year);
    set_leap_year(year);
    print_calendar(year, daycode);

    return 0;
}

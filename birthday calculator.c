/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

/* ---------- Date validation---------- */

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getMaxDays(int month, int year) {
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2)
        return isLeapYear(year) ? 29 : 28;
    else
        return 31;
}


int readInt(const char *prompt, int min, int max) {
    int value, status, c;

    do {
        printf("%s", prompt);
        status = scanf("%d", &value);

        if (status != 1 || value < min || value > max) {
            printf("Error: enter a number between %d and %d. Try again.\n\n", min, max);
            while ((c = getchar()) != '\n' && c != EOF); /* clear bad input */
            value = min - 1; /* force loop to repeat */
        } else {
            while ((c = getchar()) != '\n' && c != EOF); /* clear trailing newline */
        }
    } while (value < min || value > max);

    return value;
}

/* ---------- Zeller's Congruence ---------- */


int dayOfWeek(int d, int m, int y) {
    if (m < 3) {
        m += 12;
        y -= 1;
    }

    int K = y % 100;
    int J = y / 100;

  
    int h = (d + (13 * (m + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
    return h;
}

/* ---------- good stuff <3 ---------- */

int main(void) {
    const char *days[] = {
        "Saturday", "Sunday", "Monday", "Tuesday",
        "Wednesday", "Thursday", "Friday"
    };

    int year, month, day, max_days;

    printf("=== Day of Birth -> Day of Week Calculator ===\n\n");

    year = readInt("Enter your birth year (e.g. 2005): ", 1, 9999);
    month = readInt("Enter your birth month (1-12): ", 1, 12);

    max_days = getMaxDays(month, year);

    char prompt[80];
    sprintf(prompt, "Enter your day of birth (1-%d): ", max_days);
    day = readInt(prompt, 1, max_days);

    int h = dayOfWeek(day, month, year);

    printf("\nYour date of birth: %02d/%02d/%d\n", day, month, year);
    printf("You were born on a: %s\n", days[h]);
    printf("congratulation!! ^^")

    return 0;
}

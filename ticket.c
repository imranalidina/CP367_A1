#include <stdio.h>
#include <string.h>

int main() {
    char timeOfDay[6];
    int age;
    int price = 0;

    printf("Enter the time (day/night): ");
    scanf("%5s", timeOfDay);

    printf("Enter the age: ");
    scanf("%d", &age);

    if (strcmp(timeOfDay, "day") == 0) {
        if (age >= 4) price = 8;
    } else if (strcmp(timeOfDay, "night") == 0) {
        if (age < 4) price = 0;
        else if (age >= 4 && age <= 16) price = 12;
        else if (age > 16 && age < 55) price = 15;
        else price = 13;
    } else {
        printf("Invalid input for time of day.\n");
        return 1;
    }

    if (age < 4) {
        printf("The ticket price is: free\n");
    } else {
        printf("The ticket price is: $%d\n", price);
    }

    return 0;
}



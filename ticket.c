#include <stdio.h>
#include <string.h>

int main() {
    char timeOfDay[10];
    int age;
    int price;

    printf("Enter the time (day/night): ");
    scanf("%s", timeOfDay);
    printf("Enter the age: ");
    scanf("%d", &age);

    if (strcmp(timeOfDay, "day") == 0) {
        if (age >= 55) {
            price = 13;
        } else if (age >= 4) {
            price = 8;
        } else {
            price = 0; // Free for under 4
        }
    } else if (strcmp(timeOfDay, "night") == 0) {
        if (age >= 55) {
            price = 15;
        } else if (age >= 4) {
            price = 12;
        } else {
            price = 0; // Free for under 4
        }
    } else {
        printf("Invalid input for time of day.\n");
        return 1;
    }

    if (price == 0) {
        printf("The ticket is free.\n");
    } else {
        printf("The ticket price is: $%d\n", price);
    }

    return 0;
}



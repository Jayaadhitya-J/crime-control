#include <stdio.h>
#include <conio.h>
#define MAX_CRIMES 100
#define MAX_NAME 50
#define DESCRIP 50

struct Crime {
    int id;
    char name[MAX_NAME];
    char description[DESCRIP];
    int pincode;
};

int getMaxcrimepincode(struct Crime *arrCri, int crimeCount) {
    int n = crimeCount;
    int i, j, maxElement = 0, count;
    int maxCount = 0;

    if (n < 3) {
        printf("Add a minimum of 3 records.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        count = 1;
        for (j = i + 1; j < n; j++) {
            if (arrCri[j].pincode == arrCri[i].pincode) {
                count++;
                if (count > maxCount) {
                    maxCount = count;
                    maxElement = arrCri[j].pincode;
                }
            }
        }
    }

    return maxElement;
}

int main() {
    struct Crime crimes[MAX_CRIMES] = {
        {1, "Raghu", "Stealing property using force or the threat of force", 560075},
        {2, "Yash", "Unlawful entry into a building with the intent to steal", 560075},
        {3, "Hemanth", "Intentionally causing bodily harm to another person", 636108},
        {4, "Raju", "Deception for personal gain", 560001},
        {5, "Mahesh", "Willful destruction of property", 636001},
    };
    int crimeCount = 5;

    while (1) {
        int choice;

        printf("1. Add a crime\n");
        printf("2. View crimes\n");
        printf("3. Exit\n");
        printf("4. Analyse crimes\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (crimeCount >= MAX_CRIMES) {
                printf("Crime list is full.\n");
                continue;
            }

            printf("Enter name: ");
            scanf("%s", crimes[crimeCount].name);
            printf("Enter description: ");
            scanf("%s", crimes[crimeCount].description);
            printf("Enter pincode: ");
            scanf("%d", &crimes[crimeCount].pincode);
            crimes[crimeCount].id = crimeCount + 1;
            crimeCount++;
            printf("Crime added successfully\n");
        } else if (choice == 2) {
            for (int i = 0; i < crimeCount; i++) {
                printf("ID: %d\n", crimes[i].id);
                printf("Name: %s\n", crimes[i].name);
                printf("Description: %s\n", crimes[i].description);
                printf("PINCODE: %d\n", crimes[i].pincode);
                printf("\n");
            }
        } else if (choice == 3) {
            printf("Thank you for using this code\n");
            break;  // Exit the loop and end the program
        } else if (choice == 4) {
            int pincode = getMaxcrimepincode(crimes, crimeCount);
            if (pincode > 0) {
                printf("PINCODE WITH THE MOST CRIMES: %d\n", pincode);
            } else {
                printf("Not enough records to analyze.\n");
            }
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}

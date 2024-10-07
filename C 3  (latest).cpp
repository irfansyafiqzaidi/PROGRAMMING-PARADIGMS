#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
void makeReservation();
void returnEquipment();
void displayEquipment();
void countEquipment(int*, int*);
int getInteger(const char* prompt);

// array sizes
#define N 16
#define M 2

char equipmentList[N][M][20] = {
    {"soccer ball", "20"},
    {"basketball", "20"},
    {"tennis racket", "15"},
    {"tennis ball", "10"},
    {"badminton racket", "30"},
    {"badminton shuttle", "100"},
    {"volleyball", "20"},
    {"netball", "20"},
    {"chess set", "15"},
    {"scrabble", "30"},
    {"snooker", "20"},
    {"carrom", "50"},
    {"monopoly", "25"},
    {"batu seremban", "10"},
    {"foosball table", "5"},
    {"congkak", "20"},
};

int main() 
{
    int choice;
    do 
    {
        // Display of menu options
        printf("=====================================\n");
        printf(" Sport Equipments Reservation System\n");
        printf("=====================================\n\n");
        printf("  1. Make a reservation\n");
        printf("  2. Return equipment\n");
        printf("  3. View inventory\n");
        printf("  4. Exit\n\n");
        printf("=====================================\n\n");

        choice = getInteger("Enter your choice: ");
        printf("\n");

        switch (choice) 
        {
            case 1:
                makeReservation();
                break;
            case 2: 
                returnEquipment();
                break;
            case 3:     
                printf("\n");
                displayEquipment();
                printf("\n");
                break;
            case 4:       
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

int getInteger(const char* prompt) {
    int value;
    char input[100];
    while (1) {
        printf("%s", prompt);
        if (fgets(input, sizeof(input), stdin) != NULL) {
            if (sscanf(input, "%d", &value) == 1) {
                return value;
            }
        }
        printf("Invalid input. Please enter a number.\n");
    }
}

void makeReservation() 
{
    int student_ID = getInteger("Enter your student ID number: ");
    printf("\n");
    
    displayEquipment();
    
    int equipmentNumber = getInteger("Enter the equipment number: ") - 1; // convert to zero-indexed array
    int units = getInteger("Enter the number of units: ");

    if (equipmentNumber >= 0 && equipmentNumber < N && units > 0 && units <= atoi(equipmentList[equipmentNumber][1])) 
    {
        int current_units = atoi(equipmentList[equipmentNumber][1]);
        sprintf(equipmentList[equipmentNumber][1], "%d", current_units - units);
        printf("\nStudent ID number: %d\n", student_ID);
        printf("Reservation made successfully!\n");
        printf("Please return the equipment within 3 hours.\n\n");
    } 
    else
        printf("Reservation failed. Invalid equipment or units.\n\n");
}

void returnEquipment()
{
    displayEquipment();
    int equipmentNumber = getInteger("Enter the equipment number: ") - 1; // convert to zero-indexed array
    int units = getInteger("Enter the number of units: ");
    
    if (equipmentNumber >= 0 && equipmentNumber < N && units > 0) 
    {
        int current_units = atoi(equipmentList[equipmentNumber][1]);
        sprintf(equipmentList[equipmentNumber][1], "%d", current_units + units);
        printf("\nEquipment returned successfully!\n\n");
    } 
    else
        printf("Return of equipment failed. Invalid equipment or units.\n\n");
}

void displayEquipment() 
{
    int outdoor_count = 0;
    int indoor_count = 0;
    countEquipment(&outdoor_count, &indoor_count);

    printf("=====================================\n");
    printf("       Available equipments:\n");
    printf("=====================================\n\n");
    
    for (int i = 0; i < N; i++) {
        printf("  %d. %s: %s\n", i+1, equipmentList[i][0], equipmentList[i][1]);
    }

    printf("\n=====================================\n");
    printf("Equipment Summary:\n");
    printf("-------------------------------------\n");
    printf("Outdoor Sports Equipment: %d\n", outdoor_count);
    printf("Indoor Sports Equipment: %d\n", indoor_count);
    printf("=====================================\n\n");
}

void countEquipment(int *outdoor, int *indoor) {
    *outdoor = 0;
    *indoor = 0;
    
    for (int i = 0; i < N; i++) {
        if (i < 8) {
            *outdoor += atoi(equipmentList[i][1]);
        } else {
            *indoor += atoi(equipmentList[i][1]);
        }
    }
}
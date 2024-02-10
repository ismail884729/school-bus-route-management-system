#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define STOPS_COUNT 10


struct BusRoute {
    char routeName[50];
    char stops[STOPS_COUNT][50];
    int numStops;
    double distance;
    struct BusRoute* next;
};


struct Admin {
    char username[50];
    char password[50];
    struct Admin* next;
};


struct Parent {
    char username[50];
    char password[50];
    struct Parent* next;
};


void displayMenu();
void addRoute(struct BusRoute** head);
void displayRoutes(struct BusRoute* head);
void registerAdmin(struct Admin** head);
bool adminLogin(struct Admin* head, const char* username, const char* password);
void parentLogin(struct Parent* head);
void trackBus();
void findShortestRoute(struct BusRoute* head);
void findLongestRoute(struct BusRoute* head);


void insertRoute(struct BusRoute** head, const char* routeName, const char stops[][50], int numStops, double distance) {
    struct BusRoute* newNode = (struct BusRoute*)malloc(sizeof(struct BusRoute));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(newNode->routeName, routeName);
    for (int i = 0; i < numStops; ++i) {
        strcpy(newNode->stops[i], stops[i]);
    }
    newNode->numStops = numStops;
    newNode->distance = distance;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct BusRoute* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}


void displayRoutes(struct BusRoute* head) {
    struct BusRoute* current = head;

   
    printf("+------------------------------------------------------+-----------------+\n");
    printf("|                      Route Name                      |    Distance     |\n");
    printf("+------------------------------------------------------+-----------------+\n");

    
    while (current != NULL) {
        printf("| %-50s |   %-12.2lf |\n", current->routeName, current->distance);
        current = current->next;
    }

   
    printf("+------------------------------------------------------+-----------------+\n");
}


void addRoute(struct BusRoute** head) {
    char routeName[50];
    int numStops;
    char stops[STOPS_COUNT][50];
    double distance;

    printf("Enter route name: ");
    scanf("%s", routeName);

    printf("Enter the number of stops: ");
    scanf("%d", &numStops);

    printf("Enter stops (one by one):\n");
    for (int i = 0; i < numStops; ++i) {
        printf("Stop %d: ", i + 1);
        scanf("%s", stops[i]);
    }

    printf("Enter distance for the route: ");
    scanf("%lf", &distance);

    insertRoute(head, routeName, stops, numStops, distance);
    printf("Route added successfully!\n");
}


void registerAdmin(struct Admin** head) {
    char username[50];
    char password[50];
    printf("                        REGISTRATION  OF  ADMIN : \n");
    printf("Enter admin username: ");
    scanf("%s", username);

    printf("Enter admin password: ");
    scanf("%s", password);

    struct Admin* newNode = (struct Admin*)malloc(sizeof(struct Admin));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(newNode->username, username);
    strcpy(newNode->password, password);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Admin* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    printf("Admin registered successfully!\n");
}


bool adminLogin(struct Admin* head, const char* username, const char* password) {
    struct Admin* current = head;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0 && strcmp(current->password, password) == 0) {
            return true; 
        }
        current = current->next;
    }
    return false; 
}


void parentLogin(struct Parent* head) {
    
    printf("Parent login functionality is not implemented yet.\n");
}


void trackBus() {
   
    srand(time(NULL)); 
    double latitude = (rand() % 180) - 90 + (double)rand() / RAND_MAX;
    double longitude = (rand() % 360) - 180 + (double)rand() / RAND_MAX;

    printf("Bus Location - Latitude: %lf, Longitude: %lf\n", latitude, longitude);
}



void findShortestRoute(struct BusRoute* head) {
    printf("Finding the shortest route path...\n");
    
    if (head == NULL) {
        printf("No routes available.\n");
        return;
    }

    struct BusRoute* current = head;
    struct BusRoute* shortestRoute = NULL;
    double minDistance = __DBL_MAX__;

  
    while (current != NULL) {
        if (current->distance < minDistance) {
            minDistance = current->distance;
            shortestRoute = current;
        }
        current = current->next;
    }

    if (shortestRoute != NULL) {
        printf("Shortest route path: %s, Distance: %.2lf\n", shortestRoute->routeName, shortestRoute->distance);
    } else {
        printf("No routes found.\n");
    }
}
   




void findLongestRoute(struct BusRoute* head) {
    printf("Finding the longest route path...\n");
    
    if (head == NULL) {
        printf("No routes available.\n");
        return;
    }

    struct BusRoute* current = head;
    struct BusRoute* longestRoute = NULL;
    double maxDistance = -1;

    // Find the longest route
    while (current != NULL) {
        if (current->distance > maxDistance) {
            maxDistance = current->distance;
            longestRoute = current;
        }
        current = current->next;
    }

    if (longestRoute != NULL) {
        printf("Longest route path: %s, Distance: %.2lf\n", longestRoute->routeName, longestRoute->distance);
    } else {
        printf("No routes found.\n");
    }
}

 


void displayMenu() {
    printf("\nMENU\n");
    printf("1. Add Bus Route\n");
    printf("2. Display Bus Routes\n");
    printf("3. Track Bus\n");
    printf("4. Find Shortest Route Path\n");
    printf("5. Find Longest Route Path\n");
    printf("6. Log out and Register Admin\n");
    printf("7. Exit\n");
}

int main() {
    struct BusRoute* head = NULL;
    struct Admin* adminHead = NULL;

  
    registerAdmin(&adminHead);

    int choice;
    do {
        
        char username[50], password[50];
        printf("                        LOGIN  OF  ADMIN : \n");
        printf("Enter admin username: ");
        scanf("%s", username);
        printf("Enter admin password: ");
        scanf("%s", password);
        if (adminLogin(adminHead, username, password)) {
            printf("Admin login successful.\n");
            do {
                displayMenu();
                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch (choice) {
                    case 1:
                        addRoute(&head);
                        break;
                    case 2:
                        displayRoutes(head);
                        break;
                    case 3:
                        trackBus();
                        break;
                    case 4:
                        findShortestRoute(head);
                        break;
                    case 5:
                        findLongestRoute(head);
                        break;
                    case 6:
                        printf("Logging out and moving to registration of admin.\n");
                        // Resetting adminHead to NULL
                        adminHead = NULL;
                        registerAdmin(&adminHead);
                        break;
                    case 7:
                        printf("Exiting admin panel.\n");
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }
            } while (choice != 7);
        } else {
            printf("Invalid admin credentials.\n");
        }
    } while (1);

  
    struct BusRoute* current = head;
    while (current != NULL) {
        struct BusRoute* temp = current;
        current = current->next;
        free(temp);
    }

  
    struct Admin* adminCurrent = adminHead;
    while (adminCurrent != NULL) {
        struct Admin* temp = adminCurrent;
        adminCurrent = adminCurrent->next;
        free(temp);
    }

    return 0;
}

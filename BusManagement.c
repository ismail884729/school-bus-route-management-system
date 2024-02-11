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

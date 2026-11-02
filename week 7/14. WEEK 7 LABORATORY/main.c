#include <stdio.h>
#include <string.h>

int main() {
    // Character arrays to store input data (Lab Task 1)
    char supplier_name[100] = "";
    char email[100] = "";
    char phone[50] = "";
    char town[50] = "";
    
    // Auxiliary arrays for backup string and sentence building
    char backup_name[100] = "";
    char description[250] = "";
    
    int choice;
    char search_query[100];
    int has_supplier = 0; // Guard variable to track if data exists

    do {
        // Lab Task 6 Main Interface System
        printf("\n================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Supplier\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // Flush trailing newline from buffer

        switch(choice) {
            case 1:
                // LAB TASK 1: Input collection
                printf("\nEnter supplier name: ");
                fgets(supplier_name, sizeof(supplier_name), stdin);
                supplier_name[strcspn(supplier_name, "\n")] = 0; // Strip trailing newline

                printf("Enter email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0;

                printf("Enter phone: ");
                fgets(phone, sizeof(phone), stdin);
                phone[strcspn(phone, "\n")] = 0;

                printf("Enter town: ");
                fgets(town, sizeof(town), stdin);
                town[strcspn(town, "\n")] = 0;

                // LAB TASK 4: Copying Supplier Information
                strcpy(backup_name, supplier_name);
                
                has_supplier = 1;
                printf("\nSupplier added successfully!\n");
                printf("[Backup Verification] Copied Name: %s\n", backup_name);
                break;

            case 2:
                if (!has_supplier) {
                    printf("\nNo supplier data found. Please add a supplier first using option 1.\n");
                } else {
                    // LAB TASK 1: Displaying information
                    printf("\n--- SUPPLIER DETAILS ---\n");
                    printf("Name : %s\n", supplier_name);
                    printf("Email: %s\n", email);
                    printf("Phone: %s\n", phone);
                    printf("Town : %s\n", town);

                    // LAB TASK 2: Determine and print string lengths using strlen()
                    printf("\nSupplier name length: %lu\n", (unsigned long)strlen(supplier_name));
                    printf("Email length: %lu\n", (unsigned long)strlen(email));
                    printf("Town length: %lu\n", (unsigned long)strlen(town));

                    // LAB TASK 5: Construct sentence dynamically using strcpy and strcat
                    strcpy(description, supplier_name);
                    strcat(description, " operates in ");
                    strcat(description, town);
                    strcat(description, ".");
                    printf("\n%s\n", description);
                }
                break;

            case 3:
                // LAB TASK 3: Search using strcmp()
                printf("\nEnter supplier name to search: ");
                fgets(search_query, sizeof(search_query), stdin);
                search_query[strcspn(search_query, "\n")] = 0;

                // Testing against the specified system matches or active user record
                if (strcmp(search_query, "ABC Office Supplies") == 0 || 
                    strcmp(search_query, "Namibia Stationery") == 0 ||
                    (has_supplier && strcmp(search_query, supplier_name) == 0)) {
                    printf("Supplier found.\n");
                } else {
                    printf("Supplier not found.\n");
                }
                break;

            case 4:
                if (!has_supplier) {
                    printf("\nNo active supplier to check. Add one first.\n");
                } else {
                    printf("\nSupplier name length: %lu\n", (unsigned long)strlen(supplier_name));
                }
                break;

            case 5:
                printf("\nExiting Supplier Module. Goodbye!\n");
                break;

            default:
                printf("\nInvalid menu option selected. Try again.\n");
        }
    } while(choice != 5);

    return 0;
}
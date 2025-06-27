#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char task[100];
    int choice;

    while (1) {
        printf("\n1. Add Task\n2. View Tasks\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();  // clear buffer

        if (choice == 1) {
            printf("Enter task: ");
            fgets(task, sizeof(task), stdin);
            fp = fopen("tasks.txt", "a");
            fprintf(fp, "%s", task);
            fclose(fp);
        } else if (choice == 2) {
            fp = fopen("tasks.txt", "r");
            printf("\n--- Your Tasks ---\n");
            while (fgets(task, sizeof(task), fp) != NULL) {
                printf("%s", task);
            }
            fclose(fp);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}

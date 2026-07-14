#include <stdio.h>
#include <string.h>

struct Employee{
    int emp_ID;
    char emp_name[100];
    char emp_role[100];
};

#define max_emp 100
struct Employee emp_table[max_emp];
int current_emp_count=0;

void add_emp()
{
    if(current_emp_count>=max_emp){
        printf("Employee limit reached!\n");
        printf("Cannot add more employees..!");
        return;
    }
    struct Employee new_emp;
    printf("Enter employee ID: ");
    int emp_ID_toadd;
    scanf("%d",&emp_ID_toadd);
    getchar();
    int found=0;
    if(current_emp_count==0){
        new_emp.emp_ID=emp_ID_toadd;
        printf("Enter employee name: ");
        fgets(new_emp.emp_name,sizeof(new_emp.emp_name),stdin);
        new_emp.emp_name[strcspn(new_emp.emp_name, "\n")] = 0;
        printf("Enter employee role: ");
        fgets(new_emp.emp_role,sizeof(new_emp.emp_role),stdin);
        new_emp.emp_role[strcspn(new_emp.emp_role, "\n")] = 0;
        emp_table[current_emp_count]=new_emp;
        current_emp_count++;
    }
    else{
        for(int i=0;i<current_emp_count;i++){
            if(emp_table[i].emp_ID==emp_ID_toadd){
                printf("Employee ID already exists\n");
                printf("Employee record not added\n");
                found=1;
                return;
            }
        }
        if(found==0){
            new_emp.emp_ID=emp_ID_toadd;
            printf("Enter employee name: ");
            fgets(new_emp.emp_name,sizeof(new_emp.emp_name),stdin);
            new_emp.emp_name[strcspn(new_emp.emp_name, "\n")] = 0;
            printf("Enter employee role: ");
            fgets(new_emp.emp_role,sizeof(new_emp.emp_role),stdin);
            new_emp.emp_role[strcspn(new_emp.emp_role, "\n")] = 0;
            emp_table[current_emp_count]=new_emp;
            current_emp_count++;
        }
    }
    printf("Employee record added successfully!\n");
}

void display_emp(){
    if(current_emp_count==0){
        printf("No employee records found.\n");
        return;
    }
    printf("Employee records:\n");
    printf("-----------------------------------------\n");
    printf("ID\tName\t\tRole\n");
    printf("-----------------------------------------\n");
    for(int i=0;i<current_emp_count;i++)
    {
        printf("%d\t%s\t%s\n",emp_table[i].emp_ID,emp_table[i].emp_name,emp_table[i].emp_role);
    }
    printf("-----------------------------------------\n");
}

void delete_emp(){
    if(current_emp_count==0){
        printf("No employee records found.\n");
        return;
    }
    int id_to_delete;
    printf("Enter Employee Id to delete: ");
    scanf("%d",&id_to_delete);
    int found=0;
    for(int i=0;i<current_emp_count;i++){
        if(emp_table[i].emp_ID==id_to_delete){
            for(int j=i;j<current_emp_count-1;j++){
                emp_table[j]=emp_table[j+1];
            }
            current_emp_count--;
            printf("Employee with ID %d deleted successfully\n",id_to_delete);
            found=1;
            break;
        }
    }
    if(found==0){
        printf("Employee with ID %d not found\n",id_to_delete);
    }
}

void search_emp_by_id(){
    if(current_emp_count==0){
        printf("No employee records found.\n");
        return;
    }
    int id_to_search;
    printf("Enter Employee ID to search: ");
    scanf("%d",&id_to_search);
    int found=0;
    for(int i=0;i<current_emp_count;i++){
        if(emp_table[i].emp_ID==id_to_search){
            printf("\nEmployee Found!\n");
            printf("ID: %d\n", emp_table[i].emp_ID);
            printf("Name: %s\n", emp_table[i].emp_name);
            printf("Role: %s\n", emp_table[i].emp_role);
            found = 1;
            break;
        }
    }
    if(found==0){
        printf("Employee with ID %d not found\n",id_to_search);
    }
}

void search_emp_by_name(){
    if(current_emp_count==0){
        printf("No employee records found.\n");
        return;
    }
    char name_to_search[100];
    printf("Enter Employee name to search: ");
    getchar();
    fgets(name_to_search,sizeof(name_to_search),stdin);
    name_to_search[strcspn(name_to_search, "\n")] = 0;
    int found=0;
    for(int i=0;i<current_emp_count;i++){
        if(strcmp(emp_table[i].emp_name,name_to_search)==0){
            printf("\nEmployee Found!\n");
            printf("ID: %d\n", emp_table[i].emp_ID);
            printf("Name: %s\n", emp_table[i].emp_name);
            printf("Role: %s\n", emp_table[i].emp_role);
            found = 1;
            break;
        }
    }
    if(found==0){
        printf("Employee with name '%s' not found\n",name_to_search);
    }
}

int main()
{
    int choice;
    while (1){
        printf("\nEmployee Management System\n");
        printf("1. Add New Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Delete Employee\n");
        printf("4. Search Employee by ID\n");
        printf("5. Search Employee by Name\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                add_emp();
                break;
            case 2:
                display_emp();
                break;
            case 3:
                delete_emp();
                break;
            case 4:
                search_emp_by_id();
                break;
            case 5:
                search_emp_by_name();
                break;
            case 6:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

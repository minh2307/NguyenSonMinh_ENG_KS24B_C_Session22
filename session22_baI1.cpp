#include <stdio.h>
#include <string.h>

struct student {
    char id[50];
    char name[50];
    int age;
};

typedef struct student Student;

void Menu();
void addStudent(Student students[], int *n);
void printStudents(Student students[], int n);
void editStudent(Student students[], int n);
void deleteStudent(Student students[], int *n);
void searchStudent(Student students[], int n);
void sortStudents(Student students[], int n);

int main() {
    int choice, n = 0;
    Student students[100];

    do {
        Menu();
        printf("\nLua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printStudents(students, n);
                break;
            case 2:
                addStudent(students, &n);
                break;
            case 3:
                editStudent(students, n);
                break;
            case 4:
                deleteStudent(students, &n);
                break;
            case 5:
                searchStudent(students, n);
                break;
            case 6:
                sortStudents(students, n);
                break;
            case 7:
                printf("Good bye my love!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    } while (choice != 7);

    return 0;
}

void Menu() {
    printf("\nMenu\n");
    printf("1. In danh sach sinh vien\n");
    printf("2. Them sinh vien\n");
    printf("3. Sua thong tin sinh vien\n");
    printf("4. Xoa sinh vien\n");
    printf("5. Tim kiem sinh vien\n");
    printf("6. Sap xep danh sach sinh vien\n");
    printf("7. Thoat\n");
}

void addStudent(Student students[], int *n) {
    if (*n >= 100) {
        printf("Danh sach sinh vien da day!\n");
        return;
    }

    Student newStudent;
    printf("Nhap ID: ");
    fgets(newStudent.id, 50, stdin);
    printf("Nhap Ten: ");
    fgets(newStudent.name, 50, stdin);
    printf("Nhap Tuoi: ");
    scanf("%d", &newStudent.age);
    getchar();

    students[*n] = newStudent;
    (*n)++;
    printf("Da them sinh vien thanh cong!\n");
}

void printStudents(Student students[], int n) {
    if (n == 0) {
        printf("Danh sach sinh vien trong!\n");
        return;
    }

    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %s %d\n", students[i].id, students[i].name, students[i].age);
    }
}

void editStudent(Student students[], int n) {
    char id[50];
    printf("Nhap ID sinh vien can sua: ");
    fgets(id, 50, stdin);
    id[strcspn(id, "\n")] = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("Nhap Ten moi: ");
            fgets(students[i].name, 50, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = 0;

            printf("Nhap Tuoi moi: ");
            scanf("%d", &students[i].age);
            getchar();

            printf("Sua thong tin thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID %s\n", id);
}

void deleteStudent(Student students[], int *n) {
    char id[50];
    printf("Nhap ID sinh vien can xoa: ");
    fgets(id, 50, stdin);
    id[strcspn(id, "\n")] = 0;

    for (int i = 0; i < *n; i++) {
        if (strcmp(students[i].id, id) == 0) {
            for (int j = i; j < *n - 1; j++) {
                students[j] = students[j + 1];
            }
            (*n)--;
            printf("Xoa sinh vien thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID %s\n", id);
}

void searchStudent(Student students[], int n) {
    char id[50];
    printf("Nhap ID sinh vien can tim: ");
    fgets(id, 50, stdin);
    id[strcspn(id, "\n")] = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("%s %s %d\n", students[i].id, students[i].name, students[i].age);
            return;
        }
    }
    printf("Khong tim thay sinh vien voi ID %s\n", id);
}

void sortStudents(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(students[i].id, students[j].id) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Da sap xep danh sach sinh vien theo ID!\n");
}


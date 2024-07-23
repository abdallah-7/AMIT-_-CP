#include <stdio.h>
#include "STD.h"
#include "SDB.h"

// Counter of number of students in DB
int counter;
// Student DB (Array of Struct of 10 Students)
student studentArray[10];

void initializeDB() {
    counter = 0;
}

/*
 * Descriptions: check if DB is full or not
 * Return:
 *        True --> full
 *        False --> still has places for students to add
 */
bool SDB_IsFull() {
    if (counter == 10) {
        return true;
    }
    return false;
}

/*
 * Descriptions: Get size of used DB
 * Errors handled:
 *              Can't add id that exists
 *              Can't add to full DB
 * Return:
 *        Number of students in DB
 */
uint8 SDB_GetUsedSize() {
    return counter;
}

/*
 * Descriptions: Add students to DB
 * Errors handled:
 *              Can't add id that exists
 *              Can't add to full DB
 * Return:
 *        True --> Added Successfully
 *        False --> Cannot be added
 */

bool SDB_AddEntry() {
    if (!SDB_IsFull()) {
        printf("Enter Student id: ");
        scanf("%d", &studentArray[counter].Student_ID);
        int8 idExists = 0;
        for (int i = 0; i < counter; ++i) {
            if (studentArray[i].Student_ID == studentArray[counter].Student_ID)
                idExists = 1;
        }
        if (!idExists) {
            printf("Enter Student Year: ");
            scanf("%d", &studentArray[counter].Student_year);
            printf("Enter Student Course1_ID: ");
            scanf("%d", &studentArray[counter].Course1_ID);
            printf("Enter Student Course1_grade: ");
            scanf("%d", &studentArray[counter].Course1_grade);
            printf("Enter Student Course2_ID: ");
            scanf("%d", &studentArray[counter].Course2_ID);
            printf("Enter Student Course2_grade: ");
            scanf("%d", &studentArray[counter].Course2_grade);
            printf("Enter Student Course3_ID: ");
            scanf("%d", &studentArray[counter].Course3_ID);
            printf("Enter Student Course3_grade: ");
            scanf("%d", &studentArray[counter].Course3_grade);
            counter++;
            return true;
        } else {    //id Already exists
            printf("Id Already Exist!!!\n");
            return false;
        }
    } else {
        printf("Full DB!!!\n");
        return false;
    }
}

/*
 * Descriptions: Delete students to DB using id
 * Errors handled:
 *              Can't delete id that exists
 *              Can't delete to empty DB
 * Return:
 *          Void
 */
void SDB_DeleteEntry(uint32 id) {
    int8 index = -1;
    //Search for ID
    for (int i = 0; i < counter; ++i) {
        if (studentArray[i].Student_ID == id) {
            index = i;
        }
    }
    //Not found
    if (index == -1) {
        printf("Id not found to delete!!!\n");
    } else {     //Found (EXISTS)
        //shift until Counter - 1
        for (int i = index; i < counter - 1; ++i) {
            studentArray[i] = studentArray[i + 1];
        }
        //Decrement counter (delete student)
        counter--;
        printf("Student of id %d deleted Successfully\n", id);
    }
}

/*
 * Descriptions: get student info from DB using id
 * Errors handled:
 *              Can't get info of id that exists
 * Return:
 *         True --> Read and found
 *         False --> Cannot Read
 */
bool SDB_ReadEntry(uint32 id) {
    int8 index = -1;
    //Search for ID
    for (int8 i = 0; i < counter; ++i) {
        if (studentArray[i].Student_ID == id) {
            index = i;
        }
    }
    //Not found
    if (index == -1) {
        return false;
    } else {     //Found (EXISTS)
        printf("Enter Student id: %d\n", studentArray[index].Student_ID);
        printf("Enter Student Year: %d\n", studentArray[index].Student_year);
        printf("Enter Student Course1_ID: %d\n", studentArray[index].Course1_ID);
        printf("Enter Student Course1_grade: %d\n", studentArray[index].Course1_grade);
        printf("Enter Student Course2_ID: %d\n", studentArray[index].Course2_ID);
        printf("Enter Student Course2_grade: %d\n", studentArray[index].Course2_grade);
        printf("Enter Student Course3_ID: %d\n", studentArray[index].Course3_ID);
        printf("Enter Student Course3_grade: %d\n", studentArray[index].Course3_grade);
        return true;
    }
}

/*
 * Descriptions: List all student IDs from DB
 * Return:
 *         Void
 */
void SDB_GetList(uint8 *count, uint32 *list) {
    *count = counter;
    for (int i = 0; i < counter; ++i) {
        list[i] = studentArray[i].Student_ID;
    }
}

/*
 * Descriptions: Check Existence of Students in DB using id
 * Return:
 *         True --> Exist
 *         False --> Not Exists
 */
bool SDB_IsIdExist(uint32 id) {
    int8 index = -1;
    //Search for ID
    for (int8 i = 0; i < counter; ++i) {
        if (studentArray[i].Student_ID == id) {
            index = i;
        }
    }
    //Not found
    if (index == -1) {
        return false;
    } else {
        return true;
    }
}

/*
 * Descriptions: Input a choice and send to SDB_action function
 * Errors handled:
 *              Entering number >8 or <0
 * Return:
 *         Void
 */
void SDB_APP() {
    printf("choose your Choice from:\n"
           "1. To add entry, enter 1 \n"
           "2. To get used size in database, enter 2\n"
           "3. To read student data, enter 3 \n"
           "4. To get the list of all student IDs, enter 4\n"
           "5. To check is ID is existed, enter 5 \n"
           "6. To delete student data, enter 6\n"
           "7. To check is database is full, enter 7\n"
           "8. To exit enter 0\n"
    );
    while (1) {
        printf("Your Choice is: ");
        uint8 choice;
        scanf("%d", &choice);
        if (choice == 8)
            break;
        else
            SDB_action(choice);
    }
}

/*
 * Descriptions: Action of the choice
 * Return:
 *         Void
 */
void SDB_action(uint8 choice) {
    if (choice == 1) {
        if (SDB_AddEntry()) {
            printf("Student Added Successfully\n");
        } else {
            printf("Student didn't Added\n");
        }
    } else if (choice == 2) {
        printf("Size  used In DB %d out of 10\n", SDB_GetUsedSize());
    } else if (choice == 3) {
        printf("Enter Student id to get data: ");
        uint8 id;
        scanf("%d", &id);
        if (SDB_ReadEntry(id)) {
            printf("Student of id %d Read Successfully\n", id);
        } else {
            printf("Not found to Read!!!\n");
        }
    } else if (choice == 4) {
        uint32 list[10];
        uint8 countOfStudents = 0;
        SDB_GetList(&countOfStudents, list);
        printf("Count = %d\n", countOfStudents);
        for (int8 i = 0; i < countOfStudents; ++i) {
            printf("st %d = %d\n", i + 1, list[i]);
        }
        SDB_GetList(&countOfStudents, list);
    } else if (choice == 5) {
        printf("Enter Student id to check existence: ");
        uint8 id;
        scanf("%d", &id);
        if (SDB_IsIdExist(id))
            printf("The id is Exist\n");
        else
            printf("The id is Not Exist\n");
    } else if (choice == 6) {
        printf("Enter Student id of student be deleted: ");
        uint8 id;
        scanf("%d", &id);
        SDB_DeleteEntry(id);
    } else if (choice == 7) {
        if (SDB_IsFull()) {
            printf("DB is full\n");
        } else {
            printf("DB isn't full --> still have places to add %d more students\n", 10 - counter);
        }
    } else {
        printf("Invalid Entry!!! --> choose from 1 to 8\n");
    }
}

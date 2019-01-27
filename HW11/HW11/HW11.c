#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Customers_t{ /*Customer Struct.*/
	char firstName[10];
	char lastName[10];
	int age;
	char gender[6];
	struct Customers_t *next;
}Customers;

typedef struct Rooms_t{ /*Rooms Struct.*/
	int roomNumber;
	int capacity;
	int floor;
	struct Rooms_t *next;
	Customers *customer;
}Rooms;
void showVacancy(Rooms *Room); /*Function prints all empty rooms.*/
void readRoomsFromFile(Rooms *head); /*Function that read rooms from file.*/
void readCustomersFromFile(); /*Function that read customers from file.*/
void deleteFromFront(Rooms ** headRef); /*Function writes first element of list.*/
void removeRoom(Rooms *head); /*Function that removes room.*/

int main(void){
	Rooms *head = NULL; /*Head pointer.*/
	Customers *cHead = NULL; /*Customer head pointer.*/
	cHead = (Customers*)malloc(sizeof(Customers)); /*Allocating memory for Customers struct.*/
	head = (Rooms*)malloc(sizeof(Rooms));/*Allocating memory for head struct.*/
	readRoomsFromFile(head); /*Reads all rooms infos from file and constructs the linked list.*/
	deleteFromFront(&head); /*When we allocate space for new struct, before sending it to functions all elements are initialized to 0.*/
	/*For that reason we need to delete that first element.*/
	showVacancy(head); /*Showing all empty rooms. */
	readCustomersFromFile(head, cHead); /*Reading Customers from file.*/
	removeRoom(head); /*Removing room from end(For Testing).*/
	removeRoom(head);/*Removing room from end(For Testing).*/
	removeRoom(head);/*Removing room from end(For Testing).*/
	showVacancy(head); /*Printing the room list again after 3 delete process.*/
	free(head);/*Free both heads*/
	free(cHead);/*Free both heads*/
	return 0;
}
void readRoomsFromFile(Rooms *head){
	int i = 0;
	int roomNumBuffer, roomCapacityBuffer, roomFloorBuffer;
	char junk; /*Reading comma character.*/
	FILE *fptr;/*File pointer*/
	fptr = fopen("rooms.txt","r"); /*Opening the file in reading mode.*/
	if(fptr == NULL){
		printf("Error opening file.\n"); /*Printing error message if error occurs*/
		exit(1);
	}
	else{
		while(fscanf(fptr,"%d%c%d%c%d",&roomNumBuffer,&junk, &roomCapacityBuffer,&junk, &roomFloorBuffer) != EOF) {
			Rooms *newNode;
			newNode = (Rooms*) malloc(sizeof(Rooms)); /*Initializing the linked list in temporary newNode method.*/
			newNode -> roomNumber = roomNumBuffer; 
			newNode -> capacity = roomCapacityBuffer;
			newNode -> floor = roomFloorBuffer;
			newNode -> next = NULL;
			Rooms *temp = head;
			while(temp -> next != NULL){
				temp = temp -> next;
			}
			temp -> next = newNode;
		} 
	}
	fclose(fptr);	/*Closing the file pointer.*/
}

void showVacancy(Rooms *room){
	Rooms *temp = room;
	while(temp != NULL){
		printf("Room Number : %d  Room Capacity %d Room Floor %d\n",temp->roomNumber, temp->capacity, temp->floor);
		temp = temp -> next; /*Printing room infos till temp node is not equal to NULL.*/
	}
}

void addRoomToEnd(Rooms *head, int roomNumBuffer, int roomCapacityBuffer, int roomFloorBuffer){
	Rooms *newNode;
	newNode = (Rooms*) malloc(sizeof(Rooms)); /*Initializing the linked list in temporary newNode method.*/
	newNode -> roomNumber = roomNumBuffer;
	newNode -> capacity = roomCapacityBuffer;
	newNode -> floor = roomFloorBuffer;
	newNode -> next = NULL;
	Rooms *temp = head;
	while(temp -> next != NULL){ 
		temp = temp -> next;
	}
	temp -> next = newNode;
}
void addCustomerToEnd(Customers *head, char* firstName, char *lastName, int age, char* gender){
	Customers *newNode;
	newNode = (Customers*) malloc(sizeof(Customers)); /*Initializing the linked list in temporary newNode method.*/
	newNode -> age = age;
	strcpy(newNode->firstName, firstName);
	strcpy(newNode->lastName, lastName);
	strcpy(newNode->gender, gender);
	newNode -> next = NULL;
	Customers *temp = head;
	
	while(temp -> next != NULL){
		temp = temp -> next;
	}
	temp -> next = newNode;
}
void deleteFromFront(Rooms ** headRef){
	Rooms *head = *headRef; /*Incrementing head -> next by one and its equals to our new headRef after initializing.*/
	head = head -> next;
	*headRef = head;
}
void removeRoom(Rooms *head){
	Rooms *temp = head;
	while(temp -> next -> next != NULL){
		temp = temp -> next; /*While temp -> next -> next ! = NULL the loop continues and deletes last element.*/
	}
	temp -> next = NULL; 
}
void readCustomersFromFile(Rooms *head, Customers *chead){
	int roomNumber;
	char firstName[20];
	char lastName[20];
	char gender[6];
	char junk;
	int age;
	Rooms *temp = head; /*Creating temp head otherwise Room linkedlist pointer will always point to next element.*/

	FILE *fptr;/*File pointer*/
	fptr = fopen("customers.txt","r"); /*Opening the file in reading mode.*/
	if(fptr == NULL){
		printf("Error opening file.\n"); /*Printing error message if error occurs*/
		 //room, capacity, floor order.
		exit(1);
	}
	else{ /*Reading %s value in [^,] format because after one point it takes all the line as string.
	So I want to read till it's comma.*/
		while(fscanf(fptr,"%d%c%s%c%[^,]%c%d%c%s",&roomNumber,&junk,firstName,&junk,lastName,&junk,&age,&junk,gender) != EOF) {
				printf("First name: %s\nLast name: %s\nAge: %d\nGender %s\n\n",firstName,lastName,age,gender );
				Customers *newNode;
				newNode = (Customers*) malloc(sizeof(Customers)); /*Initializing the linked list in temporary newNode method.*/
				newNode -> age = age;
				strcpy(newNode->firstName, firstName);
				strcpy(newNode->lastName, lastName);
				strcpy(newNode->gender, gender);
				newNode -> next = NULL;
				Customers *tempC = chead;
				
				while(tempC -> next != NULL){
					tempC = tempC -> next;
				}
				tempC -> next = newNode;
				while(head != NULL){
					if(head -> roomNumber == roomNumber){ /*Searching Process.*/
						printf("Found in %d. floor.\n",head->roomNumber); /*Reading room number from customer.txt and searchs
						the same room number in Rooms Linked List. */
						head->customer=newNode;
						printf("***Customer: %s %s\n", head->customer->firstName, head->customer->lastName);
					}
					head = head -> next;
				}
				head = temp; 
			}
		fclose(fptr);
	}
}
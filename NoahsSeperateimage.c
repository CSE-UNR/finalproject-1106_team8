//final Project 
//Authors: Noah Ramos

#include <stdio.h>
#define ROWS 100
#define COLUMNS 100
#define FILENAME_LENGTH 25
FILE *filePtr1 ;

void mainMenu();

void loadImage(int rows, int columns, char loadArr[][columns], int* maxRow, int* maxColumn);

void displayImage(int rows, int columns, char dispArr[][columns]);

void editImage();

void dimImage(int rows, int columns, char dimArr[][columns]);

void brightImage(int rows, int columns, char brightArr[][columns]);

void save(int rows, int columns, char saveArr[][columns]);

int main(){

	mainMenu();	
	
}

void mainMenu(){
	int menuChoice;
	int imageRows, imageColumns;
	char savedImage[ROWS][COLUMNS];
	do{
	printf("**IMAGE EDITOR**\n1: Load image\n2: Display Image\n3: Edit Image\n0: Exit\n\nChoose from one of the above:");
	scanf("%d", &menuChoice);
	switch(menuChoice){
		case 1:loadImage(ROWS, COLUMNS, savedImage, &imageRows, &imageColumns);
			printf("the rows are %d, and columns are %d\n", imageRows, imageColumns);
			int indexRow=0, indexColumn=0;
		for(indexRow;indexRow<imageRows;indexRow++){
			for(indexColumn;indexColumn<imageColumns;indexColumn++){
			printf("%c", savedImage[indexRow][indexColumn]);
			}
		}
	printf("\n");
			break;
		case 2:displayImage(imageRows, imageColumns, savedImage);
			break;
		case 3:editImage(imageRows, imageColumns, savedImage);
			break;
		case 0:printf("\nGoodbye!\n");
			break;
	}
	}while(menuChoice != 0);
}
void loadImage(int rows, int columns, char loadArr[][columns], int* maxRow, int* maxColumn){
	int indexRow=0, indexColumn=0;
	char tempVal;
	char fileName[FILENAME_LENGTH+1];
	printf("this is where the image will be loaded\nWhat is the name of the image file? ");
	scanf("%s", fileName);
	filePtr1= fopen (fileName,"r");
		if(filePtr1 == NULL){
			printf("cannot open file\n");
		}
		else{
		while(fscanf(filePtr1, "%c", &tempVal)==1)
			
			if(tempVal=='\n'){
			indexRow++;
			*maxColumn = indexColumn;
			indexColumn = 0;
			}
			else{
			loadArr[indexRow][indexColumn]=tempVal;
			indexColumn++;
			}
			
			
		}
		 *maxRow = indexRow;

	}
void displayImage(int rows, int columns, char dispArr[][columns]){
	printf("this is where the image will be displayed\n\n");
	printf("the rows are %d, and columns are %d\n", rows, columns);
		int indexRow=0, indexColumn=0;
		for(indexRow;indexRow<rows;indexRow++){
			for(indexColumn;indexColumn<columns;indexColumn++){
			printf("%c", dispArr[indexRow][indexColumn]);
			}
		}
	printf("\n");
}
void editImage(int rows, int columns, char editArr[][columns]){
	int editChoice;
	printf("**EDIT IMAGE**\n");
	printf("1: Brighten image\n");
	printf("2: Dim image\n");
	printf("3: Crop image\n");
	printf("0: Exit\n");
	printf("Choose how you want to edit:");
	scanf("%d", &editChoice);
	
	do{switch(editChoice){
		case 1:brightImage(rows, columns, editArr);
			break;
		case 2:dimImage(rows, columns, editArr);
			break;
		case 3:
			break;
		}
	}while(editChoice!= 0);	
	printf("GoodBye!\n\n");	
}

void dimImage(int rows, int columns, char dimArr[][columns]){
	
}

void brightImage(int rows, int columns, char brightArr[][columns]){

}

void save(int rows, int columns, char saveArr[][columns]){
	char saveChoice;
	printf("would you like to save the edited image?");
	scanf(" %c", &saveChoice);
}




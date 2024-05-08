//Names: Christopher Thrasher and Noah Ramos
//Date: 4/29/24
//Assignment: Final Group Project

#include <stdio.h>

#define MAXWIDTH 100
#define MAXHEIGHT 100
FILE *filePtr1 ;

void loadImage(int rows, int columns, char loadArr[][columns]);

void displayImage(int rows, int columns, char dispArr[][columns]);

void brightenImage(int rows, int columns, char brightArr[][columns]);

void dimImage(int rows, int columns, char dimArr[][columns]);

void saveImage(int rows, int columns, char saveArr[][columns]);

void cropImage(int rows, int columns, char cropArr[][columns]);

void editMenu(int rows, int columns, char editArr[][columns]);

void mainMenu();

int main() {
    char pixels[MAXWIDTH][MAXHEIGHT];
    
    int choice;

    do {
      printf("**ERINSTAGRAM**\n");
      printf("1: Load image\n");
      printf("2: Display image\n");
      printf("3: Edit image\n");
      printf("0: Exit\n");
      printf("\nChoose from one of the options above: ");
      scanf("%d", &choice);

	switch (choice) {
	case 1:
		{
		loadImage(MAXHEIGHT, MAXWIDTH, pixels);
			break;
		}
	case 2:
		displayImage(MAXHEIGHT, MAXWIDTH, pixels);
		printf("\n");
			break;
	case 3:{
		editMenu(MAXHEIGHT, MAXWIDTH, pixels);
	}
	case 0:
	printf("Goodbye!\n");
	break;
	default:
	printf("Invalid option. Please try again.\n\n");
	break;
	}
	} while (choice != 0);

    return 0;
}

void editMenu(int rows, int columns, char editArr[][columns]){
	int width = 0, height = 0, X, Y;
            if (width > 0 && height > 0) {
                int editChoice;
                do {
                printf("**EDITING**\n");
                printf("1: Crop image\n");
                printf("2: Dim image\n");
                printf("3: Brighten image\n");
                printf("0: Return to main menu\n");
                printf("\nChoose from one of the options above: ");
                scanf("%d", &editChoice);

     switch (editChoice) {
     case 1:
     {
     int startA, startB, newWidth, newHeight;
       printf("The image you want to crop is %d x %d.\n", width, height);
       printf("The row and column values start in the upper lefthand corner.\n\n");
       printf("Which column do you want to be the new left side? ");
       scanf("%d", &X);
       printf("\nWhich column do you want to be the new right side? ");
       scanf("%d", &newWidth);
       printf("\nWhich row do you want to be the new top? ");
       scanf("%d", &Y);
       printf("\nWhich row do you want to be the new bottom? ");
       scanf("%d", &newHeight);

       cropImage(MAXHEIGHT, MAXWIDTH, editArr);
       printf("\n");

       char saveChoice;
       printf("Would you like to save the file? (y/n) ");
       scanf(" %c", &saveChoice);
         if (saveChoice == 'y' || saveChoice == 'Y') {
         char filename[100];
         printf("\nWhat do you want to name the image file? (include the extension) ");
         scanf("%s", filename);
         saveImage(MAXHEIGHT, MAXWIDTH, editArr);
         printf("Image successfully saved!\n\n");
         }
         break;
         }
         case 2:
         {
         dimImage(MAXHEIGHT, MAXWIDTH, editArr);
                                        
         char saveChoice;
         printf("Would you like to save the file? (y/n) ");
         scanf(" %c", &saveChoice);
            if (saveChoice == 'y' || saveChoice == 'Y') {
            char filename[100];
            printf("\nWhat do you want to name the image file? (include the extension) ");
            scanf("%s", filename);
            saveImage(MAXHEIGHT, MAXWIDTH, editArr);
            printf("Image successfully saved!\n\n");
            }
            break;
            }
            case 3:
            {
            brightenImage(MAXHEIGHT, MAXWIDTH, editArr);
                                                                               
            char saveChoice;
            printf("Would you like to save the file? (y/n) ");
            scanf(" %c", &saveChoice);
               if (saveChoice == 'y' || saveChoice == 'Y') {
               char filename[100];
               printf("\nWhat do you want to name the image file? (include the extension) ");
               scanf("%s", filename);
               saveImage(MAXHEIGHT, MAXWIDTH, editArr);
               printf("Image successfully saved!\n\n");
              }
               break;
               }
          case 0:
          break;
          default:
          printf("Invalid option. Please try again.\n\n");
          break;
          }
         } 
         while (editChoice != 0);
         }
         else {
         printf("Sorry, no image to edit\n\n");
         }
}

void loadImage(int rows, int columns, char loadArr[][columns]) {
        int index1, index2;
        char tempVal;
        char filename[100];
                printf("What is the name of the image file? ");
                scanf("%s", filename);
        
        FILE *filePtr1 = fopen(filename, "r");
                       if (filePtr1 == NULL) {
                                printf("cannot open file\n");
                                return;
                       }
                       printf("Image successfully loaded!\n");

    
   		 for (index1 = 0; index1 < rows; index1++) {
    			for (index2 = 0; index2 < columns; index2++) {
            
            		if (fscanf(filePtr1, " %c", &tempVal) != 1){
                	break; 
            		}
            		loadArr[index1][index2] = tempVal;
        		}
        		
   		 }

   			fclose(filePtr1);
	}
 

void displayImage(int rows, int columns, char dispArr[][columns]) {
       int index1, index2;

       printf("Image:\n");
       for (index1 = 0; index1 < rows; index1++) {
             for (index2 = 0; index2 < columns; index2++) {
             printf("%c", dispArr[index1][index2]);
          }
          printf("\n"); 
      }
      printf("\n"); 
}

void brightenImage(int rows, int columns, char brightArr[][columns]){

}

void dimImage(int rows, int columns, char dimArr[][columns]){

}

void saveImage(int rows, int columns, char saveArr[][columns]){

}

void cropImage(int rows, int columns, char cropArr[][columns]){
    int startColumn, endColumn, startRow, endRow;

    	printf("Enter the starting column for cropping (0-%d): ", columns - 1);
    	scanf("%d", &startColumn);
    	printf("Enter the ending column for cropping (%d-%d): ", startColumn, columns - 1);
    	scanf("%d", &endColumn);
    	printf("Enter the starting row for cropping (0-%d): ", rows - 1);
    	scanf("%d", &startRow);
    	printf("Enter the ending row for cropping (%d-%d): ", startRow, rows - 1);
    	scanf("%d", &endRow);

    		if (startColumn < 0 || startColumn >= columns ||
        	endColumn < startColumn || endColumn >= columns ||
        	startRow < 0 || startRow >= rows ||
        	endRow < startRow || endRow >= rows) {
        	printf("Invalid crop dimensions. Please try again.\n");
        	return;
    }

    int newWidth = endColumn - startColumn + 1;
    int newHeight = endRow - startRow + 1;

    char croppedArr[MAXHEIGHT][MAXWIDTH];

    	for (int i = startRow; i <= endRow; i++) {
        	for (int j = startColumn; j <= endColumn; j++) {
            	croppedArr[i - startRow][j - startColumn] = cropArr[i][j];
        	}
    	}

    	for (int i = 0; i < newHeight; i++) {
        	for (int j = 0; j < newWidth; j++) {
            	cropArr[i][j] = croppedArr[i][j];
        	}
    	}

    	rows = newHeight;
    	columns = newWidth;

    	printf("Image successfully cropped!\n");
}





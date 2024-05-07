//Names: Christopher Thrasher and Noah Ramos
//Date: 4/29/24
//Assignment: Final Group Project

#include <stdio.h>

#define MAXWIDTH 100
#define MAXHEIGHT 100
FILE *filePtr1 ;

void loadImage(int rows, int columns, int loadArr[][columns]);

void displayImage(int rows, int columns, int dispArr[][columns]);

void brightenImage(int rows, int columns, int brightArr[][columns]);

void dimImage(int rows, int columns, int dimArr[][columns]);

void saveImage(int rows, int columns, int saveArr[][columns]);

void cropImage(int rows, int columns, int cropArr[][columns]);

void editMenu(int rows, int columns, int editArr[][columns]);

void mainMenu();

int main() {
    int pixels[MAXWIDTH][MAXHEIGHT];
    
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
		printf("Image successfully loaded!\n\n");
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

void editMenu(int rows, int columns, int editArr[][columns]){
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

void loadImage(int rows, int columns, int loadArr[][columns]){
	int index1, index2, tempVal;
	char filename[100];
		printf("What is the name of the image file? ");
		scanf("%s", filename);
	printf("the file you want to acess is %s \n", filename);
	filePtr1= fopen (filename,"r");
		if(filePtr1 == NULL){
			printf("cannot open file\n");
			return;
		}
		printf("Image suessfully loaded!\n");
		
		
		for(index1 = 0;index1<rows;index1++){
			for(index2 = 0;index2<columns;index2++){
				}while(loadArr[index1][index2]!= EOF);
					}
				  if (fscanf(filePtr1, "%d", &tempVal) != 1){
                                    printf("Could not find an image with that filename.\n");
				
				    fclose(filePtr1);
                                    return;
                                    loadArr[index1][index2] = tempVal; 
					}
			}
			fclose(filePtr1); 
}
}


void displayImage(int rows, int columns, int dispArr[][columns]){
	for(index1 = 0;index1<rows;index1++){
		for(index2 = 0;index2<columns;index2++){
			if(dispArr[index1][index2]!= '\0')
			printf("%d", dispArr[index1][index2]);
					}
}

void brightenImage(int rows, int columns, int brightArr[][columns]){

}

void dimImage(int rows, int columns, int dimArr[][columns]){

}

void saveImage(int rows, int columns, int saveArr[][columns]){

}

void cropImage(int rows, int columns, int cropArr[][columns]){

}

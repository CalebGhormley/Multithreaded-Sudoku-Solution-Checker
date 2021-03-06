#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define NUM_CHILD_THREADS 27
#define MAX 200

void *runner(void *param);

typedef struct{
    int topRow;
    int bottomRow;
    int leftColumn;
    int rightColumn;
}run_param;

int sudokuPuzzle[9][9];
bool columnBool[9];
bool rowBool[9];
bool subGridBool[9];

int main() {
    FILE *sudokuAnswer;
    int fileBuff[MAX];

    //pthread_t tid_column[9];
    //pthread_t tid_row[9];
    //pthread_t tid_subGrid[9];
    pthread_t tid[NUM_CHILD_THREADS]; /* the thread identifier for child threads */
    pthread_attr_t attr[NUM_CHILD_THREADS]; /* set of attributes for the thread */
    run_param thrParam[NUM_CHILD_THREADS];

    sudokuAnswer = fopen("SudokuPuzzle.txt", "r");
    if(sudokuAnswer == NULL) {
        printf("Error: Unable to open 'SudokuPuzzle.txt");
        exit(1);
    }
    for (int i = 0; i < MAX; i++) {
        //May need to check for eof
        fileBuff[i] = fgetc(sudokuAnswer);
    }
    fclose(sudokuAnswer);
    int colNum = 0, rowNum = 0, index = 0;
    while(rowNum < 9 && index < MAX){
        if(fileBuff[index] == '1' || fileBuff[index] == '2' || fileBuff[index] == '3'
           || fileBuff[index] == '4' || fileBuff[index] == '5' || fileBuff[index] == '6'
           || fileBuff[index] == '7' || fileBuff[index] == '8' || fileBuff[index] == '9'){
            sudokuPuzzle[colNum][rowNum] = fileBuff[index];
            colNum++;
            if(colNum == 9){
                colNum = 0;
                rowNum++;
            }
        }
        index++;
    }
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            printf("%c\t", sudokuPuzzle[j][i]);
        }
        printf("\n");
    }

    /* get the default attributes */
    for (int i = 0; i < NUM_CHILD_THREADS; i++)
        pthread_attr_init(&(attr[i]));

    /*Create structures for child threads*/
    run_param columnOne, columnTwo, columnThree, columnFour, columnFive, columnSix, columnSeven, columnEight, columnNine;
    columnOne.topRow = 0; columnOne.bottomRow = 8; columnOne.leftColumn = 0; columnOne.rightColumn = 0;
    columnTwo.topRow = 0; columnTwo.bottomRow = 8; columnTwo.leftColumn = 1; columnTwo.rightColumn = 1;
    columnThree.topRow = 0; columnThree.bottomRow = 8; columnThree.leftColumn = 2; columnThree.rightColumn = 2;
    columnFour.topRow = 0; columnFour.bottomRow = 8; columnFour.leftColumn = 3; columnFour.rightColumn = 3;
    columnFive.topRow = 0; columnFive.bottomRow = 8; columnFive.leftColumn = 4; columnFive.rightColumn = 4;
    columnSix.topRow = 0; columnSix.bottomRow = 8; columnSix.leftColumn = 5; columnSix.rightColumn = 5;
    columnSeven.topRow = 0; columnSeven.bottomRow = 8; columnSeven.leftColumn = 6; columnSeven.rightColumn = 6;
    columnEight.topRow = 0; columnEight.bottomRow = 8; columnEight.leftColumn = 7; columnEight.rightColumn = 7;
    columnNine.topRow = 0; columnNine.bottomRow = 8; columnNine.leftColumn = 8; columnNine.rightColumn = 8;

    run_param rowOne, rowTwo, rowThree, rowFour, rowFive, rowSix, rowSeven, rowEight, rowNine;
    rowOne.topRow = 0; rowOne.bottomRow = 0; rowOne.leftColumn = 0; rowOne.rightColumn = 8;
    rowTwo.topRow = 1; rowTwo.bottomRow = 1; rowTwo.leftColumn = 0; rowTwo.rightColumn = 8;
    rowThree.topRow = 2; rowThree.bottomRow = 2; rowThree.leftColumn = 0; rowThree.rightColumn = 8;
    rowFour.topRow = 3; rowFour.bottomRow = 3; rowFour.leftColumn = 0; rowFour.rightColumn = 8;
    rowFive.topRow = 4; rowFive.bottomRow = 4; rowFive.leftColumn = 0; rowFive.rightColumn = 8;
    rowSix.topRow = 5; rowSix.bottomRow = 5; rowSix.leftColumn = 0; rowSix.rightColumn = 8;
    rowSeven.topRow = 6; rowSeven.bottomRow = 6; rowSeven.leftColumn = 0; rowSeven.rightColumn = 8;
    rowEight.topRow = 7; rowEight.bottomRow = 7; rowEight.leftColumn = 0; rowEight.rightColumn = 8;
    rowNine.topRow = 8; rowNine.bottomRow = 8; rowNine.leftColumn = 0; rowNine.rightColumn = 8;

    run_param subOne, subTwo, subThree, subFour, subFive, subSix, subSeven, subEight, subNine;
    subOne.topRow = 0; subOne.bottomRow = 2; subOne.leftColumn = 0; subOne.rightColumn = 2;
    subTwo.topRow = 0; subTwo.bottomRow = 2; subTwo.leftColumn = 3; subTwo.rightColumn = 5;
    subThree.topRow = 0; subThree.bottomRow = 2; subThree.leftColumn = 6; subThree.rightColumn = 8;
    subFour.topRow = 3; subFour.bottomRow = 5; subFour.leftColumn = 0; subFour.rightColumn = 2;
    subFive.topRow = 3; subFive.bottomRow = 5; subFive.leftColumn = 3; subFive.rightColumn = 5;
    subSix.topRow = 3; subSix.bottomRow = 5; subSix.leftColumn = 6; subSix.rightColumn = 8;
    subSeven.topRow = 6; subSeven.bottomRow = 8; subSeven.leftColumn = 0; subSeven.rightColumn = 2;
    subEight.topRow = 6; subEight.bottomRow = 8; subEight.leftColumn = 3; subEight.rightColumn = 5;
    subNine.topRow = 6; subNine.bottomRow = 8; subNine.leftColumn = 6; subNine.rightColumn = 8;

    thrParam[0] = columnOne;
    thrParam[1] = columnTwo;
    thrParam[2] = columnThree;
    thrParam[3] = columnFour;
    thrParam[4] = columnFive;
    thrParam[5] = columnSix;
    thrParam[6] = columnSeven;
    thrParam[7] = columnEight;
    thrParam[8] = columnNine;
    thrParam[9] = rowOne;
    thrParam[10] = rowTwo;
    thrParam[11] = rowThree;
    thrParam[12] = rowFour;
    thrParam[13] = rowFive;
    thrParam[14] = rowSix;
    thrParam[15] = rowSeven;
    thrParam[16] = rowEight;
    thrParam[17] = rowNine;
    thrParam[18] = subOne;
    thrParam[19] = subTwo;
    thrParam[20] = subThree;
    thrParam[21] = subFour;
    thrParam[22] = subFive;
    thrParam[23] = subSix;
    thrParam[24] = subSeven;
    thrParam[25] = subEight;
    thrParam[26] = subNine;

    /* create the threads */
    for (int i = 0; i < NUM_CHILD_THREADS; i++)
    {
        pthread_create(&(tid[i]),&(attr[i]),runner, &(thrParam[i]));
    }

    /* now wait for the thread to exit */
    for (int i = 0; i < NUM_CHILD_THREADS; i++) {
        pthread_join(tid[i], NULL);
    }

    // display results
    for(int i = 0; i < 9; i++){
        if(columnBool[i] == true){
            printf("Column: %lX valid\n", tid[i]);
        }
        else
            printf("Column: %lX invalid\n", tid[i]);
    }
    for(int i = 0; i < 9; i++){
        if(rowBool[i] == true){
            printf("Row: %lX valid\n", tid[i+9]);
        }
        else
            printf("Row: %lX invalid\n", tid[i+9]);
    }
    for(int i = 0; i < 9; i++){
        if(rowBool[i] == true){
            printf("Subgrid: %lX valid\n", tid[i+18]);
        }
        else
            printf("Subgrid: %lX invalid\n", tid[i+18]);
    }
    bool puzzleCheck = true;
    for(int i = 0; i < 9; i++){
        if(columnBool[i] == false)
            puzzleCheck = false;
    }
    for(int i = 0; i < 9; i++){
        if(rowBool[i] == false)
            puzzleCheck = false;
    }
    for(int i = 0; i < 9; i++){
        if(subGridBool[i] == false)
            puzzleCheck = false;
    }
    if(puzzleCheck == true)
        printf("Sudoku Puzzle: valid\n");
    else
        printf("Sudoku PuzzleL invalid\n");

    return 0;
}

/**
 * The thread will begin control in this function
 */
void *runner(void *param)
{
    run_param *inP;
    pthread_t self;
    inP = (run_param *)param;
    bool checker[9];
    bool threadResult = true;

    for(int i = 0; i < 9; i++){
        checker[i] = false;
    }
    for(int i = inP->leftColumn; i <= inP->rightColumn; i++){
        for(int j = inP->topRow; j <= inP->bottomRow; j++){
            checker[(sudokuPuzzle[i][j] - 49)] = true;
        }
    }
    printf("\n");
    for(int i = 0; i < 9; i++){
        if (checker[i] == false) {
            threadResult = false;
        }
    }
    printf("\n");
    if(threadResult == true) {
        if (inP->leftColumn == inP->rightColumn)
            columnBool[inP->leftColumn] = true;
        else if (inP->topRow == inP->bottomRow)
            rowBool[inP->topRow] = true;
        else {
            if (inP->topRow == 0 && inP->leftColumn == 0)
                subGridBool[0] = true;
            else if (inP->topRow == 0 && inP->leftColumn == 3)
                subGridBool[1] = true;
            else if (inP->topRow == 0 && inP->leftColumn == 6)
                subGridBool[2] = true;
            else if (inP->topRow == 3 && inP->leftColumn == 0)
                subGridBool[3] = true;
            else if (inP->topRow == 3 && inP->leftColumn == 3)
                subGridBool[4] = true;
            else if (inP->topRow == 3 && inP->leftColumn == 6)
                subGridBool[5] = true;
            else if (inP->topRow == 6 && inP->leftColumn == 0)
                subGridBool[6] = true;
            else if (inP->topRow == 6 && inP->leftColumn == 3)
                subGridBool[7] = true;
            else if (inP->topRow == 6 && inP->leftColumn == 6)
                subGridBool[8] = true;
            else
                printf("Sub grid check is incorrect\n");
        }
    }
    self = pthread_self();
    if(threadResult == true) {
        printf("%lX TRow: %d BRow: %d LCol: %d RCol: %d valid!\n", (unsigned long) self, inP->topRow, inP->bottomRow,
               inP->leftColumn, inP->rightColumn);
    }
    else
        printf("%lX TRow: %d BRow: %d LCol: %d RCol: %d invalid!\n", (unsigned long) self, inP->topRow, inP->bottomRow,
               inP->leftColumn, inP->rightColumn);
    pthread_exit(0);
}
/*
 * Calories Burned Calculator
 * author: Rosalba Monterrosas
 * date: June 18, 2018
 * description: Calculates the total calories burned, as well as other related outputs, while casual walking. 
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXIMUM_ATTEMPTS 10

void banner();
void getInputs(double* pWeight,int* pHeightFeet,double* pHeightInches,int* pSteps);
void calculateOutputs(double* pWeight,int* pHeightFeet,double* pHeightInches,double* pStrideLengthInches,double* pCaloriesPerMile,double* pStepsPerMile,double* pCaloriesPerStep,double* pTotalCalories,int* pSteps,int iAttempt,int* pSize,double* pCaloriesPerMileArray, double* pStrideLengthInchesArray,double* pStepsPerMileArray,double* pCaloriesPerStepArray,double* pTotalCaloriesArray);
void printOne(double dCaloriesPerMile,double dStrideLengthInches, double dStepsPerMile, double dCaloriesPerStep, double dTotalCalories, char* sCategory);
int tryAgain(int iAttempt);
void printAll(int iSize,double* pCaloriesPerMileArray, double* pStrideLengthInchesArray,double* pStepsPerMileArray,double* pCaloriesPerStepArray,double* pTotalCaloriesArray, char** categoryArray);
void categorize(double dTotalCalories, char** categoryArray, int iAttempt);

void banner(){
//Prints a banner

    printf("\nWelcome to the Calculator of Calories Burned While Casual Walking\n");
    printf("*****************************************************************\n");
}

void getInputs(double* pWeight,int* pHeightFeet,double* pHeightInches,int* pSteps){
//Prompts the user to enter their weight, height, and number of steps
    
    do {
        printf("Please enter your weight in lbs (between 4.7 and 1400 lb).\n"); 
        scanf("%lf",pWeight);
            if(*pWeight<4.7 || *pWeight>1400) //Reference for using 4.7lb as the lowest value: https://www.telegraph.co.uk/news/science/science-news/6226095/Human-extremes-the-tallest-shortest-heaviest-and-lightest-people-ever.html
                printf("You have entered an incorrect value. Please try again.\n");
        } while(*pWeight<4.7 || *pWeight>1400); //Reference for using 1400lb as the highest value: http://www.guinnessworldrecords.com/world-records/heaviest-man
        
        do {
        printf("Please enter your height in feet (between 1 and 8 ft) and inches.\n");
        printf("Feet:");
        scanf("%d",pHeightFeet);
            if(*pHeightFeet<1 || *pHeightFeet>8) //Reference for using 1ft as the lowest value: http://www.guinnessworldrecords.com/news/2015/9/remembering-chandra-dangi-the-worlds-shortest-man-ever-396354
                printf("You have entered an incorrect value. Please try again.\n");
        } while(*pHeightFeet<1 || *pHeightFeet>8); //Reference for using 8ft as the highest value: http://www.guinnessworldrecords.com/world-records/tallest-man-ever
        
        do {
        printf("Inches:");
        scanf("%lf",pHeightInches);
            if(*pHeightInches<0 || *pHeightInches>=12)
                printf("You have entered an incorrect value. Please try again.\n");
        } while(*pHeightInches<0 || *pHeightInches>=12); 
        
        do {
        printf("Please enter the total number of steps walked (between 1 and 100000 steps).\n");
        scanf("%d",pSteps);
            if(*pSteps<1 || *pSteps>100000)
                printf("You have entered an incorrect value. Please try again.\n");
        } while(*pSteps<1 || *pSteps>100000);
}

void calculateOutputs(double* pWeight,int* pHeightFeet,double* pHeightInches,double* pStrideLengthInches,double* pCaloriesPerMile,double* pStepsPerMile,double* pCaloriesPerStep,double* pTotalCalories,int* pSteps,int iAttempt,int* pSize,double* pCaloriesPerMileArray, double* pStrideLengthInchesArray,double* pStepsPerMileArray,double* pCaloriesPerStepArray,double* pTotalCaloriesArray){
//Perform calculations for total calories burned and other outputs 
   
    int iInchesPerMile;
    double dTotalHeightInches;
    
    *pCaloriesPerMile=0.57*(*pWeight); //Reference: https://www.livestrong.com/article/238020-how-to-convert-pedometer-steps-to-calories/
    iInchesPerMile=5280*12;
    dTotalHeightInches=((*pHeightFeet)*12)+(*pHeightInches);
    *pStrideLengthInches=(dTotalHeightInches)*0.413; //Reference: https://www.beachbodyondemand.com/blog/how-many-steps-walk-per-mile
    *pStepsPerMile=iInchesPerMile/(*pStrideLengthInches); //Reference: https://www.beachbodyondemand.com/blog/how-many-steps-walk-per-mile
    *pCaloriesPerStep=(*pCaloriesPerMile)/(*pStepsPerMile); //Reference: https://www.livestrong.com/article/238020-how-to-convert-pedometer-steps-to-calories/
    *pTotalCalories=(*pCaloriesPerStep)*(*pSteps); //Reference: https://www.livestrong.com/article/238020-how-to-convert-pedometer-steps-to-calories/
    
    
        
    pCaloriesPerMileArray[iAttempt]=*pCaloriesPerMile;
    pStrideLengthInchesArray[iAttempt]=*pStrideLengthInches;
    pStepsPerMileArray[iAttempt]=*pStepsPerMile;
    pCaloriesPerStepArray[iAttempt]=*pCaloriesPerStep;
    pTotalCaloriesArray[iAttempt]=*pTotalCalories;
    (*pSize)++;
    
}

void categorize(double dTotalCalories, char** categoryArray, int iAttempt){
//Categorize the total calories burned into 3 categories: low, medium, and high    
    
    if(dTotalCalories<2000){
        categoryArray[iAttempt] = "Low";
    }else if((dTotalCalories>=2000) && (dTotalCalories<=2800)){
        categoryArray[iAttempt] = "Medium";
    }else{
        categoryArray[iAttempt] = "High";
    } //Reference for categories: https://fitfolk.com/average-calories-burned-per-day-men-women/
}

void printOne(double dCaloriesPerMile,double dStrideLengthInches, double dStepsPerMile, double dCaloriesPerStep, double dTotalCalories, char* sCategory){
//Print the outputs of one attempt

   printf("\nCalories Burned Per Mile: %.2f\n",dCaloriesPerMile); 
    printf("Stride Length In Inches: %.2f\n",dStrideLengthInches); 
    printf("Steps Per Mile: %d\n",((int)dStepsPerMile+1)); //Casting double into integer and adding 1 to round up to the next step
    printf("Calories Burned Per Step: %.2f\n",dCaloriesPerStep); 
    printf("Total Calories Burned: %.2f\n",dTotalCalories); 
    printf("Total Calories Burned Category: %s\n", sCategory);
}

int tryAgain(int iAttempt){
//Notify the user how many attempts they have left. Ask the user if they would like to try again.
    
    char cExit;
    
    printf("\nThis was your attempt number %d. You have %d attempts left.\n",iAttempt+1,MAXIMUM_ATTEMPTS-(iAttempt+1));
    printf("Do you want to try again? Y/N\n");
    scanf(" %c",&cExit);
    if (cExit == 'N' || cExit == 'n'){
        printf("\nYou have exited the calculator. Thank you for using the calculator.\n");
        return 0;
    } else {
        return 1;
    }
}
    
void printAll(int iSize,double* pCaloriesPerMileArray, double* pStrideLengthInchesArray,double* pStepsPerMileArray,double* pCaloriesPerStepArray,double* pTotalCaloriesArray, char** categoryArray){
//Print the outputs for all attempts 

   int iAttempt;
    
    printf("\n");
    
    for (iAttempt=0;iAttempt<iSize;iAttempt++){
        printf("Calories Burned Per Mile[%d]=%.2lf\n",iAttempt,pCaloriesPerMileArray[iAttempt]);
        printf("Stride Length In Inches[%d]=%.2lf\n",iAttempt,pStrideLengthInchesArray[iAttempt]);
        printf("Steps Per Mile[%d]=%.2lf\n",iAttempt,pStepsPerMileArray[iAttempt]);
        printf("Calories Burned Per Step[%d]=%.2lf\n",iAttempt,pCaloriesPerStepArray[iAttempt]);
        printf("Total Calories Burned[%d]=%.2lf\n",iAttempt,pTotalCaloriesArray[iAttempt]);
        printf("Total Calories Burned Category[%d]: %s.\n",iAttempt, categoryArray[iAttempt] );
        printf("\n");
    }

}


void test(){
//Driver of program
    
    double dWeight =0;
    int iHeightFeet =0;
    double dHeightInches =0;
    int iSteps =0;
    double dCaloriesPerMile =0;
    double dStrideLengthInches =0;
    double dStepsPerMile =0;
    double dCaloriesPerStep =0;
    double dTotalCalories;
    int iAttempt;
    int iTryAgain=1;
    int iSize=0;
    double dCaloriesPerMileArray[MAXIMUM_ATTEMPTS];
    double dStrideLengthInchesArray[MAXIMUM_ATTEMPTS];
    double dStepsPerMileArray[MAXIMUM_ATTEMPTS];
    double dCaloriesPerStepArray[MAXIMUM_ATTEMPTS];
    double dTotalCaloriesArray[MAXIMUM_ATTEMPTS];
    char* categoryArray[MAXIMUM_ATTEMPTS];

    for(iAttempt=0;iAttempt<MAXIMUM_ATTEMPTS && iTryAgain!=0;iAttempt++) {
    
        banner();
        getInputs(&dWeight,&iHeightFeet,&dHeightInches,&iSteps);
        calculateOutputs(&dWeight,&iHeightFeet,&dHeightInches,&dStrideLengthInches,&dCaloriesPerMile,&dStepsPerMile,&dCaloriesPerStep,&dTotalCalories,&iSteps,iAttempt,&iSize,dCaloriesPerMileArray,dStrideLengthInchesArray,dStepsPerMileArray,dCaloriesPerStepArray,dTotalCaloriesArray);
        categorize(dTotalCalories, categoryArray, iAttempt);
        printOne(dCaloriesPerMile,dStrideLengthInches,dStepsPerMile,dCaloriesPerStep,dTotalCalories,categoryArray[iAttempt]);
        iTryAgain=tryAgain(iAttempt);
        
    }
    
    printAll(iSize,dCaloriesPerMileArray,dStrideLengthInchesArray,dStepsPerMileArray,dCaloriesPerStepArray,dTotalCaloriesArray, categoryArray);
    
}

int main(){
    test();
    return 0;
}
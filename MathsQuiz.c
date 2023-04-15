/*
Program Description:
This program simulates a mathematics quiz game.
The program is menu-driven and displays a main menu when run. The menu includes the following options:


1. Enter the number of questions to be asked for this round of the quiz (maximum of 5 questions allowed).
2. Start and play quiz
3. Display the number of questions that were answered (i) correctly and (ii) incorrectly for this round.
4. Exit Program

The program continually runs and re-displays the main menu after each option has completed. 
The program only terminates when the user enters option 4 (i.e. Exit Program).

The user can only select option 2 after they select option 1.
The user can only select option 3 after they select option 2.
When the user starts a new quiz, option 3 is reset from the previous round.

Author: Sarah Barron C21415904
Date: 28/11/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int user_choice = 0; //  variable for option user chooses
    int num_qs = 0; // number of questions user selects in option 1

    int i = 0; // used in for loop
    int num1 = 0;  // stores random number for quiz questions
    int num2 = 0;  // stores random number for quiz questions
    int oper = 0; // stores random number for operators in quiz questions
    int corr_ans = 0; // counter for correct answers to quiz
    int incorr_ans = 0; // counter for incorrect answers to quiz

    int answer = 0; // answer to quiz questions
    int user_answer = 0; // user's answer to quiz questions

    int end = 0; // used to end program
    int option1 = 0; // counter for when user has selected option 1 
    int option2 = 0; // counter for when user has selected option 2
    
    printf("\n\nWhen entering an option from the menu, you must press enter twice.\n\n");
    
    // while the user has not entered option 4 to terminate the program
    while(end != 1)
    {
        // reprint menu until user enters valid input
        do
        {
            printf("\n\n--------------Maths Quiz Menu--------------");
            printf("\n\n 1. Enter desired number of questions");
            printf("\n 2. Start Quiz");
            printf("\n 3. Display number of questions answered correctly and incorrectly");
            printf("\n 4. Exit");
            printf("\n\n-------------------------------------------");

            printf("\n\nChoose an option: ");

            // read in user's choice
            scanf("%d", &user_choice);
            
            // discards unwanted characters before user presses enter key
            while(getchar() != '\n');               
            
        } while ((user_choice < 1 || user_choice > 4) || (getchar() != '\n'));

       
        switch(user_choice)
        {
            // if user inputs 1
            case 1:
            {
                printf("Press enter twice when inputting your answer.\n");
                // reprint statement until user enters valid input
                do
                {
                    printf("\nEnter desired number of questions (maximum 5 questions): ");

                    // read in how many questions user wants in quiz
                    scanf("%d", &num_qs);

                    // discards unwanted characters before user presses enter key
                    while(getchar() != '\n');

                } while((num_qs < 1 || num_qs > 5) || (getchar() != '\n'));

                // increment to show user selected option 1 in menu            
                option1 ++;
                //reset to zero
                option2 = 0;
                break;

            }// end case

            // if user inputs 2              
            case 2:
            {
                // if user has previously selected option 1
                if(option1 > 0)
                {
                    printf("\nLet the quiz begin...\n\n");

                    // set correct and incorrect answer counters to zero
                    corr_ans = 0;
                    incorr_ans = 0;

                    // iterate for the number of questions user chose
                    for(i = 1; i <= num_qs; i++)
                    {
                        // seed the random number generator with a range 0 – large number
                        srand(time(NULL));

                        // num1 and num2 assigned a random number between 1 – 10
                        num1 = (rand() % 10) + 1;
                        num2 = (rand() % 10) + 1;

                        // oper assigned a random number between 1-3
                        oper = (rand() % 3) + 1;

                        // randomise operators for quiz questionsusing random numbers 
                        if(oper == 1) 
                        {
                            answer = num1 + num2;
                            printf("\nQuestion %d: %d + %d = ", i, num1, num2);
                        }
                        else if(oper == 2) 
                        {
                            answer = num1 - num2;
                            printf("\nQuestion %d: %d - %d = ", i, num1, num2);
                        }
                        else if(oper == 3) 
                        {
                            answer = num1 * num2;
                            printf("\nQuestion %d: %d * %d = ", i, num1, num2);
                        }

                        // read in user's answer to each question
                        scanf("%d", &user_answer);

                        // compare the user's answer to the correct answer                        
                        if(user_answer == answer)
                        {
                            // increment counter of user's correct answers
                            corr_ans ++;
                        }
                        else if(user_answer != answer)
                        {
                            // increment counter of user's incorrect answers
                            incorr_ans ++;
                            printf("\nYou entered: %d. Wrong! The correct answer: %d\n", user_answer, answer);
                        }

                        // reset option 1 to zero so user can start a new round with a different number of questions   
                        option1 = 0;

                        //increment to show user has selected option 2
                        option2 ++;

                    }// end for

                }// end if

                // else if user has NOT previously selected option 1
                else if(option1 < 1)
                {
                    printf("\nPlease select option 1 before you select option 2.");
                } // end else if

                break;
              
            }// end case

            // if user inputs 3
            case 3:
            {
                // if user has previously selected option 2
                if(option2 > 0)
                {
                    printf("\n\nYou answered correctly %d times.", corr_ans);
                    printf("\nYou guessed incorrectly %d times.", incorr_ans);
                }// end if

                // else if user has NOT previously selected option 2
                else if(option2 < 1)
                {
                    printf("\nPlease select option 2 before you select option 3.");                   
                }// end else if

                break;

            }// end case

            // if user inputs 4
            case 4:
            {
                // increment to end program
                end ++;
                printf("GAME OVER!");

                break;
            } // end case

        }// end switch

    } // end while
    
    return 0;

}

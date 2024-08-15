#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

int set_rules();
void Single_Player(int games);
void Two_Player(int games);
void decide_winner(int pOne_Input, int pTwo_Input, int& Score1, int& Score2);
bool check_Input(int RPS_Choice);

int main(){

    bool leave_game = false;
    int choice = 0;
    int games_to_win = 0;

    while(leave_game == false){
        cout << "Welcome to Rock, Paper, Scissor!" << endl;
        cout << "Select your game mode by entering the number below:" << endl << endl;

        cout << "\t1) Single Player" << endl << "\t2) 2-Player" << endl << "\t3) Exit";
        cout << endl << endl << "Selection: ";
        cin >> choice;
        //cout << endl << "Your Selection is: " << choice;

        system("cls");

        switch(choice){
            case 1:
                cout << "Welcome to Single Player Mode!" << endl;
                games_to_win = set_rules();
                Single_Player(games_to_win);
                break;

            case 2:
                cout << "Welcome to 2-Player Mode!" << endl;
                games_to_win = set_rules();
                Two_Player(games_to_win);
                break;

            case 3:
                cout << "Goodbye! Thank you for Playing!" << endl;
                leave_game == true;
                exit(0);
                break;

            default:
                cout << "Invalid Selection" << endl;
                break;
        }
        this_thread::sleep_for(chrono::seconds(5));

        system("cls");
    }
    cout << "End of Program!";


    return 0;
    
}

int set_rules(){
    int games;

    do{
        cout << "How many games would you like to play?" << endl;
        cout << "* This represents shows how many games you are playing the best of. Even numbers will be rounded up. *" << endl;
        cout << "Best of: "; 
        cin >> games;
        cout << endl;

        if (games <= 0){
            cout << "Please enter a positive number of games" << endl;
        }

    } while (games <= 0);

    //Creates odd number of games to win
    if (games % 2 == 0 ){
        games = games / 2;
        games += 1;
    }
     else{
        games += 1;
        games = games / 2;  
    }
    return games;
}

/*
The value of 1 represent Rock
The value of 2 represent Paper
The value of 3 represent Scissors
*/

void Single_Player(int games){
    int round_num = 1;
    int player_score = 0;
    int CPU_score = 0;
    int pOne_Input = 0;
    int CPU_Input;
    bool valid_input = false;

    system("cls");

    while (player_score < games && CPU_score < games){
        cout << "Round " << round_num << endl;
        cout << "---------------------------" << endl;
        cout << "\tScores:" << endl;
        cout << "Player 1: " << player_score << endl;
        cout << "CPU: " << CPU_score << endl << endl << endl;

        do{
            cout << "1) Rock" << endl <<
                    "2) Paper" << endl <<
                    "3) Scissors" << endl << endl;

            cout << "Your turn Player 1! Make a selection from the numbers above." << endl
                << "Selection: ";

            cin >>  pOne_Input;
            cout << endl;
            
            valid_input = check_Input(pOne_Input);
        } while(valid_input == false);

        CPU_Input = ((rand() % 3) + 1);

        system("cls");
        decide_winner(pOne_Input, CPU_Input, player_score, CPU_score);
        round_num++;
    }
    cout << endl << "Please wait to continue" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    system("cls");

    if (player_score == games){
        cout << "Congrats! You have won the game!" << endl;
    }
    else{
        cout << "You lose! Better luck next time!" << endl << endl;
    }
        cout << "Final Score: " << endl;
        cout << "Player 1: " << player_score << endl;
        cout << "CPU: " << CPU_score << endl << endl << endl;
  
}

void Two_Player(int games){
    int p1_score = 0;
    int p2_score = 0;
    int p1_input;
    int p2_input;
    int round_num = 1;
    bool valid_input;

    system("cls");

    while (p1_score < games && p2_score < games){
        valid_input = false;
        cout << "Round " << round_num << endl;
        cout << "------------------------" << endl;
        cout << "\tScores:" << endl;
        cout << "Player 1: " << p1_score << endl;
        cout << "Player 2: " << p2_score << endl << endl << endl;

        do{
            cout << "1) Rock" << endl <<
                    "2) Paper" << endl <<
                    "3) Scissors" << endl << endl;

            cout << "Your turn Player 1! Make a selection from the numbers above." << endl
                << "Selection: ";

            cin >>  p1_input;
            cout << endl;
            
            valid_input = check_Input(p1_input);
        } while(valid_input == false);

        valid_input = false;
        system("cls");
        cout << "Round " << round_num << endl;
        cout << "------------------------" << endl;
        cout << "\tScores:" << endl;
        cout << "Player 1: " << p1_score << endl;
        cout << "Player 2: " << p2_score << endl << endl << endl;

        do{
            cout << "1) Rock" << endl <<
                    "2) Paper" << endl <<
                    "3) Scissors" << endl << endl;

            cout << "Your turn Player 2! Make a selection from the numbers above." << endl
                << "Selection: ";

            cin >>  p2_input;
            cout << endl;
            
            valid_input = check_Input(p2_input);
        } while(valid_input == false);

        system("cls");
        decide_winner(p1_input, p2_input, p1_score, p2_score);
        round_num++;
    }
    cout << endl << "Please wait to continue" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    system("cls");

    if (p1_score == games){
        cout << "Congrats Player 1! You have won the game!" << endl;
    }
    else{
        cout << "Congrats Player 2! You have won the game!" << endl << endl;
    }
        cout << "Final Score: " << endl;
        cout << "Player 1: " << p1_score << endl;
        cout << "Player 2: " << p2_score << endl << endl << endl;
}

/*
The value of 1 represent Rock
The value of 2 represent Paper
The value of 3 represent Scissors
*/

// The CPU is always going to be player Two
void decide_winner(int pOne_Input, int pTwo_Input, int& Score1, int& Score2){
    if (pOne_Input == pTwo_Input){
        cout << "It's a Tie!" << endl;
        if(pOne_Input == 1){
            cout << "    _______              _______    \n";
            cout << "---'   ____)            (____   '---\n";
            cout << "      (_____)          (_____)      \n";     
            cout << "      (_____)    vs    (_____)      \n";
            cout << "      (_____)          (_____)      \n";
            cout << "---.__(_____)          (_____)__.---\n";


        }
        else if(pOne_Input == 2){
            cout << "    _______                             _______      \n";
            cout << "---'   ____)______               ______(____   '---  \n";
            cout << "          ________)            (__________          \n";
            cout << "          _________)    vs    (___________           \n";
            cout << "         _________)            (_________            \n";
            cout << "---.____________)                (____________.---   \n";

        }
        else{
            cout << "    _______                          ________     \n";
            cout << "---'   ____)______            ______(____    '---\n";
            cout << "          ________)          (________           \n";
            cout << "       ___________)    vs    (___________        \n";
            cout << "      (____)                        (____)       \n";  
            cout << "---.__(___)                          (___)__.--- \n";   

            
        }
        cout << endl << endl;
        return;       
    }

// Tests cases if Player 1 chooses Rock
    if (pOne_Input == 1){
        if (pTwo_Input == 2){
            cout << "It's Rock vs Paper! Paper Wins!" << endl;
            cout << "    _______                      ________     \n";
            cout << "---'   ____)              ______(____    '---\n";
            cout << "      (_____)           _(__________          \n";     
            cout << "      (_____)    vs    (___________           \n";
            cout << "      (_____)            (_________           \n";
            cout << "---.__(_____)              (____________.---  \n";
            Score2++;
            cout << endl << endl;
            return;
        }
        else if (pTwo_Input == 3){
            cout << "It's Rock vs Scissors! Rock Wins!" << endl;
            cout << "    _______                         ________     \n";
            cout << "---'   ____)              _________(____    '---\n";
            cout << "      (_____)            (___________           \n";     
            cout << "      (_____)    vs      (_____________        \n";
            cout << "      (_____)                      (____)       \n";
            cout << "---.__(_____)                       (___)____.---  \n";
            Score1++;
            cout << endl << endl;
            return;
        }
    }
        
// Tests cases if Player 1 chooses Paper
    if (pOne_Input == 2){
        if (pTwo_Input == 1){
            cout << "It's Paper vs Rock! Paper Wins!" << endl;
            cout << "    _______                             _______    \n";
            cout << "---'   ____)______                     (____   '---\n";
            cout << "          ________)                   (_____)      \n";
            cout << "          _________)    vs            (_____)      \n";
            cout << "         _________)                   (_____)      \n";
            cout << "---.____________)                     (_____)__.---\n";
            Score1++;
            cout << endl << endl;
            return;
        }
        else if (pTwo_Input == 3){
            cout << "It's Paper vs Scissors! Scissors Wins!" << endl;
            cout << "    _______                                _______    \n";
            cout << "---'   ____)______              _________(____    '---\n";
            cout << "          ________)            (___________           \n";
            cout << "          _________)    vs      (_____________        \n";
            cout << "         _________)                      (____)       \n";
            cout << "---.____________)                         (___)____.---  \n";
            Score2++;
            cout << endl << endl;
            return;
        }
    }

    // Tests cases if Player 1 chooses Scissors
    if (pOne_Input == 3){
        if (pTwo_Input == 1){
            cout << "It's Scissors vs Rock! Rock Wins!" << endl;
            cout << "    _______                     ________    \n";
            cout << "---'   ____)______            (____     '---\n";
            cout << "          ________)          (_____)      \n";
            cout << "       ___________)    vs    (_____)      \n";
            cout << "      (____)                 (_____)      \n";  
            cout << "---.__(___)                   (_____)__.---\n";  
            Score2++;
            cout << endl << endl;
            return;
        }
        else if (pTwo_Input == 2){
            cout << "It's Scissors vs Paper! Scissors Wins!" << endl;
            cout << "    _______                           ________     \n";
            cout << "---'   ____)______             ______(____    '---\n";
            cout << "          ________)           ( _________       \n";
            cout << "       ___________)    vs    (___________        \n";
            cout << "      (____)                  (_________          \n";  
            cout << "---.__(___)                    (____________.---  \n";  
            Score1++;
            cout << endl << endl;
            return;
        }

    }
    cout << endl <<"Error: Hit end of Decide Winner Function";
}

bool check_Input(int RPS_Choice){
    if (RPS_Choice == 1 || RPS_Choice == 2 || RPS_Choice == 3){
        return true;
    }
    else{
        return false;
    }
}
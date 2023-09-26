//Wendy Wu
//Purpose: An interactive implementation of the dice game BlackJack. 
//Looping algorithm and rand to generate various outcomes. Users can enter wager value to "Win" or "Lose" money based on the gaming algorithm of BlackJack.
//Feel free to play the game by choosing #5 on the gaming menu. Other options on the menu are also available to test/try. Enjoy

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;
int rollDice()
{
  int die = (rand() % 13) + 2; 
 //between 2 and 14
  if(die ==14)
  {
    die = 10; //king      c
    cout << "\nRolled a king !" <<endl;
  }
  else if(die ==13)
  {      
    die = 10; // Queen
    cout << "\nRolled a queen !" <<endl;
  }
  else if(die == 12)
  {
    die = 10; //jack
    cout << "\nRolled a jack !" <<endl;
  }   
  return die;
}
int rollDicew()
{
  int die = (rand() % 13) + 2; 
 //between 2 and 14
  if(die ==14)
  {
    die = 10; //king     
  }
  else if(die ==13)
  {      
    die = 10; // Queen
  }
  else if(die == 12)
  {
    die = 10; //jack
  }   
  return die;
}
int getWager(int money)
{
  int wager=0;
  bool done = false;
  while(done ==false)
  {
  cout << "Please enter your wager value: \t\t";
  cin >> wager;
  if(wager > money)
  {
    //invalid
    cout << "Not valid, try again\n"<<endl;
  }
  else if (wager <0) //negative
  {
    //invalid
   cout << "Not valid, try again\n"<<endl;
  }
  else if ((wager>0)&& (wager <=money)){
    cout << "\nAccepted Wager...\n" << endl;
    cout << "\nWager you entered is : \t\t$" <<wager <<endl;
    done = true;
  }
  else
  {
    cout <<"Not Valid, try again\n" <<endl;
  }
  }
  return wager;
}
void playerTurn(int money, int &wager, bool &bust, int&total, int &houseRoll)
{
  bool roll = true;//if keep rolling/hit or true to stand
  int choice =0;
  bool choose = false;
  int die = 0;
  //srand(time(0));
  int ran = (rand()%2) +1; //ace
  
  while(roll==true)
    {
    if(total >=22)
    {
      cout << "\nYour total is (over 22): \t\t" << total <<endl;
      cout << "\nYour round is over and you are busted. Unfortunately you lose your wager...sadness."<<endl;
      //round over
      bust = true;
      roll = false;
      //doesn't immediately say round over but update above? more sophisticated if work on this logic later but for now I'll keep this
    }
    else //roll is less than 22
    {
      //continue stand or hit
      choose = false;
      while (choose == false)
      {
      cout << "\nThe House's single/first roll is : \t\t" <<houseRoll << endl;
      cout << "option: hit or stand (enter 1 to hit or enter 2 to stand)? \n\t";
      cin >> choice;
      if((choice!=1) && (choice!=2))
      {
        cout << "\nyour choice is not valid, please enter again\n"<<endl;
      }
      else
      {
        choose = true; // the user entered hit or stand = can move on 
      }
      
      }
      
      if(choice==1) //hit
      {
        die = rollDice();
        if(ran == 1)
        {
          if(die ==11)
          {
            die = 1; 
            cout << "\nYou rolled an ACE that has a value of 1 !" <<endl;
          }
        }
        else if (ran==2 &&die ==11)
        {
          cout << "\nYou rolled an ACE that has a value of 11 !" <<endl;
        }
        cout << "\nYou rolled a ... " << die <<endl;
        total = total + die;
        cout << "\nYour current total is: \t\t\t\t" <<total <<"." <<endl;
      }
      else if(choice==2) // stand
      { 
         cout << "\nYour total is: \t\t\t\t" <<total <<".\n\n" <<endl;
          roll = false;
      }
    
    }
    }
  
}

void houseTurn(int houseRoll, bool &bust, int &total)
{ //the variables in the parameter is same name as the playturn but please make them diff in main function
  //start here 
  bool done = false;
  int die =0;
  //srand(time(0));
  int ran = (rand()%2)+1;
    die = rollDice();
    if(ran == 1 && die ==11)
    {
      die =1;
      cout << "\nHouse rolled an ACE that has a value of 1 !" <<endl;
    }
    else if(ran==2 &&die ==11)
    {
      cout << "\nHouse rolled an ACE that has a value of 11 !" <<endl;
    }
    cout << "\nHouse rolled a ... " << die <<endl;
    total = total + die;
    if(total>=22)
    {
      cout << "\nThe House's total is: \t\t" << total <<endl;
      bust = true; //busted
      done = true;
    }
    else if(total <17)
    {
      while(done == false)
      {
        /*cout << "Continue to 'hit'.\n" <<endl;
        die = rollDice();
        if(ran == 1 && die ==11) //check if the ace switch is 1 and die can only get 11 for ace so then convert ace to 1
        {
          die =1;
        }
        cout << "House rolled a ... " << die <<endl;
        total = total + die; */
        if(total>=22)
        {
          cout << "\nThe House's total is: \t\t" << total <<endl;
          cout << "\nHouse is unfortunately busted :( \n" <<endl;
          bust = true; //busted
          done = true;
        }
        else if (total <17) //continue add
        {
          cout << "\nContinue to 'hit'.\n" <<endl;
          die = rollDice();
          if(ran == 1 && die ==11) //check if the ace switch is 1 and die can only get 11 for ace so then convert ace to 1
          {
            die =1;
          cout << "\nHouse rolled an ACE that has a value of 1 !" <<endl;
          } 
          else if(ran==2 &&die ==11)
          {
          cout << "\nHouse rolled an ACE that has a value of 11 !" <<endl;
          }
          cout << "\nHouse rolled a ... " << die <<endl;
          total = total + die;
          cout << "\nThe House's current total is: \t\t" << total <<endl;
        }
        else if (total >=17 && total <22)//get a num between 17 and 21
        {
          cout << "\nThe House's final total is: \t\t" << total <<endl;
          bust = false;
          done = true;
        }
      }
  
    }
    else if(total>=17 &&total <22)
    {
      cout << "\nThe House's final total is: \t\t" << total <<endl;
      bust = false;
      done = true;
    }
  
  
}
void pTurn(int money, int &wager, bool &bust, int&total, int &houseRoll)
{
  bool roll = true;//if keep rolling/hit or true to stand
  int choice = (rand()%2)+1; //randomize stand or hit
  int die = 0;
  //srand(time(0));
  int ran = (rand()%2) +1; //ace
  
  while(roll==true)
    {
    if(total >=22)
    {
      //round over
      bust = true;
      roll = false;
      //doesn't immediately say round over but update above? more sophisticated if work on this logic later but for now I'll keep this
    }
    else //roll is less than 22
    {
      //continue stand or hit
    
      if(choice==1) //hit
      {
        die = rollDicew();
        if(ran == 1)
        {
          if(die ==11)
          {
            die = 1; 
          }
        }
        total = total + die;
      }
      else if(choice==2) // stand
      { 
          roll = false;
      }
    
    }
    }
  
}

void hTurn(int houseRoll, bool &bust, int &total)
{ //the variables in the parameter is same name as the playturn but please make them diff in main function
  //start here 
  bool done = false;
  int die =0;
  //srand(time(0));
  int ran = (rand()%2)+1;
    die = rollDicew();
    if(ran == 1 && die ==11)
    {
      die =1;
    }
    
    total = total + die;
    if(total>=22)
    {
      bust = true; //busted
      done = true;
    }
    else if(total <17)
    {
      while(done == false)
      {
        /*cout << "Continue to 'hit'.\n" <<endl;
        die = rollDice();
        if(ran == 1 && die ==11) //check if the ace switch is 1 and die can only get 11 for ace so then convert ace to 1
        {
          die =1;
        }
        cout << "House rolled a ... " << die <<endl;
        total = total + die; */
        if(total>=22)
        {
          bust = true; //busted
          done = true;
        }
        else if (total <17) //continue add
        {
          die = rollDicew(); //modify later
          if(ran == 1 && die ==11) //check if the ace switch is 1 and die can only get 11 for ace so then convert ace to 1
          {
            die =1;
          } 
          total = total + die;
        }
        else if (total >=17 && total <22)//get a num between 17 and 21
        {
          bust = false;
          done = true;
        }
      }
  
    }
    else if(total>=17 &&total <22)
    {
      bust = false;
      done = true;
    }
  
  
}
int main() {
  srand(time(0));
  cout << "\n\nWelcome to BlackJack!\n";
  int pWin =0;
  int hWin =0;
  int money = 100;
  int wager =10;
  int die =0;
  bool quitYo = false;
  int totalP = 0; //first player's total is totalP
  int totalH =0; //first house's total is totalH
  int houseRoll = 0; //just set a random for testing purposes , let's say houseRoll is 7 at first roll
  bool win = false;
  int dicew =0;
  int choice = 9;
  int ran = 0; //ace
  int que = 0;
  bool quit = false;
  bool bustP = false; //if player is busted or not
  bool bustH = false; //if House is busted or not
  while(choice!=0) //while player doesn't quit or money isn't = 0
  {
    cout << "\n\n\nMenu:" <<endl;
    cout << "1. Test rollDice" <<endl;
    cout << "2. Test getWager" <<endl;
    cout << "3. Test playerTurn" <<endl;    
    cout << "4. Test houseTurn" <<endl;
    cout << "5. Play the game once using the functions above (*I modified this to the user can choose to quit instead of playing only one round)" <<endl; 
    cout << "6.Simulate playing the game 100,000 times(rounds) and tally/report the results." <<endl;
    cout << "0.Quit"<<endl;    
    cout <<"\nPlease enter your choice here: \t\t\t" ;
    cin >> choice;
    if(choice == 1)
    {
      dicew = rollDice();
      cout << "\nThe number outputted from rolling the dice is: \t\t\t" <<dicew << endl;
    }
    else if(choice == 2)
    {
      money =100; // for this function to work, start with money =100;
      cout << "\nYour Wager...is operated by this function getWager: \n" <<endl;
      wager = getWager(money);
    }
    else if (choice ==3)
    {
      money =100; //all are for testing purposes only
      wager = 10;
      bustP = false;
      totalP = 15;
      houseRoll = 9;
      cout << "\n Testing player Turn function..." << endl; 
      cout << "The initial totalP from two times of rolling is: " <<totalP <<endl;
      playerTurn(money, wager, bustP, totalP, houseRoll);
    }
    else if (choice ==4)
    {
      houseRoll = 9;
      bustH = false;
      totalH =9;
      cout << "\n Testing house Turn function..." << endl; 
      cout << "The initial totalH from one time of rolling is: " <<totalH <<endl;
      houseTurn(houseRoll, bustH, totalH);
    }
    else if(choice == 5)
    {
      cout << "Note: You (player) will have $100 to start the game." <<endl;
      money =100;
      quitYo=false;
      while ((money>0)&&(quitYo==false))
      {
           //if ace == 2 then 11 is ace else then ace == 1  is 1
           totalP =0;
           totalH =0;
           bustP = false;
           bustH=false;
           if (win ==false)
           {
           wager = getWager(money);
           //srand(time(0));
           ran = (rand()%2) +1; //ace
           //player's Turn
           cout << "\n\nPlayer's two Turns:\n"<<endl;
           for(int i =0; i <2 ; i++) //roll twice for player
           {
            die = rollDice(); 
            if(ran == 1)
            {
               if(die ==11)
               {
                die = 1; 
                cout << "\nYou (player) rolled an ACE that has a value of 1 !" <<endl;
               }
            }
            else if(ran==2 &&die ==11)
            {
              cout << "\nYou (player) rolled an ACE that has a value of 11 !" <<endl;
            }
            cout << "\nYour " << (i+1) << " time roll is = \t" <<die<<endl;
            totalP = totalP+ die;
            cout << "\nCurrent total for the player is:  \t\t" << totalP <<endl;
           }
           //house's turn
           cout << "\n\nHouse's first Turn:\n"<<endl;
           houseRoll = rollDice(); 
            if(ran == 1)
            {
               if(houseRoll ==11)
               {
                houseRoll = 1; 
                cout << "\nHouserolled an ACE that has a value of 1 !" <<endl;
               }
            }
            else if(ran==2 &&houseRoll ==11)
            {
              cout << "\nHouse rolled an ACE that has a value of 11 !" <<endl;
            }
            totalH = totalH+ houseRoll;
           playerTurn(money,wager, bustP, totalP,houseRoll);
           if(bustP ==true)//player busted
           {
             money = money - wager;
             cout << "\nYou lost the round and lost the wager because you were busted (your rolls exceeded 21)\n" <<endl;
             cout << "\nYour current money is:\t\t\t$"<<money<<endl;
             win = true;
            
           }
           else if(bustP == false)
           {
             houseTurn(houseRoll, bustH, totalH);
             if(bustH == true)
             {
               cout << "\nHouse's total that caused it to bust is:\t\t" <<totalH <<endl;
               cout << "Congrats! The house busted so you won the wager! \n" <<endl;
               money = money + wager;
               cout << "\nYour current money is:\t\t\t$"<<money<<endl;
             }
             else
             {
               if(totalP > totalH)
               {
                 cout << "\nHouse's total is:\t\t" <<totalH <<endl;
                 cout << "\nCongrats! You won the wager because your roll total was > than house's! \n" <<endl;
               money = money + wager;
               cout << "\nYour current money is:\t\t\t$"<<money<<endl;
               }
               else if(totalH == totalP)
               {
                 cout << "\nHouse's total is:\t\t" <<totalH <<endl;
                 cout << "\nPUSH. player's sum is equal to house's so no gain/loss"<<endl;
                 money = money; //not necessary but a good reminder for myself
                 cout << "\nYour current money is:\t\t\t$"<<money<<endl;
                 win = true; 
               }
               else
               {
                 cout << "\nHouse's total is:\t\t" <<totalH <<endl;
                 cout << "\nPlayer loses the wager :(" <<endl;
                 money = money - wager;
                 cout << "\nYour current money is:\t\t\t$"<<money<<endl;
                 win = true;
               }
             }
           }
           }
           win = false;
           if(money ==0)
           {
             quitYo =true;
           }
           else
           {
           cout << "\n\nWould you like to Quit? (enter 1 to quit / 2 to continue playing...\t\t" ;
           cin >> que;
           if (que==2)
           {
             quitYo = false;
           }
           else if (que==1)
           {
             quitYo = true;
           }
           else
           {
             cout << "\nnot valid, quit automatically :)"<<endl;
             quitYo = true;
             break;
           }
           }

      }
    }
    else if(choice ==6) //note all simulations are randomized (ie: hit/stand...) (also no couts)
    {
      int u =0;
      int push =0;
      while(u<100000) // 100,000 times
      {
           money =100;
           totalP =0;
           totalH =0;
           bustP = false;
           bustH=false;
           win = false;
           if (win ==false)
           {
           wager = (rand()%money) +1; //randomize the wager
           //srand(time(0));
           ran = (rand()%2) +1; //ace
           //player's Turn
           for(int i =0; i <2 ; i++) //roll twice for player
           {
            die = rollDicew(); 
            if(ran == 1)
            {
               if(die ==11)
               {
                die = 1; 
               }
            }
            totalP = totalP+ die;
           }
           //house's turn
           houseRoll = rollDicew(); 
            if(ran == 1)
            {
               if(houseRoll ==11)
               {
                houseRoll = 1; 
               }
            }
            totalH = totalH+ houseRoll;
           pTurn(money,wager, bustP, totalP,houseRoll);
           if(bustP ==true)//player busted
           {
             money = money - wager;
             win = true;
             hWin++;
             u++;
           }
           else if(bustP == false)
           {
             hTurn(houseRoll, bustH, totalH);
             if(bustH == true)
             {
               money = money + wager;
               pWin++;
               win = true;
               u++;
             }
             else
             {
               if(totalP > totalH)
               {
               money = money + wager;
               win = true;
               pWin++;
               u++;
               }
               else if(totalH == totalP) //equal
               {
                 win = true; 
                 push++;
                 u++;
               }
               else
               {
                 money = money - wager;
                 win = true;
                 hWin++;
                 u++;
               }
             }
           }
           
           
           }

      
      }
      //after while loop print the results
      cout << "\nOut of 100,000 rounds of BlackJack, here are the results:\n" <<endl;
      cout << "The player's number of wins:\t\t" <<pWin <<endl;
      cout << "The House's number of wins:\t\t" <<hWin <<endl;
      cout << "The number of PUSH is: \t\t" <<push <<endl;
      cout.setf(ios::fixed);
      cout.setf(ios::showpoint);
      cout.precision(2); //two decimal places after the . (ALSO did use the precision function)
      cout << "player's win / 100,000 rounds percentage is: \t\t" << ((pWin/100000.00)*100) <<"%."<<endl;
      cout << "house's win / 100,000 rounds percentage is: \t\t" << ((hWin/100000.00)*100) <<"%."<<endl;
      cout << "num Push (equal)/ 100,000 rounds percentage is: \t\t" << ((push/100000.00)*100) <<"%."<<endl;
    }
    else
    {
      cout <<"exiting..." <<endl;

      choice =0;
    }

  }

  
}

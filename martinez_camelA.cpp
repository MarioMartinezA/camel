//Kori Gann & Mario Martinez
#include <iostream>
#include <stdlib.h> 
using namespace std;

void intro();
void loop();
char choice();
bool quit(bool quit, char option);
void status(char choice, int yourmiles, int drinks, int nativemiles, int& camelTired, int thirst);
void stop(char choice, int& camelTired, int& nativeMiles);
void fullSpeed(char choice, int &camelTired, int& nativeMiles, int &yourMiles, int &thirst);
void moderateSpeed(char choice, int &camelTired, int& nativeMiles, int &yourMiles, int &thirst);
void drink(char choice, int& canteen, int& thirst);
void killcamel(char& chosen, int& camelTired, bool& done);

void noCamel();
char camelchoose();
void camelA(char cchoice, bool& done);
void camelB(char cchoice, bool& done);
void camelC(char cchoice, bool& done);
int main()
{
    char chosen = 'g';
    bool done = false;
    bool done2 = false;
    srand(time(0));

    //The game objects
    int yourMiles = 0, camelTired = 0, thirst = 0; 
    int nativeMiles = 20;
    int canteen = rand() % 12 + 1; //random drinks of water
    int water = canteen;
    
                                                                    
    //GAME Time Yeah!!!!
    //has intro statements to game
    intro();

    //pretty much whole game
    while(done == false)
    {
        if (camelTired > 8)
        {
            char cchoice;
           
                noCamel();
                cchoice = camelchoose();
                if(cchoice == 'A')
                {
                    camelA(cchoice, done);
                
                }
                if (cchoice == 'B')
                {
                    camelB(cchoice, done);
                    
                }
                if(cchoice == 'C')
                {
                
                    camelC(cchoice, done);
                }
                break;

        }
        int oasis = rand() % 20;
        if( thirst > 4 && thirst < 6)
        {
            cout << "You are thirsty." << endl;
        }
        if (thirst > 6)
        {
            cout << "You died from dehydration."<< endl;
            done = true;
        }
        if (camelTired > 5 && camelTired < 8)
        {
            cout << "Your camel is getting tired." << endl;
        }


        if (nativeMiles < 1)
        {
            cout << "The natives caught you! Your dead! oh Noooo!" << endl;
            done = true;
        }
        if (nativeMiles < 15)
        {
            cout << "The natives are getting close!" << endl;
        }
        if (yourMiles > 199)
        {
            cout << "You win! That's Amazing...Not that I doubted you..." << endl;
            done = true;
        }
        if (oasis == 5)
        {
            cout << "Yay, you found an oasis now you won't let your pesky body kill you." << endl;
            canteen = water;
        }
        done = quit(done, chosen);
        loop();
        chosen = choice();
        status(chosen, yourMiles, canteen, nativeMiles, camelTired, thirst);
        stop(chosen, camelTired, nativeMiles);
        fullSpeed(chosen, camelTired, nativeMiles, yourMiles, thirst);
        moderateSpeed(chosen, camelTired, nativeMiles, yourMiles, thirst);
        drink(chosen, canteen, thirst);
        killcamel(chosen, camelTired, done);
        
        
    }
         

    return 0;
}

void intro()
{
    cout << "Welcome to Camel!" << endl;
    cout << "You have stolen a camel to make your way across the great Mobi dessert." << endl;
    cout << "The natives want their camel back and are chasing you down! Survive your" << endl;
    cout << "desert trek and out run the natives." << endl;
    
    return;
}
//tells you your choices
void loop()
{
    cout << "A. Drink from your canteen." << endl;
    cout << "B. Ahead moderate speed." << endl;
    cout << "C. Ahead full speed." << endl;
    cout << "D. Stop for the night." << endl;
    cout << "E. Status check." << endl;
    cout << "F. Lose the camel?" << endl;
    cout << "Q. Quit." << endl;
    cout << "Your choice? ";
    
    return;
}
//grabs your choices in correct format
char choice()
{
    char choice;
    cin >> choice;
    choice = toupper(choice);
    
    return choice;
}
//Allows you to quit game
bool quit(bool quit, char option)
{
    if (option == 'Q')
    {
        cout << "Bye, hope you had fun! (^_^)" << endl;
        quit = true;
    }
    else
    {
        quit = false;
    }
    return quit;
}

void status(char choice, int yourmiles, int drinks, int nativemiles, int& camelTired, int thirst)
{
    if (choice == 'E')
    {
        cout << "\n\n";
        cout << "Miles traveled: " << yourmiles << endl;
        cout << "Drinks in canteen: " << drinks << endl;
        cout << "The natives are " << nativemiles << " miles behind you." << endl;
        cout << "Camel tiredness: " << camelTired << endl;
        cout << "Thirst: " << thirst;
        cout << "\n \n";
    }
    return;
}

void stop(char choice, int& camelTired, int& nativeMiles)
{
    int num = rand() % 7 + 7;
    if(choice == 'D')
    {
        cout << "\n \n";
        cout << "Your camel is happy!" << endl;
        camelTired = 0;
        nativeMiles = nativeMiles - num;
        cout << "But natives are " << nativeMiles << " away from you!" << endl;
        cout << "\n \n";
    }

    return ;
}

void fullSpeed(char choice, int &camelTired, int& nativeMiles, int &yourMiles, int &thirst)
{
    int num = rand() % 10 + 10;
    int num2 = rand() % 7 + 7;
    int num3 = rand() % 3 + 1;

    if(choice == 'C')
    {
        yourMiles = yourMiles + num;
        cout << "\n \n";
        cout << "Miles traveled: " << num << endl;
        thirst++;
        camelTired = camelTired + num3;
        nativeMiles = (nativeMiles + num) - num2;
    }

}

void moderateSpeed(char choice, int &camelTired, int& nativeMiles, int &yourMiles, int &thirst)
{
    int num = rand() % 7 + 5;
    int num2 = rand() % 7 + 7;

    if(choice == 'B')
    {
        yourMiles = yourMiles + num;
        cout << "\n \n";
        cout << "Miles traveled: " << num << endl;
        thirst++;
        camelTired++;
        nativeMiles = (nativeMiles + num) - num2;
    }




}

void drink(char choice, int& canteen, int& thirst)
{
    if (choice == 'A')
    {
        canteen = canteen - 1;
        thirst = 0;
    }
}
//Added to allow extra game
void killcamel(char& chosen, int& camelTired, bool& done)
{
    if (chosen == 'F')
    {
        camelTired = camelTired + 10;
        
    }
}
//Added as an intro
void noCamel()
{
    cout << "\n\n";
    cout << "Oh no! You lost your camel! The natives are right behind you! " << endl;
    cout << "What will you do?" << endl;
    cout << "A) Go to the cave in the West." << endl;
    cout << "B) Hide in the Camel's body." << endl;
    cout << "C) Take out your gun and kill natives." << endl;
    cout << "\n\n";
}
//choice variable 
char camelchoose()
{
    char choice;
    cin >> choice;
    choice = toupper(choice);
    
    return choice;
}

void camelA(char cchoice, bool& done)
{
    char choice;
    if(cchoice == 'A')
    {
        cout << "\n\n";
        cout << "As you're nearing the cave you hear a scream." << endl;
        cout << "A) Do you run?" << endl;
        cout << "B) Or do you go in?" << endl;
        choice = camelchoose();
        if (choice == 'A')
        {
            cout << "\n\n";
            cout << "You run out of the cave as fast as possible." << endl;
            cout << "After a little bit of running you turn back to see how far you've gotten from the cave." << endl;
            cout << "Seeing that the cave is far away and you see no native in sight so you merrily walk forward. " << endl;
            cout << "After a while of walking you accidently step on a trap and are eaten by a hungry cannibal who stole your gun." << endl;
            done = true;
           
        }
        if (choice == 'B')
        {
            cout << "\n\n";
            cout << "You cautiously walk into the cave following the odd noises." << endl;
            cout << "Once you're super close to the noise you quietly look into the hole in the cave." << endl;
            cout << "In the rock room you see a girl with a huge rock on her leg." << endl;
            cout << "You rush in and help the girl you end up fixing her leg and laying her in her bed." << endl;
            cout << "Ten years later you marry her and live happily ever after with 2 kids." << endl;
            done = true;
            
        }
    }
    done = true;
}

void camelB(char cchoice, bool& done)
{
    char choice;
    if(cchoice == 'B')
    {
        cout << "\n\n";
        cout << "You climb inside the camels body. After a while, you hear someone on the outside calling your name." << endl;
        cout << "Do you answer?" << endl;
        cout << "A) Yes!!!" << endl;
        cout << "B) NO!" << endl;
        choice = camelchoose();
    }
    if(choice == 'A')
    {
        cout << "Oh NO! The natives found you!!!" << endl;
    }
    if(choice == 'B')
    {
        cout << "You listen as the voice of the person calling your name fades away into the distance." << endl;
        cout << "You climb out of the camel and begin to wander off into to the desert." << endl;
        cout << "Where you eventually die of exposure" << endl;
    }
}

void camelC(char cchoice, bool& done)
{
    char choice;
    if(cchoice == 'C')
    {
        cout << "\n\n";
        cout << "You see humanoid figure standing out in the distance." << endl;
        cout << "Do you open fire." << endl;
        cout << "A) Yes!!!" << endl;
        cout << "B) NO!" << endl;
        cchoice = camelchoose();
        
    }
    if(cchoice == 'A')
    {
        cout << "You quickly undload your gun on the figure, but you quickly notice that there's nothing there." << endl;
        cout << "It was your mind playing tricks on you." << endl;
        cout << "What's worst the natives now know your position and are quickly charging towards you." << endl;
        cout << "You try running away but the natives are to quick for you, so they capture you and turn you into their slave." << endl;
    }
    if(cchoice == 'B')
    {
        cout << "You close your eyes for a short time. Once you open your eyes, you noticed that there's nothing there." << endl;
        cout << "You look out in to the distance to find the natives heading back to where they came from. The natives finally gave up trying to find you." << endl;
        
    }
}

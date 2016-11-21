#include <iostream>
#include <stdlib.h>
#include "player.h"
#include "game.h"
#include "room.h"

void game::init()
{
    //room listings
    room* first = new room();
    room* second = new room();
    room* third = new room();
    room* fourth = new room();
    room* fifth = new room();
    room* sixth = new room();
    room* seventh = new room();
    room* eighth = new room();
    room* ninth = new room();
    room* tenth = new room();
    room* eleventh = new room();
    room* twelfth = new room();
    room* thirteenth = new room();
    room* fourteenth = new room();
    room* fifteenth = new room();
    room* sixteenth = new room();
    room* seventeenth = new room();
    // room* eighteenth = new room();
    // room* nineteenth = new room();
    // room* twentieth = new room();
    room* twentifirst = new room();
    room* twentisecond = new room();
    room* twentithird = new room();
    room* twentifourth = new room();
    room* twentififth = new room();
    room* twentisixth = new room();
    room* twentiseventh = new room();
    // room* twentieighth = new room();
    // room* twentininth = new room();
    room* thirtieth = new room();

    first->setRoom(NORTH, second);
    first->setRoom(SOUTH, fourth);
    second->setRoom(EAST, third);
    third->setRoom(EAST, fifth);
    fourth->setRoom(WEST, eleventh);
    fourth->setRoom(EAST, thirteenth);
    fifth->setRoom(NORTH, sixth);
    fifth->setRoom(SOUTH, ninth);
    fifth->setRoom(EAST, seventh);
    seventh->setRoom(SOUTH, tenth);
    seventh->setRoom(EAST, eighth);
    eighth->setRoom(EAST, twentifirst);
    ninth->setRoom(EAST, tenth);
    tenth->setRoom(SOUTH, seventeenth);
    eleventh->setRoom(SOUTH, twelfth);
    twelfth->setRoom(SOUTH, twentisecond);
    thirteenth->setRoom(SOUTH, fourteenth);
    fourteenth->setRoom(EAST, fifteenth);
    fifteenth->setRoom(SOUTH, twentiseventh);
    sixteenth->setRoom(WEST, fifteenth);
    seventeenth->setRoom(NORTH, tenth);
    seventeenth->setRoom(SOUTH, sixteenth);
    // eighteenth->setRoom(EAST, twentieth);
    // nineteenth->setRoom(NORTH, eighteenth);
    // nineteenth->setRoom(WEST, sixteenth);
    twentisecond->setRoom(SOUTH, twentithird);
    twentithird->setRoom(SOUTH, thirtieth);
    twentifourth->setRoom(WEST, twentithird);
    twentififth->setRoom(WEST, twentifourth);
    twentisixth->setRoom(WEST, twentififth);
    twentiseventh->setRoom(SOUTH, twentisixth);
    // twentieighth->setRoom(WEST, twentisixth);
    // twentininth->setRoom(WEST, twentieighth);

    first->addDesc("\nYou're in your Cubicle. It's small, beige, and boring.\nThere's a poster of a kitty on the wall telling you to 'Hang in there buddy!'\nMotivation +1. Cynicism +5.\nThere are doors to the NORTH and SOUTH.");
    second->addDesc("\nYou're in the Hallway. The incandescent lights flicker drearily,\nreminding you of the soul-less nature of corporate America.\nThere are doors to the EAST and SOUTH.");
    third->addDesc("\nYou're in the Copy Room. The Xerox machine hums and whirs, perpetually copying, scanning, printing, and jamming;\nan apt metaphor for your life.\nThere are doors to the EAST and WEST.");
    fourth->addDesc("\nYou're in the Hallway. The incandescent lights flicker drearily, reminding you of the soul-less nature of corporate America.\nThere are doors to the EAST and WEST.");
    fifth->addDesc("\nYou're in the Lobby. The receptionist stares blankly at you as she answers the phone.\n'Thank you for calling Prather Corp. Please hold.'\nThere are doors to the NORTH, EAST, SOUTH and WEST.");
    sixth->addDesc("\nYou're in the Parking Lot. Fresh air! Just being outside feels so good;\nbut you know you won't find your boss here.\nThere are doors to the SOUTH.");
    seventh->addDesc("\nYou're in the Conference Room. A long table stretches into the dark room before you.\nThere are doors to the EAST, SOUTH, and WEST.");
    eighth->addDesc("\nYou're in the Hallway. The incandescent lights flicker drearily,\nreminding you of the soul-less nature of corporate America.\nThere are doors to the EAST and WEST.");
    ninth->addDesc("\nYou're in the Supplies Closet. Around you are stacks and stacks of paper, toner, pens, but no staplers...\nThere are doors to the NORTH.");
    tenth->addDesc("\nYou're in the Hallway. The incandescent lights flicker drearily,\nreminding you of the soul-less nature of corporate America.\nThere are doors to the NORTH and SOUTH.");
    eleventh->addDesc("It's the Break Room. Cheryl is here.\n'Want to hear my favourite story?' asks Cheryl.(YES/NO)");
    twelfth->addDesc("\nYou're in the Hallway. The incandescent lights flicker drearily,\nreminding you of the soul-less nature of corporate America.\nThere are doors to the NORTH and SOUTH.");
    thirteenth->addDesc("\nYou're in the Server Closet. Wires. Wires everywhere.\nThe closet is a mess. You keep meaning to fix this, but where to start?\nThere are rooms to the SOUTH and WEST.");
    fourteenth->addDesc("\nYou're in the Bathroom. There's a pervasive smell of urine and those urinal donut things.\nThere are doors to the NORTH and EAST.");
    fifteenth->addDesc("\nYou're in the Janitor Closet. It's mostly mops and cleaning supplies. What did you expect?\nThere are doors to the EAST, SOUTH, and WEST.");
    sixteenth->addDesc("\nYou're in the Atrium. The skylights provide a constant reminder that you're stuck inside.\nThere are doors to the NORTH and WEST.");
    seventeenth->addDesc("\nYou're in the Stairwell. There's stairs going up and down, which is odd because there's only one floor.\nThere are doors to the NORTH and SOUTH.");
    twentifirst->addDesc("\nYou're in the Company Dungeon. It's dark and damp. Strange noises echo in the dark. Your skin crawls.\nThere are doors to the WEST.");
    twentisecond->addDesc("\nYou're in the Call Center. The phones ring incessantly. Ask not for whom the phone rings. It rings for thee.\nThere are doors to the NORTH and SOUTH.");
    twentithird->addDesc("\nYou're in the Commissary. The smell of questionable meals wafts under your nose.\nYou're put off by the mystery amalgamation they're serving today.\nThere are doors to the NORTH, EAST, and SOUTH.");
    twentifourth->addDesc("You're in the Boss's Bathroom!");
    twentififth->addDesc("\nYou're in the Testing Lab. The room is incredibly sterile. And here you are tracking your dirt shoes across the floor!\nThere are doors to the EAST and WEST.");
    twentisixth->addDesc("\nYou're in the Executive Suite. Your Boss's office is plush, elegant, and the reason no one got bonuses last year.\nThere are doors to the NORTH and WEST.");
    twentiseventh->addDesc("\nYou're in the Accounting Department. This is where the Bean Pushers work the books. They never laugh at you're jokes.\nWhat nerds.");
    thirtieth->addDesc("You're in the Human Resources Office. This is where you bring your late timesheets. This is where they tell you sending Cat Pics to the entire staff is inappropriate behaviour.\nThere are doors to the NORTH.");    
    
    player::playerGet()->setLocation(first);
    
    //START DIALOGUE
    cout << "\nMONDAY -- 9AM\nYou've settled into the routine at you job here at PratherCorp.\nEach day you show up, check your email, check Reddit, get coffee, go to the bathroom to play Tetris on your phone.\nCheck your email. Ignore the email your mom sent you.\nRead the memo about TPS reports. Toss the memo into hoop over the garbarge.\nYou miss.\nLunch break!\nSomeone ate your sandwich in the break room, probably Steve...\nBack to your Desk. Check email. Check Re--OH CRAP\nYou see your boss walking across the office towards you. You hunker down hoping to go unnoticed.\n'Well hello.' says Lumbergh.\n'Listen, I'm going to need one those computery programs you make for my board meeting at 5 today. \nThink you can do that? If you could do that, that would be greeaaat.'\nLumbergh leaves. You look at your computer. You think about crying. You think about quitting. You bang you head on the keyboard.\nYou take a deep breath and start typing.\nHuh. It only took you like an hour to write.\nMust be due to your excellent Professors.\nYou save the program to your floppy. You get up."<< endl;
    
    cout << "\nWhat would you like to do?\nYou have " << deadline << " moves to find your boss!\nYou can 'GO NORTH' or a similar direction.\nYou can also 'CHECK TIME' and 'LOOK AROUND'\n"<< endl;
}

game::game()
{
    deadline = 150;
    commandChain = new go();
    commandChain->addNext(new look());
    commandChain->addNext(new check());
    commandChain->addNext(new use());
    commandChain->addNext(new no());
    commandChain->addNext(new showMap());
    commandChain->addNext(new quit());
    commandChain->addNext(new invalid());
    
    
}
game::~game()
{
}
game* game::instance = new game;
game* game::getter()
{
    return instance;
}
void game::checkTime()
{
    cout << "You have: " << deadline << " moves left till you're late!" << endl;
    //return deadline;
}
void game::changeDeadline(int deadlineChange)
{
	deadline += deadlineChange;
	return;
}
void game::deadlineDec()
{
    deadline--;
    if (deadline == 0)
    {
        std::cout << endl << "You missed your deadline!" << endl << endl << "Running through the hallway, you barge into the conference room." << endl << "Your boss looks up from a very important TPS report and gives you the death glare." << endl << "You gulp." << endl << "You know you're done." << endl << "You're fired." << endl << endl << "THREE MONTHS LATER" << endl << endl << "You've adjusted to your new life living in your van down by the river." << endl <<"Occasionally you call your mother, only to hear her sob about how you threw away your potential." << endl <<"She cries." << endl << "You raise the bottle to your mouth, yearning for the sweet release." << endl << endl << "FOUR MONTHS LATER" << endl << endl << "The priest stands over the grave, silent and alone. 'Such a shame' he mutters." << endl << "'Dust to dust, ash to ash'. Crumbled soil falls onto the coffin." << endl <<"The priest turns and walks away." << endl << endl << "YOU LOSE." << endl;
        exit(0);
    }
}
void game::input(string com)
{
    // std::cout << "AKBAR!";
    string input = com;
    string remaining = "";
    for (int i = 0; (unsigned)i < com.length(); i++)
    {
        if (com[i] == ' ')
        {
            input = com.substr(0, i);
            remaining = com.substr(i+1);
            break;
        }
    }
    // std::cout << "WOOF";
    commandChain->execute(input, remaining);
}
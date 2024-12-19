#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

#define ROW 2
#define COL 2
#define QUESTIONS 100
#define PROBLEMS 19

// GLOBAL VARIABLES
int rpsPoints = 0;
int quizBeePoints = 0;
int mathCrazePoints = 0;
bool repeatGame = true;

void rps();
void quizBee();
void mathCraze();

void mainMenu(){
    printf("\t\t\t\t\t--------------------------------");
    printf("\n\t\t\t\t\t     MINIGAMES BUNDLE IN C\n");
    printf("\t\t\t\t\t      made by EightisVIII\n");
    printf("\t\t\t\t\t--------------------------------");

    printf("\n\n\t\t\t\t\t   ------- SELECTION -------");
    printf("\n\t\t\t\t\t     1. Rock-Paper-Scissors");
    printf("\n\t\t\t\t\t     2. Quiz Bee");
    printf("\n\t\t\t\t\t     3. Math Craze");
    printf("\n\t\t\t\t\t     4. Exit Game");
    printf("\n\t\t\t\t\t   -------------------------");
}

int main(){
    int choice;
    srand(time(NULL));

    while(1){
        system("cls");
        mainMenu();

        printf("\n\n\t\t\t\t\t     Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 4){
          printf("\n\n\t\t\t\t\t ------- SEE YOU LATER! -------");
          break;
        } else if(choice < 1 || choice > 4){
          printf("\n\t\t\t\t\tIncorrect input! Please try again!\n");
          getch();
          continue;
        }

        do{
          system("cls");
          if(choice == 1){
            rps();
          } else if(choice == 2){
            quizBee();
          } else if(choice == 3){
            mathCraze();
          }
          getch();
        } while(repeatGame);
    }

    return 0;
}

void pColor(){
  printf("\033[1;32m");
}

void botColor(){
  printf("\033[1;37m");
}

void resetColor(){
  printf("\033[0m");
}

void rps(){
    char rpsChoice;

    printf("Score: %d\n", rpsPoints);
    printf("\t\t\t\t\t    --------------------------------");
    printf("\n\t\t\t\t\t\t  ROCK PAPER SCISSORS\n");
    printf("\t\t\t\t\t    --------------------------------");
    printf("\n\t\t\t\t      \'s\' for scissor, \'p\' for paper, \'r\' for rock\n");
    printf("\t\t\t\t\t\'q\' to quit, \'m\' to go back to main menu\n\n");
    pColor();
    printf("\t\t\t\t\t\t       You: ");
    resetColor();
    scanf(" %c", &rpsChoice);

    int rng = rand() % 100;

    // QUIT
    if(rpsChoice == 'q'){
        printf("\n\t\t\t\t\t       Alright, maybe next time!\n");
        repeatGame = false;
        exit(0);
    } else if(rpsChoice == 'm'){
        repeatGame = false;
        return;
    }

    botColor();
    printf("\t\t\t\t\t\t       Bot: ");
    resetColor();

    char botChoice;
    // ASSIGN CHOICE TO RNG
    if(rng < 33){
        printf("s");
        botChoice = 's';
    } else if(rng > 33 && rng < 66){
        printf("p");
        botChoice = 'p';
    } else{
        printf("r");
        botChoice = 'r';
    }

    // ALL POSSIBILITIES
    if((rpsChoice == 'p' && botChoice == 's') ||
       (rpsChoice == 's' && botChoice == 'r') ||
       (rpsChoice == 'r' && botChoice == 'p')){
        botColor();
        printf("\n\n\t\t\t\t\t\t   Bot Wins\n");
        resetColor();
    } else if(rpsChoice == botChoice){
        printf("\n\n\t\t\t\t\t\t     Draw\n");
    } else if((rpsChoice == 'p' && botChoice == 'r') ||
              (rpsChoice == 's' && botChoice == 'p') ||
              (rpsChoice == 'r' && botChoice == 's')){
        pColor();
        printf("\n\n\t\t\t\t\t\t    You Win\n");
        resetColor();
        rpsPoints += 1;
    } else{
        printf("\n\t\t\t\t\tIncorrect input! Restarting...\n");
        return;
    }
}

void setQuestions();

void shuffleQuestions(int *arr, int n);

void quizBee(){
    char areYouReady;
    int q[QUESTIONS];

    for(int i = 0; i < QUESTIONS; i++){
        q[i] = i + 1;
    }

    shuffleQuestions(q, QUESTIONS);

    printf("\t\t\t\t\t    --------------------------------");
    printf("\n\t\t\t\t\t\t        QUIZ BEE\n");
    printf("\t\t\t\t\t    --------------------------------");
    printf("\n\t\t\tYou will be given a randomized set of questions with various genres and categories.\n");
    printf("\t\t\t       Make sure to enter the correct capitalization and spaces!\n\n");
    printf("\t\t\t\t     Answer \'m\' to go back to main menu or \'n\' to quit.");
    pColor();
    printf("\n\t\t\t\t\t\t   Are you ready? ");
    resetColor();
    scanf(" %c", &areYouReady);

    if(areYouReady == 'y' || areYouReady == 'Y'){
      printf("\n\t\t\t\t\t\tQUESTIONNAIRE\n");
      for(int i = 0; i < 20; i++){
        printf("\t\t%d. ", i + 1);
        setQuestions(q[i]);
        printf("\n");
      }
      printf("\t\tFinal Score: %d\n", quizBeePoints);
    } else if(areYouReady == 'n' || areYouReady == 'N'){
      printf("\n\t\t\t\t\t       Alright, maybe next time!\n");
      exit(0);
    } else if(areYouReady == 'm'){
      repeatGame = false;
      return;
    } else{
      printf("\n\t\t\t\t\tIncorrect input! Restarting...\n");
    }
}

void setQuestions(int q){
    char a, ans[50];

    // EASY
    switch(q){
      case 1:
        printf("Who was the Ancient Greek God of the Sun?\n");
        printf("\t\ta. Zeus\t\tb. Apollo");
        printf("\n\t\tc. Dionysus\td. Hera\n");
        printf("\t\tAnswer: ");
        scanf(" %c", &a);
        if(a == 'b'){
            quizBeePoints += 1;
        }
        getchar();
        break;
      case 2:
        printf("Acrophobia is a fear of...\n");
        printf("\t\ta. Frogs\t\tb. Acrobats\n");
        printf("\t\tc. Air\t\t\td.Heights\n");
        printf("\t\tAnswer: ");
        scanf(" %c", &a);
        if(a == 'd'){
            quizBeePoints += 1;
        }
        getchar();
        break;
      case 3:
        printf("The first Disney Princess.\n");
        printf("\t\ta. Cinderella\t\tb. Ariel\n");
        printf("\t\tc. Snow White\t\td. Elsa\n");
        printf("\t\tAnswer: ");
        scanf(" %c", &a);
        if(a == 'c'){
            quizBeePoints += 1;
        }
        getchar();
        break;
      case 4:
        printf("What is the capital of France?\n");
        printf("\t\ta. Rome\t\tb. Paris\n");
        printf("\t\tc. Berlin\td. Madrid\n");
        printf("\t\tAnswer: ");
        scanf(" %c", &a);
        if(a == 'b'){
            quizBeePoints += 1;
        }
        getchar();
        break;
      case 5:
        printf("Which planet is known as the Red Planet?\n");
        printf("\t\ta. Earth\t\tb. Venus\n");
        printf("\t\tc. Mars\t\t\td. Jupiter\n");
        printf("\t\tAnswer: ");
        scanf(" %c", &a);
        if(a == 'c'){
            quizBeePoints += 1;
        }
        getchar();
        break;
      case 6:
        printf("Which is the smallest prime number?\n");
        printf("\t\ta. 0\t\tb. 1\n");
        printf("\t\tc. 2\t\td. 3\n");
        printf("\t\tAnswer: ");
        scanf(" %c", &a);
        if(a == 'c'){
            quizBeePoints += 1;
        }
        getchar();
        break;
      case 7:
        printf("Which animal is known as the King of the Jungle?\n");
        printf("\t\ta. Tiger\t\tb. Elephant\n");
        printf("\t\tc. Lion\t\t\td. Cheetah\n");
        printf("\t\tAnswer: ");
        scanf(" %c", &a);
        if(a == 'c'){
            quizBeePoints += 1;
        }
        getchar();
        break;
      case 8:
        printf("What is the boiling point of water?\n");
        printf("\t\ta. 100C\t\tb. 0C\n");
        printf("\t\tc. 50C\t\td. 200C\n");
        printf("\t\tAnswer: ");
        scanf(" %c", &a);
        if(a == 'a'){
            quizBeePoints += 1;
        }
        getchar();
        break;
      case 9:
        printf("What is the largest mammal in the world?\n");
        printf("\t\ta. Elephant\t\tb. Blue Whale\n");
        printf("\t\tc. Shark\t\td. Giraffe\n");
        printf("\t\tAnswer: ");
        scanf(" %c", &a);
        if(a == 'b'){
            quizBeePoints += 1;
        }
        getchar();
        break;
      case 10:
        printf("Which color is made by mixing red and yellow?\n");
        printf("\t\ta. Green\t\tb. Orange\n");
        printf("\t\tc. Purple\t\td. Brown\n");
        printf("\t\tAnswer: ");
        scanf(" %c", &a);
        if(a == 'b'){
            quizBeePoints += 1;
        }
        getchar();
        break;

    // MEDIUM
      case 11:
        printf("The first president of the United States is:\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Washington") == 0 || strcmp(ans, "George Washington") == 0){
            quizBeePoints += 3;
        }
        break;
      case 12:
        printf("What is the first anime made in Japan?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Nakamura Gatana") == 0 || strcmp(ans, "Blunt Sword") == 0){
            quizBeePoints += 3;
        }
        break;
      case 13:
        printf("____ is the powerhouse of the cell.\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Mitochondria") == 0){
            quizBeePoints += 3;
        }
        break;
      case 14:
        printf("What is the chemical symbol for gold?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Au") == 0){
            quizBeePoints += 3;
        }
        break;
      case 15:
        printf("Who wrote 'Romeo and Juliet'?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Shakespeare") == 0|| strcmp(ans, "William Shakespeare") == 0){
            quizBeePoints += 3;
        }
        break;
      case 16:
        printf("What Disney movie has the most sequels?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Toy Story") == 0){
            quizBeePoints += 3;
        }
        break;
      case 17:
        printf("Which planet in our solar system has the most moons?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Saturn") == 0){
            quizBeePoints += 3;
        }
        break;
      case 18:
        printf("Who painted the Mona Lisa?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Da Vinci") == 0 || strcmp(ans, "Leonardo Da Vinci") == 0){
            quizBeePoints += 3;
        }
        break;
      case 19:
        printf("What is the largest organ in the human body?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Skin") == 0){
            quizBeePoints += 3;
        }
        break;
      case 20:
        printf("Which programming language is known for its snake logo?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Python") == 0){
            quizBeePoints += 3;
        }
        break;

    // HARD
      case 21:
        printf("What is the name of the closest star to Earth besides the star?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Proxima Centauri") == 0){
            quizBeePoints += 5;
        }
        break;
      case 22:
        printf("What animal is considered a mammal and can lay eggs?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Platypus") == 0){
            quizBeePoints += 5;
        }
        break;
      case 23:
        printf("What city is recognized as the northernmost capital city worldwide?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Reykjavik") == 0){
            quizBeePoints += 5;
        }
        break;
      case 24:
        printf("What is the mathematical name for a shape with 20 sides?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Icosagon") == 0){
            quizBeePoints += 5;
        }
        break;
      case 25:
        printf("In what year was the theory of general relativity published?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "1915") == 0){
            quizBeePoints += 5;
        }
        break;
      case 26:
        printf("TRUE OR FALSE: Javascript is a complex language used to build sophisticated applications.\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "FALSE") == 0){
            quizBeePoints += 5;
        }
        break;
      case 27:
        printf("TRUE OR FALSE: Eggplant is a berry.\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "TRUE") == 0){
            quizBeePoints += 5;
        }
        break;
      case 28:
        printf("TRUE OR FALSE: The human brain is made up mostly of fat.\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "TRUE") == 0){
            quizBeePoints += 5;
        }
        break;
      case 29:
        printf("TRUE OR FALSE: A human loses their heat the most through their feet.\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "FALSE") == 0){
            quizBeePoints += 5;
        }
        break;
      case 30:
        printf("TRUE OR FALSE: Humans lose an average of 75 strands of hair per week.\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "FALSE") == 0){
            quizBeePoints += 5;
        }
        break;

    // MIXED
      case 31:
        printf("What is the name of Jupiter's largest moon?\n");
        printf("\t\ta. Callisto\t\tb. Io\n");
        printf("\t\tc. Titan\t\td. Ganymede\n");
        printf("\t\tAnswer: ");
        scanf(" %c", &a);
        if(a == 'd'){
            quizBeePoints += 1;
        }
        getchar();
        break;
      case 32:
        printf("What is the capital city of Japan?\n");
        printf("\t\ta. Tokyo\t\tb. Beijing\n");
        printf("\t\tc. Seoul\t\td. Bangkok\n");
        printf("\t\tAnswer: ");
        scanf(" %c", &a);
        if(a == 'a'){
            quizBeePoints += 1;
        }
        getchar();
        break;
      case 33:
        printf("Who is known as the 'Father of Computer Science'?\n");
        printf("\t\ta. Charles Babbage\tb. Alan Turing\n");
        printf("\t\tc. Bill Gates\t\td. Steve Jobs\n");
        printf("\t\tAnswer: ");
        scanf(" %c", &a);
        if(a == 'b'){
            quizBeePoints += 1;
        }
        getchar();
        break;
      case 34:
        printf("Which gas do plants absorb during photosynthesis?\n");
        printf("\t\ta. Oxygen\t\tb. Carbon Dioxide\n");
        printf("\t\tc. Nitrogen\t\td. Hydrogen\n");
        printf("\t\tAnswer: ");
        scanf(" %c", &a);
        if(a == 'b'){
            quizBeePoints += 1;
        }
        getchar();
        break;
      case 35:
        printf("What year did World War II end?\n");
        printf("\t\ta. 1940\t\tb. 1943\n");
        printf("\t\tc. 1945\t\td. 1950\n");
        printf("\t\tAnswer: ");
        scanf(" %c", &a);
        if(a == 'c'){
            quizBeePoints += 1;
        }
        getchar();
        break;
      case 36:
        printf("What is the smallest mammal in the world?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Etruscan Shrew") == 0){
            quizBeePoints += 3;
        }
        break;
      case 37:
        printf("Which element has the atomic number 117?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Tennessine") == 0){
            quizBeePoints += 3;
        }
        break;
      case 38:
        printf("What is the largest desert in the world?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Sahara") == 0){
            quizBeePoints += 3;
        }
        break;
      case 39:
        printf("What is the capital of Australia?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Canberra") == 0){
            quizBeePoints += 3;
        }
        break;
      case 40:
        printf("What is the term for animals that eat both plants and meat?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Omnivores") == 0){
            quizBeePoints += 3;
        }
        break;
      case 41:
        printf("TRUE OR FALSE: Water expands when it freezes.\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "TRUE") == 0){
            quizBeePoints += 5;
        }
        break;
      case 42:
        printf("TRUE OR FALSE: A group of crows is called a murder.\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "TRUE") == 0){
            quizBeePoints += 5;
        }
        break;
      case 43:
        printf("TRUE OR FALSE: The Great Wall of China is visible from the moon.\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "FALSE") == 0){
            quizBeePoints += 5;
        }
        break;
      case 44:
        printf("TRUE OR FALSE: The Eiffel Tower can grow taller in the summer.\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "TRUE") == 0){
            quizBeePoints += 5;
        }
        break;
      case 45:
        printf("TRUE OR FALSE: Dolphins sleep with one eye open.\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "TRUE") == 0){
            quizBeePoints += 5;
        }
        break;
      case 46:
        printf("Which planet is the hottest in the solar system?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Venus") == 0){
            quizBeePoints += 5;
        }
        break;
      case 47:
        printf("What is the rarest blood type?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "AB-") == 0){
            quizBeePoints += 5;
        }
        break;
     case 48:
        printf("What is the smallest bone in the human body?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Stapes") == 0 || strcmp(ans, "Stirrup") == 0){
            quizBeePoints += 5;
        }
        break;
      case 49:
        printf("What is the name of the galaxy we live in?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Milky Way") == 0){
            quizBeePoints += 5;
        }
        break;
      case 50:
        printf("What organelle is responsible for photosynthesis?\n");
        printf("\t\tAnswer: ");
        fgets(ans, sizeof(ans), stdin);
        strtok(ans, "\n");
        if(strcmp(ans, "Chloroplast") == 0){
            quizBeePoints += 5;
        }
        break;
    case 51:
      printf("What is the largest planet in our solar system?\n");
      printf("\t\ta. Earth\t\tb. Jupiter\n");
      printf("\t\tc. Saturn\t\td. Neptune\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'b'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 52:
      printf("The term for a group of crows.\n");
      printf("\t\ta. Murder\t\tb. Flight\n");
      printf("\t\tc. Flock\t\td. Colony\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'a'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 53:
      printf("What animal is Taz from Looney Toons?\n");
      printf("\t\ta. Dog\t\tb. Tasmanian Devil\n");
      printf("\t\tc. Hyena\td. Thylacine\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'b'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 54:
      printf("It is estimated that Greenland's population is:\n");
      printf("\t\ta. 57,000\tb. 50,000\n");
      printf("\t\tc. 56,000\td. 60,000\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'a'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 55:
      printf("What is Scotland's official animal?\n");
      printf("\t\ta. Pony\t\tb. Scottish Wildcat\n");
      printf("\t\tc. Unicorn\td. Basking Shark\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'b'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 56:
      printf("Which country has the world's largest population?\n");
      printf("\t\ta. China\tb. India\n");
      printf("\t\tc. America\td. Indonesia\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'b'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 57:
      printf("What is a fear of clowns called?\n");
      printf("\t\ta. Clownphobia\tb. Coulrophobia\n");
      printf("\t\tc. Clourophobia\td. Aerophobia\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'b'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 58:
      printf("Who was the first scientist to win a Nobel Prize?\n");
      printf("\t\ta. Wilhelm Conrad Röntgen\tb. Pierre Curie\n");
      printf("\t\tc. Marie Curie\t\t\td. Isaac Newton\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'a'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 59:
      printf("Meteorology is the study of: \n");
      printf("\t\ta. Meteors\tb. Stars\n");
      printf("\t\tc. Space\td. Weather\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'd'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 60:
      printf("What scale deems 10 a basic?\n");
      printf("\t\ta. pH Scale\tb. Architectural Scale\n");
      printf("\t\tc. Likert Scale\td. Richter Scale\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'a'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 61:
      printf("Which animal produce pearls the most?\n");
      printf("\t\ta. Clams\tb. Oysters\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'b'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 62:
      printf("What is the currency of Japan?\n");
      printf("\t\ta. Yen\tb. Yuan\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'a'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 63:
      printf("What is the biggest prime number?\n");
      printf("\t\ta. 2^136,279,841 − 1\tb. 2^82,589,933 - 1\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'a'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 64:
      printf("How many days are in a Chinese New Year?\n");
      printf("\t\ta. 28\tb. 23\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'b'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 65:
      printf("Which planet has the most gravity?\n");
      printf("\t\ta. Earth\tb. Jupiter\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'b'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 66:
      printf("How many continents are there on Earth?\n");
      printf("\t\ta. 7\tb. 8\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'a'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 67:
      printf("What is the largest internal organ?\n");
      printf("\t\ta. Heart\tb. Liver\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'b'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 68:
      printf("What is the capital of Canada?\n");
      printf("\t\ta. Toronto\tb. Ottawa\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'b'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 69:
      printf("Who is the artist that has created the most art in the world?\n");
      printf("\t\ta. Picasso\tb. Da Vinci\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'a'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 70:
      printf("Which part of the plant conducts photosynthesis?\n");
      printf("\t\ta. Chloroplasts\tb. Mesophyll\n");
      printf("\t\tAnswer: ");
      scanf(" %c", &a);
      if(a == 'a'){
          quizBeePoints += 1;
      }
      getchar();
      break;
    case 71:
      printf("TRUE OR FALSE: Humans share approximately 60-percent of their DNA with bananas.\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "TRUE") == 0){
          quizBeePoints += 3;
      }
      break;
    case 72:
      printf("TRUE OR FALSE: There are 24 hours in a day because of Earth's rotation.\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "TRUE") == 0){
          quizBeePoints += 3;
      }
      break;
    case 73:
      printf("TRUE OR FALSE: Penguins can fly.\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "FALSE") == 0){
          quizBeePoints += 3;
      }
      break;
    case 74:
      printf("What is the scientific name for humans?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "Homo sapiens") == 0){
          quizBeePoints += 3;
      }
      break;
    case 75:
      printf("Which country gifted the Statue of Liberty to the United States?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "France") == 0){
          quizBeePoints += 3;
      }
      break;
    case 76:
      printf("What is the term for animals that eat only plants?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "Herbivores") == 0){
          quizBeePoints += 3;
      }
      break;
    case 77:
      printf("Which planet has the most moons?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "Saturn") == 0){
          quizBeePoints += 3;
      }
      break;
    case 78:
      printf("Who discovered penicillin?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "Alexander Fleming") == 0){
          quizBeePoints += 3;
      }
      break;
    case 79:
      printf("What is the smallest unit of life?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "Cell") == 0){
          quizBeePoints += 3;
      }
      break;
    case 80:
      printf("What is the name of the closest star to Earth?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "Sun") == 0){
          quizBeePoints += 3;
      }
      break;
    case 81:
      printf("How many sides does a hexagon have?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "6") == 0){
          quizBeePoints += 3;
      }
      break;
    case 82:
      printf("What planet is the hottest planet?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "Mercury") == 0){
          quizBeePoints += 3;
      }
      break;
    case 83:
      printf("What is the capital of Italy?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "Rome") == 0){
          quizBeePoints += 3;
      }
      break;
    case 84:
      printf("What is the freezing point of water in Fahrenheit?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "32") == 0){
          quizBeePoints += 3;
      }
      break;
    case 85:
      printf("What does DNA stand for?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "Deoxyribonucleic Acid") == 0){
          quizBeePoints += 5;
      }
      break;
    case 86:
      printf("What is the largest insect in the world?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "Giant Weta") == 0){
          quizBeePoints += 5;
      }
      break;
    case 87:
      printf("Who wrote the 'Harry Potter' series?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "J.K. Rowling") == 0){
          quizBeePoints += 5;
      }
      break;
    case 88:
      printf("How many bones are in an adult human body?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "206") == 0){
          quizBeePoints += 5;
      }
      break;
    case 89:
      printf("How many bones are in an infant human body?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "300") == 0 || strcmp(ans, "275") == 0){
          quizBeePoints += 5;
      }
      break;
    case 90:
      printf("What is the smallest organ in the human body?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "Pineal Gland") == 0){
          quizBeePoints += 5;
      }
      break;
    case 91:
      printf("What is the world's smallest country?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "Vatican City") == 0 || strcmp(ans, "Vatican") == 0){
          quizBeePoints += 5;
      }
      break;
    case 92:
      printf("Who invented the telephone?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "Alexander Graham Bell") == 0){
          quizBeePoints += 5;
      }
      break;
    case 93:
      printf("What is the smallest planet in the solar system?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "Mercury") == 0){
          quizBeePoints += 5;
      }
      break;
    case 94:
      printf("What is the chemical symbol for Mercury?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "Hg") == 0){
          quizBeePoints += 5;
      }
      break;
    case 95:
      printf("What is the capital of the United States?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "Washington D.C.") == 0){
          quizBeePoints += 5;
      }
      break;
    case 96:
      printf("How many movies has Disney made as of 2024?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "748") == 0){
          quizBeePoints += 5;
      }
      break;
    case 97:
      printf("What is the capital of India?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "New Delhi") == 0){
          quizBeePoints += 5;
      }
      break;
    case 98:
      printf("What is the hottest continent on Earth?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "Africa") == 0){
          quizBeePoints += 5;
      }
      break;
    case 99:
      printf("What is the name of the largest ocean on Earth?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "Pacific Ocean") == 0){
          quizBeePoints += 5;
      }
      break;
    case 100:
      printf("What is the most abundant gas in the Earth's atmosphere?\n");
      printf("\t\tAnswer: ");
      fgets(ans, sizeof(ans), stdin);
      strtok(ans, "\n");
      if(strcmp(ans, "Nitrogen") == 0){
          quizBeePoints += 5;
      }
      break;
    }
}

void mathQs(int q1);

void mathCraze(){
    char areYouReady;
    int q1[PROBLEMS];

    for(int i = 0; i < PROBLEMS; i++){
        q1[i] = i + 1;
    }

    shuffleQuestions(q1, PROBLEMS);

    printf("\t\t\t\t\t    --------------------------------");
    printf("\n\t\t\t\t\t\t        MATH CRAZE\n");
    printf("\t\t\t\t\t    --------------------------------");
    printf("\n\t\t\t      You will be given a randomized set of college-level math to solve.\n\n");
    printf("\t\t\t\t     Answer \'m\' to go back to main menu or \'n\' to quit.");
    pColor();
    printf("\n\t\t\t\t\t\t   Are you ready? ");
    resetColor();
    scanf(" %c", &areYouReady);

    printf("\n\t\t\t\t\t\tQUESTIONNAIRE\n");
    if(areYouReady == 'y' || areYouReady == 'Y'){
      for(int j = 0; j < 10; j++){
        printf("\t\t%d. ", j + 1);
        mathQs(q1[j]);
        printf("\n");
      }
    } else if(areYouReady == 'n' || areYouReady == 'N'){
        printf("\n\t\t\t\t\t       Alright, maybe next time!\n");
        exit(0);
    } else if(areYouReady == 'm'){
        repeatGame = false;
        return;
    } else{
        printf("\n\t\t\t\t\tIncorrect input! Restarting...\n");
    }
}

void mathQs(int q1){
    int pAnswer, pAns[2], pA[ROW][COL];
    float playerA;    // PLAYER ANSWER

    int q2 = rand() % 25 + 1;  // NUMBER RANDOMIZER
    int q3 = rand() % 15 + 1;  // 2nd NUMBER RANDOMIZER
    int q4 = rand() % 2;       // RANDOMIZER
    int i = 3, mathQ = 0;      // LOOP VARIABLES
    int ans;                   // STORES RESULTS
    float fAns;                // FLOAT RESULT
    float mathQf = 0;          // FOR DIVISION)

    // LINEAR EQUATIONS
    int y = 1 + rand() % 10 + 1;
    int x = 1 + rand() % 10 + 1;

     int A = 1 + rand() % 10 + 1;
     int B = 1 + rand() % 10 + 1;
     int C = 1 + rand() % 10 + 1;
     int a = 1 + rand() % 10 + 1;
     int b = 1 + rand() % 10 + 1;
     int c, c2;

     int linearAns[2];

    // MATRIX
    int d[ROW][COL], e[ROW][COL];        // 2x2 MATRIX
    int f[ROW][COL];                    // ANSWER MATRIX
    int j, k, l;                       // LOOP VARIABLES
    int determinant, prodAD, prodCB;  // FOR DETERMINANTS

    // TRIGONOMETRY
    int sides = rand() % 3;      // RANDOMIZER
    int hyp = rand() % 10 + 1;
    int opp = rand() % 10 + 1;
    int adj = rand() % 10 + 1;
    int hypMis, oppMis, adjMis; // MISSING VARIABLES
    float SOH, CAH, TOA;

  switch(q1){
    // ARITHMETIC OPERATIONS
    case 1:
        printf("%d, %d, ", q2, q3);
        while(i <= 6){
          mathQ = q2 + q3;

          if(i == 6){
              printf("___");
              ans = mathQ;
              break;
          } else{
              printf("%d, ", mathQ);
          }

          if(q4 == 1){
              q2 = q3;
              q3 = mathQ;
          } else{
              q2 = mathQ;
          }

          i++;
        }

        printf("\n\t\tAnswer: ");
        scanf("%d", &pAnswer);
        if(pAnswer == ans){
          mathCrazePoints++;
        }
        break;
    case 2:
        printf("%d, %d, ", q2, q3);
        while(i <= 6){
          mathQ = q2 - q3;

          if(i == 6){
              printf("___");
              ans = mathQ;
              break;
          } else{
              printf("%d, ", mathQ);
          }

          if(q4 == 1){
              q2 = q3;
              q3 = mathQ;
          } else{
              q2 = mathQ;
          }

          i++;
        }

        printf("\n\t\tAnswer: ");
        scanf("%d", &pAnswer);
        if(pAnswer == ans){
          mathCrazePoints++;
        }
        break;
    case 3:
        printf("%d, %d, ", q2, q4);
        while(i <= 6){
          mathQ = q2 * q4;

          if(i == 6){
              printf("___");
              ans = mathQ;
              break;
          } else{
              printf("%d, ", mathQ);
          }

          q2 = q4;
          q4 = mathQ;
          i++;
        }

        printf("\n\t\tAnswer: ");
        scanf("%d", &pAnswer);
        if(pAnswer == ans){
          mathCrazePoints++;
        }
        break;
    case 4:
        printf("%d, %d, ", q2, q3);
        while(i <= 6){
          mathQ = q2 * q3;

          if(i == 6){
              printf("___");
              ans = mathQ;
              break;
          } else{
              printf("%d, ", mathQ);
          }

          q2 = mathQ;
          i++;
        }

        printf("\n\t\tAnswer: ");
        scanf("%d", &pAnswer);
        if(pAnswer == ans){
          mathCrazePoints++;
        }
        break;
    case 5:
        printf("%.2f, %.2f, ", (float)q2, (float)q3);
        while(i <= 6){
          if(q3 == 0){
            q3 = 1;
          }

          mathQf = (float)q2 / q3;

          if(i == 6){
              printf("___");
              fAns = mathQf;
              break;
          } else{
              printf("%.2f, ", mathQf);
          }

          if(q4 == 1){
              q2 = q3;
              q3 = mathQf;
          } else{
              q2 = mathQf;
          }

          i++;
        }

          printf("\n\t\tAnswer: ");
          scanf("%d", &pAnswer);
          if(pAnswer == fAns){
            mathCrazePoints++;
          }
          break;

    //LINEAR EQUATIONS
    case 6:
        printf("%dx + %dy = %d", A, B, C);

        // FIND X
        if(q4 == 1){
            printf("\n\t\t   y = %d", y);
            B = B * y;
            ans = -B + C;
            ans /= A;

            printf("\n\t\t   x = ");
            scanf("%d", &pAnswer);
            if(pAnswer == ans){
                mathCrazePoints++;
            }
        }
        // FIND Y
        else{
            printf("\n\t\t   x = %d", x);
            A = A * x;
            ans = -A + C;
            ans /= B;

            printf("\n\t\t   y = ");
            scanf("%d", &pAnswer);
            if(pAnswer == ans){
                mathCrazePoints++;
            }
        }
        break;
    case 7:
        printf("%dx - %dy = %d", A, B, C);

        // FIND X
        if(q4 == 1){
            printf("\n\t\t   y = %d", y);
            B = B * y;
            ans = B + C;
            ans /= A;

            printf("\n\t\t   x = ");
            scanf("%d", &pAnswer);
            if(pAnswer == ans){
                mathCrazePoints++;
            }
        }
        // FIND Y
        else{
            printf("\n\t\t   x = %d", x);
            A = A * x;
            ans = -A + C;
            ans /=  -B;

            printf("\n\t\t   y = ");
            scanf("%d", &pAnswer);
            if(pAnswer == ans){
                mathCrazePoints++;
            }
        }
        break;
    case 8:
        c = a * x + b * y;
        c2 = A * x + B * y;

        printf("Equation 1: %dx + %dy = %d\n", a, b, c);
        printf("\t\t   Equation 2: %dx + %dy = %d\n", A, B, c2);

        // STORES THE ANSWERS IN AN ARRAY
        linearAns[0] = x;
        linearAns[1] = y;

        for(j = 0; j < 2; j++){
          if(j == 0){
            printf("\n\t\t   x = ");
            scanf("%d", &pAns[j]);
          } else{
            printf("\t\t   y = ");
            scanf("%d", &pAns[j]);
          }
        }

        if(pAns[0] == linearAns[0] && pAns[1] == linearAns[1]){
            mathCrazePoints++;
        }

        break;

    // MATRIX
    case 9:
        printf("Matrix A:      Matrix B:\n");
        // ADDITION OF MATRIX
        for(j = 0; j < ROW; j++){
            for(k = 0; k < COL; k++){
                d[j][k] = 1 + rand() % 10;
                e[j][k] = 1 + rand() % 10;
                f[j][k] = d[j][k] + e[j][k];
            }
        }

        printf("\t\t   ");
        for(j = 0; j < ROW; j++){
            for(k = 0; k < COL; k++){
                printf("{%d} ", d[j][k]);
            }

            if(j == 0){
                printf("   +   ");
            } else {
                printf("       ");
            }

            for(k = 0; k < 2; k++){
                printf("{%d} ", e[j][k]);
            }
            printf("\n\t\t   ");
        }

        for(j = 0; j < ROW; j++){
          for(k = 0; k < COL; k++){
            printf("\n\t\t   Input answer for row %d column %d: ", j + 1, k + 1);
            scanf("%d", &pA[j][k]);
            if(pA[j][k] == f[j][k]){
                pAns == 0;
            }
          }
        }

        if(pAns == 0){
            mathCrazePoints++;
        }
        break;
    case 10:
        printf("Matrix A:      Matrix B:\n");
        // SUBTRACTION OF MATRIX
        for(j = 0; j < ROW; j++){
            for(k = 0; k < COL; k++){
                d[j][k] = rand() % 10;
                e[j][k] = rand() % 10;
                f[j][k] = d[j][k] - e[j][k];
            }
        }

        printf("\t\t   ");
        for(j = 0; j < ROW; j++){
            for(k = 0; k < COL; k++){
                printf("{%d} ", d[j][k]);
            }

            if(j == 0){
                printf("   -   ");
            } else {
                printf("       ");
            }

            for(k = 0; k < COL; k++){
                printf("{%d} ", e[j][k]);
            }
            printf("\n\t\t   ");
        }

        for(j = 0; j < ROW; j++){
          for(k = 0; k < COL; k++){
            printf("\n\t\t   Input answer for row %d column %d: ", j + 1, k + 1);
            scanf("%d", &pA[j][k]);
            if(pA[j][k] == f[j][k]){
                pAns == 0;
            }
          }
        }

        if(pAns == 0){
            mathCrazePoints++;
        }
        break;
    case 11:
        printf("Matrix A:      Matrix B:\n");
        // MULTIPLICATION OF MATRIX
        for(j = 0; j < ROW; j++){
            for(k = 0; k < COL; k++){
                d[j][k] = rand() % 10;
                e[j][k] = rand() % 10;
                f[j][k] = 0;
            }
        }

        printf("\t\t   ");
        for(j = 0; j < ROW; j++){
            for(k = 0; k < COL; k++){
                printf("{%d} ", d[j][k]);
            }

            if(j == 0){
                printf("   *   ");
            } else {
                printf("       ");
            }

            for(k = 0; k < COL; k++){
                printf("{%d} ", e[j][k]);
            }
            printf("\n\t\t   ");
        }

        for(j = 0; j < ROW; j++){
            for(k = 0; k < COL; k++){
               for(l = 0; l < COL; l++){
                 f[j][k] += d[j][l] * e[l][k];
               }
            }
        }

        for(j = 0; j < ROW; j++){
          for(k = 0; k < COL; k++){
            printf("\n\t\t   Input answer for row %d column %d: ", j + 1, k + 1);
            scanf("%d", &pA[j][k]);
            if(pA[j][k] == f[j][k]){
                pAns == 0;
            }
          }
        }

        if(pAns == 0){
            mathCrazePoints++;
        }
        break;
    case 12:
        printf("Matrix A:\n");
        // DETERMINANTS OF A MATRIX
        for(j = 0; j < ROW; j++){
            for(k = 0; k < COL; k++){
                d[j][k] = rand() % 10;
            }
        }

        printf("\t\t   ");
        for(j = 0; j < ROW; j++){
            for(k = 0; k < COL; k++){
                printf("{%d} ", d[j][k]);
            }

            if(j == 0){
                printf("  a*d - c*b  ");
            }

            printf("\n\t\t   ");
        }

        /*
           A = [0][0]
           B = [0][1]
           C = [1][0]
           D = [1][1]
        */

        prodAD = d[0][0] * d[1][1];
        prodCB = d[1][0] * d[0][1];
        determinant = prodAD - prodCB;

        printf("\n\t\t   D = ");
        scanf("%d", &pAnswer);
        if(pAnswer == determinant){
            mathCrazePoints++;
        }
        break;

    // BASIC MATH
    case 13:
        printf("%d + %d", q2, q3);
        ans = q2 + q3;

        printf("\n\t\t   Answer: ");
        scanf("%d", &pAnswer);
        if(pAnswer == ans){
            mathCrazePoints++;
        }
        break;
    case 14:
        printf("%d - %d", q2, q3);
        ans = q2 - q3;

        printf("\n\t\t   Answer: ");
        scanf("%d", &pAnswer);
        if(pAnswer == ans){
            mathCrazePoints++;
        }
        break;
    case 15:
        printf("%d * %d", q2, q3);
        ans = q2 * q3;

        printf("\n\t\t   Answer: ");
        scanf("%d", &pAnswer);
        if(pAnswer == ans){
            mathCrazePoints++;
        }
        break;
    case 16:
        printf("%.1f / %.1f", (float)q2,(float)q3);
        ans = (float)q2 / (q3);

        printf("\n\t\t   Answer: ");
        scanf("%d", &pAnswer);
        if(pAnswer == ans){
            mathCrazePoints++;
        }
        break;
    case 17:
        printf("%d^%d", q1, q4);
        ans = pow(q1, q4);

        printf("\n\t\t   Answer: ");
        scanf("%d", &pAnswer);
        if(pAnswer == ans){
            mathCrazePoints++;
        }
        break;
    case 18:
        printf("√%d", q1);
        ans = sqrt(q1);

        printf("\n\t\t   Answer: ");
        scanf("%d", &pAnswer);
        if(pAnswer == ans){
            mathCrazePoints++;
        }
        break;

    // TRIGONOMETRY
    case 19:
      printf("Observe the right triangle.\n");
      printf("\t\t   ");
      for(j = 0; j <= 5; j++){
          if(j == 3){
            printf("o ");
          } else {
            printf("  ");
          }

          for(k = 0; k <= j; k++){
              printf("* ");
          }

          if(j == 3){
            printf("  h");
          }

          printf("\n\t\t   ");
      }
      printf("\t a");

      if(q4 == 1){
        printf("\n\t\t   Find the missing side.\n");
        printf("\t\t   ---VALUES---\n");
        if(sides == 0){
            // H missing
            printf("\t\t   o = %d\n", opp);
            printf("\t\t   a = %d\n", adj);
            hypMis = sqrt(pow(opp, 2) + pow(adj, 2));
            printf("\n\t\t   h = ");
            scanf("%d", &pAnswer);
            if(pAnswer == hypMis){
              mathCrazePoints++;
            }
        } else if(sides == 1){
            // A missing
            printf("\t\t   o = %d\n", opp);
            printf("\t\t   h = %d\n", hyp);
            adjMis = sqrt(pow(opp, 2) + pow(hyp, 2));
            printf("\n\t\t   a = ");
            scanf("%d", &pAnswer);
            if(pAnswer == adjMis){
              mathCrazePoints++;
            }
        } else{
            // O MISSING
            printf("\t\t   a = %d\n", adj);
            printf("\t\t   h = %d\n", hyp);
            oppMis = sqrt(pow(adj, 2) + pow(hyp, 2));
            printf("\n\t\t   o = ");
            scanf("%d", &pAnswer);
            if(pAnswer == oppMis){
              mathCrazePoints++;
            }
        }
      } else{
          if(sides == 0){
            // SOH
            printf("\n\t\t   Find sine.\n");
            SOH = (float)opp / hyp;
            printf("\n\t\t   SOH = ");
            scanf("%f", &playerA);
            if(fabs(playerA - SOH) < 0.01){
              mathCrazePoints++;
            }
          } else if(sides == 1){
            printf("\n\t\t   Find cosine.\n");
            CAH = (float)adj / hyp;
            printf("\n\t\t   CAH = ");
            scanf("%f", &playerA);
            if(fabs(playerA - CAH) < 0.01){
              mathCrazePoints++;
            }
          } else{
            printf("\n\t\t   Find tangent.\n");
            TOA = (float)opp / adj;
            printf("\n\t\t   TOA = ");
            scanf("%f", &playerA);
            if(fabs(playerA - TOA) < 0.01){
              mathCrazePoints++;
            }
          }

          printf("\t\t   h = %d\n", hyp);
          printf("\t\t   o = %d\n", opp);
          printf("\t\t   a = %d", adj);
      }
      break;
   }
}

void shuffleQuestions(int *arr, int n){
    int i, j, temp;

    for(i = n - 1; i > 0; i--){
        j = rand() % i + 1;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

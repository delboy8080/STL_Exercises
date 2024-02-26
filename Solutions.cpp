#include "Solutions.h"

//
// Created by floodd on 21/02/2024.
//
void print(const vector<int> &vec, string s= "") {
   cout << s <<"[";
    for (int i = 0; i < vec.size(); i++)
    {
        if(i!=0)
            cout << ", ";
        cout << vec[i];
    }
    cout << "]\n";
}

void print(const list<int> &lst, string s= "") {
    cout << s <<"[";
    for (auto it = lst.cbegin(); it != lst.cend(); it++)
    {
        if(it!=lst.cbegin())
            cout << ", ";
        cout << *it;
    }
    cout << "]\n";
}

void print(const vector<string> &vec, string s= "") {
    cout << s <<"[";
    for (int i = 0; i < vec.size(); i++)
    {
        if(i!=0)
            cout << ", ";
        cout << vec[i];
    }
    cout << "]\n";
}

void print(const list<string> &lst, string s= "") {
    cout << s <<"[";
    for (auto it = lst.cbegin(); it != lst.cend(); it++)
    {
        if(it!=lst.cbegin())
            cout << ", ";
        cout << *it;
    }
    cout << "]\n";
}
/*
    Question 1.

    Write an application that will read in a number of integers from a file and store them in
    a vector. Allow the user to search through the vector and find the position of any userdefined number.

 */
void question1()
{

    ifstream fin("nums.txt");
    if(fin)
    {
        vector<int> nums;
        while(!fin.eof())
        {
            int num;
            fin >> num;
            nums.push_back(num);
        }
        fin.close();
        int key, pos=-1;
        cout << "Please enter number to find." << endl;
        cin >> key;
        for(int i = 0; i < nums.size();i++)
        {
            if(nums[i] == key)
            {
                pos = i;
                break;
            }
        }
        if(pos == -1)
            cout << key << " not found in the vector." <<endl;
        else
            cout << key << " found in the vector at position " << pos << "." <<endl;
    }
}
void question2()
{
    ifstream fin("nums.txt");
    if(fin)
    {
        list<int> nums;
        while(!fin.eof())
        {
            int num;
            fin >> num;
            nums.push_back(num);
        }
        fin.close();
        int key, pos=-1;
        cout << "Please enter number to find." << endl;
        cin >> key;
        int i = 0;
        for(auto it = nums.cbegin(); it != nums.cend(); it++)
        {
            if(*it == key)
            {
                pos = i;
                break;
            }
            i++;
        }
        if(pos == -1)
            cout << key << " not found in the vector." <<endl;
        else
            cout << key << " found in the vector at position " << pos << "." <<endl;
    }
}
void question3()
{
    ifstream fin("nums.txt");
    if(fin)
    {
        vector<int> nums;
        while(!fin.eof())
        {
            int num;
            fin >> num;
            nums.push_back(num);
        }
        fin.close();
        sort(nums.begin(), nums.end());

        print(nums, "After sorting inputted numbers. ");
        int key, pos=-1;
        cout << "Please enter number to find." << endl;
        cin >> key;
        for(int i = 0; i < nums.size();i++)
        {
            if(nums[i] == key)
            {
                pos = i;
                break;
            }
        }
        if(pos == -1)
            cout << key << " not found in the vector." <<endl;
        else
            cout << key << " found in the vector at position " << pos << "." <<endl;
    }
}

/*
 Question 4.
 Investigate the sort() function, used to sort vector (or list) contents, and see if you can
write the code to sort a vector of strings by the length of the strings. Write the code to
sort the strings in ascending order, by length. (Hint: See sort() documentation and write
a compare function).

 */
void question4()
{
    vector<string> words {"this", "is", "a", "random", "collection", "of", "words"};
    print(words, "Original list of words");
    sort(words.begin(), words.end(), [](string s1, string s2){ return s1.length() < s2.length();});
    print(words, "List of words after sorting");
}

/*
 Question 5.
    Modify the above exercise (question 3) to place the numbers in descending order. Use the STL
    function sort.

 */


void question5()
{
    ifstream fin("nums.txt");
    if(fin)
    {
        vector<int> nums;
        while(!fin.eof())
        {
            int num;
            fin >> num;
            nums.push_back(num);
        }
        fin.close();
        sort(nums.begin(), nums.end(), [](int x, int y){return x > y;});

        print(nums, "After sorting inputted numbers. ");
        int key, pos=-1;
        cout << "Please enter number to find." << endl;
        cin >> key;
        for(int i = 0; i < nums.size();i++)
        {
            if(nums[i] == key)
            {
                pos = i;
                break;
            }
        }
        if(pos == -1)
            cout << key << " not found in the vector." <<endl;
        else
            cout << key << " found in the vector at position " << pos << "." <<endl;
    }
}

/*
    Question 6.

    Create a function, print(), that takes a vector of integers and a prompt string and prints
    out the prompt (e.g. “***** My Numbers *****”) and the contents of the vector. Use
    your knowledge of const and the pass-by-reference modifier to improve the code. What
    would you need to add or change to print a vector of strings? (Hint: method
    overloading).
 */
void question6()
{
    vector<string> words {"this", "is", "a", "random", "collection", "of", "words"};
    print(words, "Original list of words");
    vector<int> nums {1,2,3,4,5,6,7,8,9,10,1,2,15,19};
    print(nums, "A list of numbers");
}

/*
    Question 7.

    Create a vector of strings, called monthVector, and add the following contents: Jan,
    Apr, May, Sept, Nov, Dec Now, using the vector Iterator and the insert() method, add
    the missing months in the least number of iterator moves possible. Use the print
    function to view the contents of the vector.

 */

void question7()
{
    vector<string> monthVector {"Jan", "Apr", "May", "Sept", "Nov", "Dec"};
    vector<string>::iterator it = monthVector.begin();
    it++;
    it = monthVector.insert(it, "Mar");
    it = monthVector.insert(it, "Feb");
    it+=4;
    it = monthVector.insert(it, "Aug");
    it = monthVector.insert(it, "Jul");
    it = monthVector.insert(it, "Jun");
    it+=4;
    it = monthVector.insert(it, "Oct");

    print(monthVector, "Final vector of months");


}

/*
    Question 8.
    Create a function, areSameUntil(), that takes two vectors of integers and returns the
position that the vector contents cease to be identical. You should decide what value
the function will return to indicate success and failure.
 */

int areSameUntil(const vector<int> &vec1, const vector<int> &vec2)
{
    int min = vec1.size() < vec2.size()?vec1.size():vec2.size();
    for(int i = 0; i < min; i++)
    {
        if(vec1[i] != vec2[i])
            return i-1;
    }
    return min-1;
}
void question8()
{
    vector<int> vec1 {1,2,3};
    vector<int> vec2 {1,2,4};
    vector<int> vec3 {4,5,6};
    vector<int> vec4 {1,2,3,4,5};
    print(vec1);
    cout << "and" << endl;
    print(vec2);
    cout << "Are same until element " << areSameUntil(vec1, vec2) <<endl;

    print(vec1);
    cout << "and" << endl;
    print(vec3);
    cout << "Are same until element " << areSameUntil(vec1, vec3) <<endl;
    print(vec1);
    cout << "and" << endl;
    print(vec4);
    cout << "Are same until element " << areSameUntil(vec1, vec4) <<endl;

    print(vec1);
    cout << "and" << endl;
    print(vec1);
    cout << "Are same until element " << areSameUntil(vec1, vec1) <<endl;


}

/*

    Question 9.
    Create a function, areSameReverse(), that takes two vectors of integers and returns true
    if the vector contents are identical but in reverse (e.g. {1,2,3} and {3,2,1}), otherwise
    false
 */
bool areSameReverse(const vector<int> &vec1, const vector<int> &vec2) {
    auto it1 = vec1.cbegin();
    auto itR = vec2.crbegin();
    while (it1 != vec1.cend() && itR != vec2.crend())
    {
        if(*it1 != *itR)
            return false;
        it1++;
        itR++;
    }
    return it1 == vec1.cend() && itR == vec2.crend();
}
void question9()
{
    vector<int> vec1 {1,2,3};
    vector<int> vec2 {3,2,1};
    vector<int> vec3 {4,5,6};
    print(vec1);
    cout << "and" << endl;
    print(vec2);
    cout << "Are same in reverse " << (areSameReverse(vec1, vec2)?"True":"False")  <<endl;
    print(vec1);
    cout << "and" << endl;
    print(vec3);
    cout << "Are same in reverse " << (areSameReverse(vec1, vec3)?"True":"False") <<endl;
}
/*
  Question 10.
  Create a function, interleave(), that takes three vectors of integers. The function will
  interleave the values from the first two vectors and place the output into the third vector.
  What assumption(s) must you make to implement your solution? Note: This function
  does not return the third interleaved vector.
 */
void interleave(const vector<int> &vec1, const vector<int> &vec2, vector<int> &ret)
{
    auto it1 = vec1.cbegin();
    auto it2 = vec2.cbegin();
    while(it1 != vec1.cend() ||it2 != vec2.cend())
    {
        if(it1 != vec1.cend())
        {
            ret.push_back(*it1);
            it1++;
        }
        if(it2 != vec1.cend())
        {
            ret.push_back(*it2);
            it2++;
        }
    }
}
void question10()
{
    vector<int> vec1 {1,2,3};
    vector<int> vec2 {3,2,1};
    vector<int> vec3 {1,2,3,4,5};
    vector<int> vec4;
    print(vec1);
    cout << "and" << endl;
    print(vec2);
    interleave(vec1, vec2, vec4);
    print(vec4, "interleaved: ");

    vec4.clear();
    print(vec1);
    cout << "and" << endl;
    print(vec3);
    interleave(vec1, vec3, vec4);
    print(vec4, "interleaved: ");
}

struct card
{
    string face;
    string suit;
};

void generateDeck(vector<card> &deck)
{
    string face[13] {"A","2","3","4","5","6","7","8","9","10", "J", "Q", "K"};
    string suit[4] {"H", "S", "C", "D"};

    for(string s: suit)
    {
        for(string f: face)
        {
            card c ;
            c.face = f;
            c.suit =s ;
            deck.push_back(c);
        }
    }
}
void question11()
{
    srand(time_t(NULL));
    vector<card> deck;
    generateDeck(deck);
    random_shuffle(deck.begin(), deck.end());
    int choice = 0;
    do {
        random_shuffle(deck.begin(), deck.end()); // shuffle the deck at the start of each round
        cout << "1. Guess FACE value only"<<endl;
        cout << "2. Guess SUIT only"<<endl;
        cout << "3. Guess Both" <<endl;
        cout <<"-1 to end" << endl;
        cin >> choice;
        string face;
        string suit;
        card choosenCard = deck.at(0);
        //cout << choosenCard.face  <<" of " << choosenCard.suit <<endl; // for testing purposes.

        if(choice==1)
        {
            cout << "Face: " <<endl;
            cin >> face;
            if(face == choosenCard.face)
            {
                cout << "You won this round" <<endl;
            }
            else
            {
                cout << "You lost this round. THe choosen card was: ";
                cout << choosenCard.face  <<" of " << choosenCard.suit <<endl;
            }
        }
        else if(choice == 2)
        {
            cout << "Suit: " <<endl;
            cin >> suit;
            if(suit == choosenCard.suit)
            {
                cout << "You won this round" <<endl;
            }
            else
            {
                cout << "You lost this round. THe choosen card was: ";
                cout << choosenCard.face  <<" of " << choosenCard.suit <<endl;
            }
        }
        else if(choice == 3)
        {
            cout << "Face: " <<endl;
            cin >> face;
            cout << "Suit: " <<endl;
            cin >> suit;
            if(face == choosenCard.face && suit == choosenCard.suit)
            {
                cout << "You won this round" <<endl;
            }
            else
            {
                cout << "You lost this round. THe choosen card was: ";
                cout << choosenCard.face  <<" of " << choosenCard.suit <<endl;
            }
        }

    }while(choice!=-1);
}

int calculateTotal(const vector<card> & hand)
{
    int score = 0;
    int aces = 0;
    for(card c: hand)
    {
        if(c.face == "A")
        {
            score+=11;
            aces++;
        }
        else if(c.face == "10"||c.face == "J"||c.face == "Q"||c.face == "K")
        {
            score += 10;
        }
        else
        {
            score += c.face[0] - '0';
        }
    }
    while(score > 21 && aces >0)
    {
        score -=10;
        aces--;
    }
    return score;
}
void displayHand(const vector<card> &hand)
{
    for(card c: hand)
    {
        cout << c.face << " of " << c.suit <<endl;
    }
    cout << "Total Score: " << calculateTotal(hand)<<endl;
}

void dealCard(vector<card> &hand, vector<card> &deck)
{
    hand.push_back(deck[0]);
    deck.erase(deck.begin());
}
void question12()
{
    srand(time(NULL));
    vector<card> deck;
    generateDeck(deck);
    random_shuffle(deck.begin(), deck.end());
    vector<card> dealer;
    vector<card> player;
    int playAgain=1;
    do {
        dealCard(player, deck);
        dealCard(player, deck);
        dealCard(dealer, deck);
        dealCard(dealer, deck);

        int hit;
        do {
            cout << "Players Hand:" <<endl;
            displayHand(player);
            cout << "1. hit or 2. Stick" << endl;
            cin >> hit;
            if(hit == 1)
            {
                dealCard(player, deck);
            }
        }while(hit == 1);
        while(calculateTotal(dealer) < 16)
        {
            dealCard(dealer, deck);
        }
        cout << "Final Player HAnd" <<endl;
        displayHand(player);
        cout << "Final Dealer Hand" <<endl;
        displayHand(dealer);

        int dealerTotal = calculateTotal(dealer);
        int playerTotal = calculateTotal(player);
        if(playerTotal > 21)
        {
            cout << "You bust"<<endl;
        }
        else if(dealerTotal > 21)
        {
            cout << "You won."<<endl;
        }
        else if(playerTotal > dealerTotal)
        {
            cout << "you Won" <<endl;
        }
        else
        {
            cout << "You Lost" <<endl;
        }

        // if less than 10 cards left in the deck regenerate and shuffle deck
        if(deck.size() < 10)
        {
            deck.clear();
            generateDeck(deck);
            random_shuffle(deck.begin(), deck.end());
        }
        cout << "Play again?\n 1. Yes \n2.No" <<endl;
        cin >> playAgain;
        player.clear();
        dealer.clear();
    }while(playAgain == 1);
}
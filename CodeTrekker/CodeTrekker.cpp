#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map> 
#include <windows.h> 
#include <regex>  
#include "user.h"
#include "problem.h";
#include "valid.h"
#include "Register.h"
#include "login.h"
#include "InitialData.h"
#include "showAndSearch.h"
#include "creationteam.h"
using namespace std;
void choice2(map<string, bool>& found_handle, map<string, bool>& found_email, map<string, bool>& found_problem,
    map<string, user>& users, map<string, problem>& problems, bool& logged_in, bool& exit, user& profile)
{
    bool stg = 1;
    while (stg)
    {
        cout << "1. Reset name\n2. Reset country\n3. Reset university\n";
        cout << "4. Reset password\n5. Reset visibility of email\n6. Go to my profile\n7. Logout\n8. Exit\n";
        cout << "your choice: "; int c; cin >> c; bool f = 0;
        string handle = profile.get_handle(), name , university;
        string h = handle;
        for (ll i = 0; i < h.size(); i++)h[i] = tolower(h[i]);
        switch (c && logged_in && !exit)
        {
        case 1:
            cout << "Enter the new name: ";
             cin >> name;
            users[h].set_name(name);
            profile = users[h];
            cout << "Name updated\n";
            break;
        case 2: 
            users[h].update_country();
            profile = users[h];
            cout << "country updated\n";
            break;
        case 3:
            cout << "Enter the university: ";
             cin >> university;
            users[h].update_university(university);
            profile = users[h];
            cout << "university updated\n";
            break;
        case 4:
            profile.reset_password();
            break;
        case 5:
            cout << "ON: 1, OFF:0, choose: ";
             cin >> f; 
            users[h].set_visible(f);
            profile.set_visible(f);
            cout << "Done\n";
            break;
        case 6:
            stg = 0;
            break;
        case 7:
            logged_in = 0;
            break;
        case 8:
            exit = 1;
            break;
        }
    }



}
void choice(map<string, bool>&found_handle, map<string, bool>&found_email, map<string, bool>& found_problem,
    map<string, user>&users,map<string, problem>&problems,bool& logged_in , bool& exit, user& profile)
{
    bool here = 1;
    while (here && logged_in && !exit)
    {
        cout << "\n1. Show my submissions\n2. Show my teams\n3. Show my friends\n4. Show my favourites\n";
        cout << "5. Submit a problem\n6. Creat team\n7. Settings\n8. Return to main page\n9. Logout\n10. Exit";
        cout << "Your choice: "; int c; cin >> c;
        switch (c)
        {
        case 1:
            profile.show_submissions();
            break;
        case 2:
            profile.show_teams();
            break;
        case 3:
            profile.show_friends();
            break;
        case 4:
            profile.show_favourites();
            break;
        case 5:
            search_for_user(found_handle, users, logged_in, profile);
            break;
        case 6:
            create_team(found_handle, found_email, users, logged_in, profile);
            break;
        case 7:
            choice2(found_handle, found_email, found_problem, users, problems, logged_in, exit, profile);
            break;
        case 8: 
            here = 0;
            break;
        case 9:
            logged_in = 0;
            break;
        case 10:
            exit = 1;
            break;
        }
    }
}
int main()
{
    map<string, bool>found_handle, found_email, found_problem;
    map<string, user>users;   
    map<string, problem>problems;
    bool logged_in = 0, exit = 0; user profile;
    init(found_handle, found_email, users, problems);
    cout << "\t\t\t\t\t\WELCOME TO CODETREKKER\n";
    while (!exit)
    {
        if (!logged_in)
        {
            cout << "Enter the number of the operation you want to do:\n";
            cout << "1. Register \n2. Login\n3. Show problemset\n4. Search for a handle\n";
            cout << "5. Show all users\n6. Show rating\n7. Exit\n";
            cout << "your choice: "; int c; cin >> c;
            switch (c)
            {
            case 1:
                registeration(found_handle, found_email, users, logged_in, profile);
                break;
            case 2:
                login(found_handle, found_email, users, logged_in, profile);
                break;
            case 3:
                show_problems(problems);
                break;
            case 4:
                search_for_user(found_handle, users, logged_in, profile);
                break;
            case 5:
                show_users(users);
                break;
            case 6:
                user::show_users_by_ranks();
                break;
            case 7:
                exit = 1;
                break;
            }
        }
        else
        {
            cout << "Enter the number of the operation you want to do:\n";
            cout << "1. Go to my profile \n2. Return to main page \n3. Show problemset\n4. Search for a handle\n";
            cout << "5. Show all users\n6. Show rating\n\n7. Logout\n8. Exit\n";
            cout << "your choice: "; int c; cin >> c; 
            switch (c)
            {
            case 1:
                choice(found_handle, found_email, found_problem,users,problems,  logged_in, exit,  profile);
                break;
            case 2:
                break;
            case 3:
                show_problems(problems);
                break;
            case 4:
                search_for_user(found_handle, users, logged_in, profile);
                break;
            case 5:
                show_users(users);
                break;
            case 6:
                user::show_users_by_ranks();
                break;
            case 7:
                logged_in = 0;
                break;
            case 8:
                exit = 1;
                break;
            }
        }


    }
    // test

    /*show_users(users);
    problem p("watermelwon", "div1", "add two numbers;", "shahd", "add them;", "time 2s;space 2 MG", { "dp", "greedy" },
       { "input;1 2;output;3" }, 800, 1, "1A");
    problem p1("ksnfi", "div1", "add two numbers;", "shahd", "add them;", "time 2s;space 2 MG", { "dp", "greedy" },
        { "input;1 2;output;3" }, 800, 2, "1A");
    user u; u.submit({ p, "acc", "gnu", "sat1:20", 125, 1564, 1615 });
    u.show_submissions();
    p.show_problem();
    p.showFromEasyToHard();
    p.showFromHardToEasy();*/
    //search_for_user(found_handle, users);
    //for (auto m : users) { m.second.show_user(); }
    //registeration(found_handle, found_email, users, logged_in, profile); 
    //login(found_handle, found_email, users, logged_in, profile);


}
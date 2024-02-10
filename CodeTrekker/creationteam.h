#pragma once
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>  
#include "valid.h"
#include <regex> 
using namespace std;
void create_team(map<string, bool>& found_handle, map<string, bool>& found_email, map<string, user>& users, bool& logged_in, user& profile)
{
    cout << "Create Team\n";
    string team_name;
    cout << "Enter the name of the team: ";
    cin >> team_name;
    cout << "Enter the number of team members\n";
    int n;
    cin >> n; bool  f = 1;
    vector<user>team_members;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the handle of member " << i + 1 << " : ";
        string handle, h;
        while (1)
        {
            cin >> handle;  h = handle; for (ll i = 0; i < h.size(); i++)h[i] = tolower(h[i]);
            if (found_handle[h])break;
            if (found_handle[h])break;
            cout << "Invalid handle\n";
            cout << "Do you want to return to home page? (1:yes, 0:no): ";
            cin >> f; if (!f)break;
            else cout << "ok, try again: ";
        }
        if (!f)break;
        team_members.push_back(users[h]);
    }
    if (!f)return;
    profile.add_team({ team_name, team_members });
    cout <<  "Done\n";
}
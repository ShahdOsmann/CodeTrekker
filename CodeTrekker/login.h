#pragma once
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>  
#include "valid.h"
#include <regex> 
using namespace std;
void login(map<string, bool>& found_handle, map<string, bool>& found_email, map<string, user>& users, bool& logged_in, user& profile)
{
    cout << "Enter handle: ";
    string handle, h; bool f = 1;
    while (1)
    {
        cin >> handle;  h = handle; for (ll i = 0; i < h.size(); i++)h[i] = tolower(h[i]);
        if (found_handle[h])break;
        cout << "Handle not found\n";
        cout << "Do you want to return to home page? (1:yes, 0:no): ";
        cin >> f; if (!f)break;
        else cout << "ok, try again: ";
    }
    if (!f)return;
    cout << "Enter password: ";
    string password;
    while (1)
    {
        cin >> password;
        if (users[h].get_password() == password)break;
        cout << "Password isnot correct\n";
        cout << "Do you want to return to home page? (1:yes, 0:no): ";
        cin >> f; if (!f)break;
        else cout << "ok, try again: ";
    }
    if (f) {
        logged_in = 1, profile = users[h];
        profile.show_user();
        cout << "Welcome, " << handle << "\n";
    }
}
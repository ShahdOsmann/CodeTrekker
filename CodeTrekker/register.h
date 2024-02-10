#pragma once
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>  
#include "valid.h"
#include <regex> 
using namespace std;
void registeration(map<string, bool>& found_handle, map<string, bool>& found_email, map<string, user>& users, bool& logged_in, user& profile)
{
    cout << "Register in Codeforces\n";
    cout << "Enter handle: "; bool f = 1;
    string handle, h;
    while (1) {
        cin >> handle;  h = handle; for (ll i = 0; i < h.size(); i++)h[i] = tolower(h[i]);
        if (validate_handle(handle) && !found_handle[h])break;
        else if (!validate_handle(handle))cout << "THis handle isnot valid , handle sould contain only [a-z]or [A-Z]or[0-9]or[., -, _]\n";
        else  cout << "This handle is already exist\n "; 
        cout << "Do you want to return to home page? (1:yes, 0:no): ";
       cin >> f; if (!f)break;
        else cout << "ok, try again: "; 
    }
    if (!f)return;
    cout << "Enter Email: ";
    string email;
    while (1)
    {
        cin >> email;
        if (validate_email(email) && !found_email[email])break;
        else if (!validate_email(email))cout << "This is not a correct email\n";
        else cout << "This email is already registered\n";
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
        if (validate_password(password))break;
        else cout << "This is a weak a password\n";
        cout << "Do you want to return to home page? (1:yes, 0:no): ";
        cin >> f; if (!f)break;
        else cout << "ok, try again: ";
    }
    if (!f)return;
    users[h] = user(handle, email, password);
    found_handle[h] = 1, found_email[email] = 1;
    users[h].show_user();
    logged_in = 1, profile = users[h];
    cout << "Account created successfully\n";
}
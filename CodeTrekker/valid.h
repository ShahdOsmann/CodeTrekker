#pragma once

#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include <regex>
#include "user.h" 
#define ll long long
using namespace std;
bool validate_email(const std::string& email);
bool validate_password(const std::string& password);
bool validate_handle(std::string handle);
bool validate_Country(std::string country);

extern std::map<std::string, bool> countryNames;
